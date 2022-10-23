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

const int N = 3e5+5;
ll a[N];
int n;
int minl[N],minr[N],maxl[N],maxr[N];
ll dp[N];   
bool vis[N];

set<int> v1[N],v2[N];

int _runtimeTerror_()
{
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>a[i];

    stack<int> st;
    st.push(1);
    for(int i=2;i<=n;++i)
    {
        while(!st.empty() && a[st.top()]<=a[i])
        {
            maxr[st.top()]=i;
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty())
    {
        maxr[st.top()]=n+1;
        st.pop();
    }
    st.push(1);
    for(int i=2;i<=n;++i)
    {
        while(!st.empty() && a[st.top()]>=a[i])
        {
            minr[st.top()]=i;
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty())
    {
        minr[st.top()]=n+1;
        st.pop();
    }
    for(int i=1;i<=n;++i)
        v1[maxr[i]].insert(i),v2[minr[i]].insert(i);
    st.push(n);
    for(int i=n-1;i>=1;--i)
    {
        while(!st.empty() && a[st.top()]<=a[i])
        {
            maxl[st.top()]=i;
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty())
    {
        maxl[st.top()]=0;
        st.pop();
    }
    st.push(n);
    for(int i=n-1;i>=1;--i)
    {
        while(!st.empty() && a[st.top()]>=a[i])
        {
            minl[st.top()]=i;
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty())
    {
        minl[st.top()]=0;
        st.pop();
    }
    queue<ll> q;
    q.push(n);
    dp[n]=0;
    vis[n]=true;
    while(!q.empty())
    {
        int j = q.front();
        q.pop();
        if(j==1)
            break;
        if(a[j-1]==a[j])
        {
            if(!vis[j-1])
            {
                dp[j-1]=dp[j]+1;
                vis[j-1]=true;
                q.push(j-1);
            }
            continue;
        }
        if(a[j-1]<a[j])
        {
            int u = maxl[j];
            if(u>0 && !vis[u])
            {
                dp[u]=dp[j]+1;
                vis[u]=true;
                q.push(u);
            }
            vector<int> er;
            for(auto k:v1[j])
            {
                er.pb(k);
                if(vis[k])
                    continue;
                dp[k]=dp[j]+1;
                vis[k]=true;
                q.push(k);
            }
            for(auto k:er)
                v1[j].erase(k);
        }
        else
        {
            int u = minl[j];
            if(u>0 && !vis[u])
            {
                dp[u]=dp[j]+1;
                vis[u]=true;
                q.push(u);
            }
            vector<int> er;
            for(auto k:v2[j])
            {
                er.pb(k);
                if(vis[k])
                    continue;
                dp[k]=dp[j]+1;
                vis[k]=true;
                q.push(k);
            }
            for(auto k:er)
                v2[j].erase(k);
        }
    }
    cout<<dp[1];
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
    //cin>>TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}