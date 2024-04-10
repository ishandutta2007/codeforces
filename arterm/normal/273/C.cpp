#include <iostream>
#include <vector>
#include <set>

#define M 300300
#define f first
#define s second
#define mp make_pair

using namespace std;

long n,m,t[M];
bool u[M];
vector<long> g[M];
set<long> s;

void read(void){
    cin>>n>>m;
    for (long i=0,a,b; i<m; ++i){
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (long i=1; i<=n; ++i){
        t[i]=g[i].size();
        //q.push()
        if (t[i]>=2)
        s.insert(i);
    }
}

void chan(long x){
    t[x]=3-t[x];

    s.erase(x);

    for (long i=0; i<g[x].size(); ++i){
        long  y=g[x][i];
        if (u[x]^u[y])
        t[y]++;
        else
        t[y]--;

        if (t[y]>=2)
        s.insert(y);
        if (t[y]<2)
        s.erase(y);
    }

    u[x]=!u[x];
}

void kill(void){
    while (!s.empty()){
        long a=*s.begin();
        chan(a);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    read();
    kill();
    for (long i=1; i<=n; ++i)
    cout<<u[i];
    return 0;
}