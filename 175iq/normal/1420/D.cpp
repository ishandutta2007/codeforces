#include <bits/stdc++.h>
using namespace std;
        
//Utility functions
#define pb push_back
#define sz size()
#define fi first
#define se second
#define all(d) (d).begin(),(d).end() 
 
//Constants
#define EPS 1e-6
#define INF 2e9
 
//Printing
#define coutRV(a,L,R) FE(i,L,R) cout<<a[i]<<" \n"[i==R] ;
#define coutV(a) coutRV(a,1,a.size()-1)
 
//For loops
#define FE(i,a,b)  for(int i=a; i<=b; i++)
#define FRE(i,b,a) for(int i=b; i>=a; i--)
#define FA(x,cont) for(auto& x : cont)
 
//For debug 
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
 
//Definitions 
#define ll long long
#define ld long double
#define vi vector<int>
#define vll vector<ll>
#define vd vector<double> 
#define vvi vector<vector<int> > //For UnGraph
#define vvpi vector<vector<pii> > //For DirGraph
#define vviwv(vecname, N, M, value) vector<vector<int> > vecname(N, vector<int> (M, value)) //For DP
#define vvlwv(vecname, N, M, value) vector<vector<ll> > vecname(N, vector<ll> (M, value)) //For DP  
#define pii pair<int,int>   
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

//Input 
#define cini(i) int i; cin>>i;
#define cini2(i,j) int i,j; cin>>i>>j;
#define cini3(i,j,k) int i,j,k; cin>>i>>j>>k;
#define cini4(i,j,k,l) int i,j,k,l; cin>>i>>j>>k>>l;
#define cinll(l) ll l; cin>>l;
#define cind(d) double d; cin>>d;
#define cins(s) string s; cin>>s; s = "#" + s;
#define cinv(a, n) vi a(n+1); FE(i,1,n) { cin>>a[i]; }
#define cinvd(a, n) vd a(n+1); FE(i,1,n) { cin>>a[i]; }
#define cinvll(a, n) vll a(n+1); FE(i,1,n) { cin>>a[i]; }

#define int ll

ll MOD = 998244353;

ll mul(ll x, ll y)
{   
    if(x >= MOD)
        x = x%MOD;
    if(y >= MOD)
        y = y%MOD;

    return (x*y)%MOD;
}

ll add(ll x, ll y)
{
    if(x >= MOD)
        x = x%MOD;
    if(y >= MOD)
        y = y%MOD;

    x = (x + y)%MOD;

    return x;
}

ll sub(ll x, ll y) 
{
    if(x >= MOD)
        x = x%MOD;
    if(y >= MOD)
        y = y%MOD;

    ll temp = x - y;
    if(temp < 0)
        temp += MOD;

    temp = (temp)%MOD;

    return temp;
}

//If the number is negative, get the positive value of mod using this way. 
ll negmod(ll a) 
{ 
    return (a%MOD + MOD)%MOD; 
} 

ll binpow(ll x, ll y)
{
    ll ans=1;
    while(y)
    {
        if(y%2==0)
        {
            y/=2;
            x*=x;
        }
        else
        {
            y--;
            ans*=x;
        }
    }
    return ans;
}

ll binpowmod(ll x, ll y)
{
    ll ans=1;
    while(y)
    {
        if(y%2==0)
        {
            y/=2;
            x = mul(x,x);
        }
        else
        {
            y--;
            ans = mul(ans,x);  
        }
    }
    return ans;
}

ll invmod(ll x)
{
    return binpowmod(x, MOD - 2);
}

ll divide(ll x, ll y)
{
    return mul(x, invmod(y));
}

int N = 3e5+10;
vll fact(N);

void precalc()
{
    fact[0] = 1;
    FE(i,1,N-1)
        fact[i] = mul(fact[i - 1], i);
}

ll C(ll n, ll k)
{
    if (n < k)
        return 0;
    if (n < 0 || k < 0) 
        return 0;

    return divide(fact[n], mul(fact[k], fact[n - k])); 
    //return mul( fact[n], mul( invmod(fact[k]), invmod(fact[n-k]) ) ) ; //Another way to do the same
}

void solve()
{   
    cini2(n, k);
    vector<pii> vec(2*n+1);

    for(int i = 1; i <= 2*n; i += 2)
    {
        cini2(l, r);
        vec[i]   = {l, 0};
        vec[i+1] = {r, 1};
    }   
    debug(vec);

    sort(1+all(vec));

    debug(vec);
    int cnt = 0, ans = 0;
    FE(i,1,2*n)
    {
        debug(cnt);
        if(vec[i].se==0)
        {
            cnt++;
            ans = add(ans, C(cnt-1, k-1));        
        }
        else
            cnt--;
    }

    cout<<ans;
    return;
}

signed main()
{
    int t = 1;
    // cin>>t; 
    precalc();
    // debug(fact);

    FE(i, 1, t)
        solve();

    return 0;
}