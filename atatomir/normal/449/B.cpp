#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <cstdio>

using namespace std;

class Buffer{
    public:
        long maxBuf,pos;
        vector<char> Buff;

        Buffer(char fileName[],long buffSize){
            //freopen(fileName,"r",stdin);
            maxBuf = buffSize; Buff.resize(maxBuf);
            reFill();
        }

        Buffer& operator>>(long &dest){
            while(!isDigit(Buff[pos])){
                pos++;
                if(pos == maxBuf) reFill();
            }
            dest = 0;
            while(isDigit(Buff[pos])){
                dest = dest*10 + Buff[pos++] - '0';
                if(pos == maxBuf) reFill();
            }
            return *this;
        }
        Buffer& operator>>(long long &dest){
            while(!isDigit(Buff[pos])){
                pos++;
                if(pos == maxBuf) reFill();
            }
            dest = 0;
            while(isDigit(Buff[pos])){
                dest = dest*10 + Buff[pos++] - '0';
                if(pos == maxBuf) reFill();
            }
            return *this;
        }

    private:
        bool isDigit(char c){
            return c >= '0' & c <= '9';
        }
        void reFill(){
            fread(&Buff[0],1,maxBuf,stdin); pos = 0;
        }
};

#define maxN 100111
#define INF (1LL<<60)

struct Edge{
    long dir;
    long long cost;
};
Edge mp(long ddir,long long ccost){
    Edge tmp;
    tmp.dir = ddir; tmp.cost = ccost;
    return tmp;
}

long n,m,k,i,cnt,x,y;
long long pay;
vector<Edge> list[maxN];
long long how[maxN];
bool train[maxN];

queue<long> Q;
bool inQueue[maxN];
bool Used[maxN];

/*
#define cin fin
ifstream cin("test.in");
*/

void addQueue(long node){
    if(inQueue[node]) return;
    inQueue[node] = true;
    Q.push(node);
    Used[node] = true;
}

int main()
{
    Buffer cin("test.in",1024*1024);
    cin >> n >> m >> k;

    for(i=1;i<=n;i++) how[i] = INF;

    for(i=1;i<=m;i++){
        cin >> x >> y >> pay;
        list[x].push_back(mp(y,pay));
        list[y].push_back(mp(x,pay));
    }
    for(i=1;i<=k;i++){
        cin >> y >> pay;
        if(how[y]>pay){
            if(train[y]) cnt++;
            how[y]= pay; train[y] = true;
        } else cnt++;
    }

    if(train[1])cnt++;

    how[1] = 0; addQueue(1); train[1]=false;
    while(!Q.empty()){
        long node = Q.front(); Q.pop(); inQueue[node] = false;
        for(i=0;i<list[node].size();i++){
            long newNode = list[node][i].dir;
            long long newCost = list[node][i].cost + how[node];

            if(newCost<=how[newNode]){
                if(train[newNode]){
                    cnt++;
                    train[newNode] = false;
                }
                if(newCost!=how[newNode])addQueue(newNode);
                how[newNode] = newCost;
            }
            if(!Used[newNode]) addQueue(newNode);
        }
    }

    cout << cnt ;

    return 0;
}