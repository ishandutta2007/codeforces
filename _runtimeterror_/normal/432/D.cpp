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
vector<int> zFunction(string &s)
{
    int n=sz(s),l,r,i;
    vector<int> z(n);
    z[0]=n;
    l=r=0;
    for(i=1;i<n;++i)
    {
        if(i<=r)
            z[i]=min(r-i+1,z[i-l]);
        while(i+z[i]<n && s[z[i]]==s[z[i]+i])
            ++z[i];
        if(i+z[i]-1>r)
        {
            l=i;r=i+z[i]-1;
        }
    }
    return z;
}
int _runtimeTerror_()
{
    string s;
    cin>>s;
    vector<int> z=zFunction(s);

    vector<pair<int,int>> ans;
    vector<int> len(s.size()+2,0);
    int n=sz(s);
    for(int i=0;i<n;++i)
    {
        ++len[0];
        --len[z[i]+1];
        if(z[i]==n-i)
            ans.pb({z[i],0});
    }
    reverse(all(ans));
    int sum=len[0];
    int i=1;
    for(auto &j:ans)
    {
        while(i<=j.F)
        {
            sum+=len[i];
            ++i;
        }
        j.S=sum;
    }
    cout<<sz(ans)<<"\n";
    for(auto j:ans)
        cout<<j.F<<" "<<j.S<<"\n";
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