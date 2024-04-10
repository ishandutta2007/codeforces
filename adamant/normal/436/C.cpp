#include <bits/stdc++.h>

using namespace std;

#define all(c) begin(c),end(c)
#define p(i,j) pair<i,j>
#define v(i) vector<i>


/* input */
 template<typename T>istream& operator >> ( std::istream& in,v(T)&a){for(auto &it:a)in>>it;return in;}
 template<typename T1,typename T2>istream& operator >>( std::istream& in,p(T1,T2)&a){in>>a.first>>a.second;return in;}

/* output */
 template<typename T>ostream& operator << ( std::ostream& out,v(T)&a){for(auto it:a){out<<' '<<it;}out<<endl;return out;}
 template<typename T1,typename T2>ostream& operator <<( std::ostream& out,p(T1,T2)&a){out<<a.first<<' '<<a.second;return out;}

#define int long long

const int INF=1e9;

#define TASK "test"

struct DSU
{
    static const int N=1000;
    int parent[N];
    int sz[N];
    DSU(){for(int i=0;i<N;i++)parent[i]=i,sz[i]=1;}
    int find(int x)
    {
        if(x==parent[x]) return x;
        return parent[x]=find(parent[x]);
    }
    void uni(int a,int b)
    {
        a=find(a);
        b=find(b);
        if(sz[a]>sz[b]) swap(a,b);
        parent[a]=b;
        sz[b]+=sz[a];
    }
} me;

v(v(p(int,int))) G;
v(int) used;
int n,m;

void dfs(int x)
{
    used[x]=1;
    for(int i=0;i<G[x].size();i++)
        if(!used[G[x][i].first])
        {
            cout<<G[x][i].first+1<<' '<<(G[x][i].second==n*m?0:x+1)<<"\n";
            dfs(G[x][i].first);
        }
}

main()
{
    //freopen(TASK".in","r",stdin);
    //freopen(TASK".out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int k,w;
    cin>>n>>m>>k>>w;
    v(v(string)) x(k,v(string)(n));
    cin>>x;

    v(p(int,p(int,int))) e;
    for(int i=1;i<k;i++)
        for(int j=0;j<i;j++)
        {
            int cur=0;
            for(int I=0;I<n;I++)
                for(int J=0;J<m;J++)
                    cur+=x[i][I][J]!=x[j][I][J];
            e.push_back({w*cur,{i,j}});
        }
    sort(all(e));

    int add=0;
    int i=0;
    G.resize(k);
    int sum=n*m;
    while(add<k-1)
    {
        int a=e[i].second.first,b=e[i].second.second,c=e[i].first;
        c=min(c,n*m);
        i++;
        if(me.find(a)==me.find(b)) continue;
        me.uni(a,b);
        sum+=c;
        G[a].push_back({b,c});
        G[b].push_back({a,c});
        add++;
    }
    cout<<sum<<endl;
    cout<<1<<' '<<0<<"\n";
    used.assign(k,0);
    dfs(0);
}