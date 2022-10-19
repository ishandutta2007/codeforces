#include <iostream>
#include <vector>
#include <queue>

#define f first
#define s second
#define mp make_pair
#define M 200200
#define long long long

using namespace std;

long n,m,s[M];
vector<long> v[M],num[M],c[M];
bool u[2*M];
long d[2*M];
queue<long> q;


void read(void){
    cin>>n>>m;
    for (long x,y,z,i=0; i<m; ++i){
        cin>>x>>y>>z;
        v[x].push_back(y);
        v[y].push_back(x);
        c[x].push_back(z);
        c[y].push_back(z);
        num[x].push_back(2*i);
        num[y].push_back(2*i+1);
        s[x]+=z;
        s[y]+=z;
    }

    for (long i=1; i<n; ++i)
    s[i]/=2;

    s[1]=0;

}

void relax(long x){
    for (long i=0; i<v[x].size(); ++i)
    if (!u[num[x][i]]){
        u[num[x][i]]=1;
        u[num[x][i]^1]=1;

        d[num[x][i]]=0;
        d[num[x][i]^1]=1;

        s[v[x][i]]-=c[x][i];

        if (s[v[x][i]]==0)
        q.push(v[x][i]);
    }
}

void kill(void){
    q.push(1);
    for (long i=0; i<n; ++i){
        relax(q.front());
        q.pop();
    }
}

int main()
{
    ios_base::sync_with_stdio();
    read();
    kill();
    for (long i=0; i<m; ++i)
    cout<<d[2*i]<<"\n";
    return 0;
}