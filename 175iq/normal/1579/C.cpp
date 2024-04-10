
#include <bits/stdc++.h>
#include <random>
#include <chrono>
using namespace std;
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
 
template<typename T> void _do(T x){cerr<<x<<"\n";}
template<typename T,typename ...U> void _do(T x,U ...y){cerr<<x<<", ";_do(y...);}
#define dbg(...) cerr<<#__VA_ARGS__<<" = ";_do(__VA_ARGS__);
 
const int MOD1=1e9+7;
const int MOD2=998244353;
const ll INF=3e18;
const ld PI=3.14159265358979323846;
ll gcd(ll a,ll b){if(b==0) return a; return gcd(b,a%b);}
ll fpow(ll a,ll b,ll m)
{
    if(!b) return 1;
    ll ans=fpow(a*a%m,b/2,m);
    return (b%2?ans*a%m:ans);
}
ll inv(ll a,ll m) {return fpow(a,m-2,m);}
 
#define MottoHayaku ios::sync_with_stdio(false);cin.tie(0);
#define int ll
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep1(i,n) for(ll i=1;i<=n;i++)
#define repk(i,m,n) for(int i=m;i<n;i++)
#define F first
#define S second
#define pb push_back
#define SZ(a) ((ll)a.size())
#define reset(a) memset(a,0,SZ(a))
#define cd(a,b) ((a+b-1)/b)
#define pow2(a) (1LL<<a)
#define LB(a,x) (lower_bound(a.begin(),a.end(),x))
#define LPOS(a,x) (lower_bound(a.begin(),a.end(),x)-a.begin())
#define UB(a,x) (upper_bound(a.begin(),a.end(),x))
#define UPOS(a,x) (upper_bound(a.begin(),a.end(),x)-a.begin())
#define uni(c) c.resize(distance(c.begin(),unique(c.begin(),c.end())))
#define unisort(c) sort(c.begin(),c.end()),uni(c)
signed main()
{
    MottoHayaku
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,m,k;
        cin>>n>>m>>k;
        vector<string> s(n);
        vector<vector<bool> > can(n,vector<bool>(m,0));
        rep(i,n) cin>>s[i];
        rep(i,n)
        {
            rep(j,m)
            {
                if(s[i][j]=='.') continue;
                ll cnt=0;
                rep1(h,n)
                {
                    if(i-h<0||j-h<0||j+h>=m) break;
                    if(s[i-h][j-h]=='.'||s[i-h][j+h]=='.') break;
                    cnt++;
                }
                if(cnt>=k)
                {
                    rep(h,cnt+1)
                    {
                        can[i-h][j-h]=can[i-h][j+h]=1;
                    }
                }
            }
        }
        bool x=1;
        rep(i,n) rep(j,m) if(s[i][j]=='*'&&!can[i][j]) x=0;
        cout<<(x?"YES\n":"NO\n");
    }
}