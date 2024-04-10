#include<bits/stdc++.h>
using namespace std ;

#define ll              long long 
#define pb              push_back
#define all(v)          v.begin(),v.end()
#define sz(a)           (ll)a.size()
#define F               first
#define S               second
#define INF             2000000000000000000
#define popcount(x)     __builtin_popcountll(x)
#define pll             pair<ll,ll> 
#define pii             pair<int,int>
#define ld              long double

const int M = 1000000007;
const int MM = 998244353;
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

const int N = 100005;


int _runtimeTerror_()
{
    int n;
    cin>>n;
    set<int> s;
    vector<int> ans(2*n+1,-1);
    stack<int> st;
    st.push(n+1);
    vector<int> idx(n+2,0);
    for(int i=1;i<=2*n;++i)
    {
        char c;
        int x;
        cin>>c;
        if(c=='+')
        {
            s.insert(i);
        }
        else
        {
            cin>>x;
            idx[x] = i;
            while(st.top()<x)
                st.pop();
            auto it = s.lower_bound(idx[st.top()]);
            st.push(x);
            if(it==s.end())
            {
                cout<<"NO\n";return 0;
            }
            ans[*it] = x;
            s.erase(*it);
        }
    }
    cout<<"YES\n";
    for(int i=1;i<=2*n;++i)
    {
        if(ans[i]!=-1)
            cout<<ans[i]<<" ";
    }
    cout<<"\n";
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