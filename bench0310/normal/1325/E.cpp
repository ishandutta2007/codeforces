#include <bits/stdc++.h>

using namespace std;

const int N=1000005;
vector<int> v[N];
vector<int> dist(N,0);
vector<int> primes;
const int inf=(1<<30);

void out(int a)
{
    printf("%d\n",a);
    exit(0);
}

int solve(int src)
{
    int res=inf;
    queue<pair<int,int>> q;
    q.push({src,src});
    dist[1]=-1;
    for(int p:primes) dist[p]=-1;
    dist[src]=0;
    while(!q.empty())
    {
        auto [from,a]=q.front();
        q.pop();
        for(int to:v[a])
        {
            if(to==from) continue;
            if(dist[to]!=-1)
            {
                res=min(res,dist[a]+dist[to]+1);
                continue;
            }
            dist[to]=dist[a]+1;
            q.push({a,to});
        }
    }
    return res;
}

int main()
{
    vector<int> p(N);
    for(int i=0;i<N;i++) p[i]=i;
    for(long long o=2;o<N;o++)
    {
        if(p[o]!=o) continue;
        primes.push_back(o);
        for(long long i=o*o;i<N;i+=o) if(o<p[i]) p[i]=o;
    }
    int n;
    scanf("%d",&n);
    map<array<int,2>,int> m;
    for(int i=0;i<n;i++)
    {
        int a;
        scanf("%d",&a);
        vector<array<int,2>> t;
        while(a>1)
        {
            if(!t.empty()&&p[a]==t.back()[0]) t.back()[1]++;
            else t.push_back({p[a],1});
            a/=p[a];
        }
        vector<int> x;
        for(auto b:t) if(b[1]&1) x.push_back(b[0]);
        if(x.size()==0) out(1);
        else if(x.size()==1) m[{1,x[0]}]++;
        else if(x.size()==2) m[{x[0],x[1]}]++;
    }
    for(auto x:m) if(x.second>1) out(2);
    for(auto [x,t]:m)
    {
        v[x[0]].push_back(x[1]);
        v[x[1]].push_back(x[0]);
    }
    int res=inf;
    for(int i=1;i<=1000;i++) if(p[i]==i) res=min(res,solve(i));
    if(res==inf) res=-1;
    out(res);
    return 0;
}