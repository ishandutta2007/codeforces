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

int _runtimeTerror_()
{
    int n;
    string s;
    cin>>n>>s;
    int x=n-6;
    string t("abacaba");
    int cnt=0;
    for(int i=0;i<x;++i)
    {
        string l=s.substr(i,7);
        if(l==t)
            ++cnt;
    }
    if(cnt>1)
    {
        cout<<"No\n";return 0;
    }
    if(cnt==1)
    {
        cout<<"Yes\n";
        for(auto j:s)
            cout<<(j=='?'?'d':j);
        cout<<'\n';
        return 0;
    }
    auto f=[&](string ans)
    {
        int c=0;
        for(int i=0;i<x;++i)
        {
            string l=ans.substr(i,7);
            if(l==t)
                ++c;
        }
        return c==1;
    };
    bool done=false;
    for(int i=0;i<x;++i)
    {
        string l=s.substr(i,7);
        bool val=false;
        for(int k=0;k<7;++k)
        {
            if(l[k]=='?' || t[k]==l[k])
                continue;
            else
            {
                val=true;break;
            }
        }
        if(val)
            continue;
        string ans=s;
        for(int k=0;k<7;++k)
            ans[i+k]=t[k];
        for(int j=0;j<n;++j)
            if(ans[j]=='?')
                ans[j]='d';
        if(f(ans))
        {
            s=ans;
            done=true;break;
        }
        else
            continue;
    }
    if(done)
        cout<<"Yes\n"<<s<<"\n";
    else cout<<"No\n";
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