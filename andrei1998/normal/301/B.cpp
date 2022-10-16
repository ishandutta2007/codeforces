#include <iostream>
#include <cmath>
#include <queue>
#include <bitset>

#define inf 4100000000000ll
using namespace std;

struct punct
{
    int x,y;

    punct(int a=0,int b=0): x(a),y(b) {}
}v[105];

int a[105];
long long int di[105];
bitset<105> viz;

int n,d;
long long int dist(punct a,punct b)
{
    return (1ll*d*(abs(a.x-b.x)+abs(a.y-b.y)));
}

queue<int> coada; //Nodurile din BF
inline bool ok(long long int incep)
{
    for(int i=2;i<=n;i++)
        di[i]=-1;
    di[1]=incep;

    viz[1]=1;
    coada.push(1);

    while(!coada.empty()){
        int y=coada.front();

        coada.pop();
        viz[y]=0;

        for(int i=1;i<=n;i++)
            if(i!=y)
                if(di[y]>=dist(v[y],v[i])){
                    long long int aux=(a[i]+di[y]-dist(v[y],v[i]));

                    if(aux>di[i]){
                        di[i]=aux;

                        if(!viz[i]){
                            viz[i]=1;
                            coada.push(i);
                        }
                    }
                }
    }

    return (di[n]>=0);
}

int main()
{
    cin>>n>>d;

    a[1]=a[n]=0;
    for(int i=2;i<n;i++)
        cin>>a[i];

    for(int i=1;i<=n;i++)
        cin>>v[i].x>>v[i].y;

    long long int st=1;
    long long int dr=inf;
    long long int mijl=(st+dr)>>1;
    long long int rasp=inf+1;

    while(st<=dr){
        if(ok(mijl)){
            rasp=mijl;
            dr=mijl-1;
        }
        else
            st=mijl+1;

        mijl=(st+dr)>>1;
    }

    cout<<rasp<<'\n';

    return 0;
}