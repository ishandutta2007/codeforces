#include<bits/stdc++.h>
using namespace std ;

#define ll long long 
#define pb push_back
#define mem0(a) memset(a,0,sizeof(a))
#define mem1(a) memset(a,-1,sizeof(a))
#define memf(a) memset(a,false,sizeof(a))
#define all(v) v.begin(),v.end()
#define sz(a) (ll)a.size()
#define F first
#define S second
#define INF 2000000000000000000
#define endl "\n"
#define _time_ 1.0 * clock() / CLOCKS_PER_SEC
#define popcount(x) __builtin_popcountll(x)
#define pll pair<ll,ll> 
#define ld long double

const int M=1000000007;
const int MM=998244353;
const long double PI = acos(-1);

ll power(ll b,ll e,ll m)
{
    if(e==0) return 1;
    if(e&1) return b*power(b*b%m,e/2,m)%m;
    return power(b*b%m,e/2,m);
}
ll power( ll b, ll e)
{
    if(e==0) return 1;
    if(e&1) return b*power(b*b,e/2);
    return power(b*b,e/2);
}
template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }
template<typename T, typename U> ostream& operator<<(ostream &os, const pair<T, U> &p)
{ 
    return os<<'('<<p.F<< ","<<p.S<<')'; 
}


const int N=200005;
vector<int> v[N];

vector<int> t_sort;
int idx[N];
int vs[N];

bool dfs_sort(int u)
{
    vs[u]=2;
    for(auto j:v[u])
    {
        if(vs[j]==2)
            return true;
        if(vs[j]==0 && dfs_sort(j))
            return true;
    }
    vs[u]=1;
    t_sort.push_back(u);
    return false;
}

// Returns true if there is a topological sort else returns false
bool top_sort(int n)
{
    t_sort.clear();
    for(int i=1;i<=n;++i)
        vs[i]=0;
    for(int i=1;i<=n;++i)
    {
        if(vs[i]==0)
        {
            if(dfs_sort(i))
            {
                t_sort.clear();
                return false;
            }
        }
    }
    reverse(t_sort.begin(),t_sort.end());
    assert(t_sort.size()==n);
    for(int i=0;i<n;++i)
        idx[t_sort[i]]=i;
    return true;
}


int _runtimeTerror_()
{
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> ans;
    for(int i=1;i<=n;++i)
        v[i].clear();
    for(int i=0;i<m;++i)
    {
        int t,x,y;
        cin>>t>>x>>y;
        if(t==1)
            v[x].pb(y);
        ans.pb({x,y});
    }
    bool val=top_sort(n);
    if(!val)
    {
        cout<<"NO\n";
        return 0;
    }
    cout<<"YES\n";
    for(auto &j:ans)
    {
        if(idx[j.F]>idx[j.S])
            swap(j.F,j.S);
        cout<<j.F<<" "<<j.S<<'\n';
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifdef runSieve
        sieve();
    #endif
    #ifdef NCR
        initialize();
    #endif
    int TESTS=1;
    cin>>TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}