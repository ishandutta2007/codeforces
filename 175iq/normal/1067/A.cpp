#include <bits/stdc++.h>
using namespace std;
  
//Utility functions
#define pb push_back
#define sz size()
#define fi first
#define se second
#define all(c) (c).begin(),(c).end() 
   
//For loops
#define FE(i,a,b)  for(int i=a; i<=b; i++)
#define FRE(i,b,a) for(int i=b; i>=a; i--)
#define FA(x,cont) for(auto& x : cont)
 
//For debug 
// ----------------------------- (Debug) ------------------------------
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; }; sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0); sim > char dud(...);
struct debug {
#ifdef LOCAL
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i));}
sim, class b dor(pair < b, c > d) {ris << "(" << d.first << ", " << d.second << ")";}
sim dor(rge<c> d) {*this << "["; for (auto it = d.b; it != d.e; ++it) *this << ", " + 2 * (it == d.b) << *it; ris << "]";}
#else
sim dor(const c&) { ris; }
#endif
};
vector<char*> tokenizer(const char* args) {
    char *token = new char[111]; strcpy(token, args); token = strtok(token, ", ");
    vector<char*> v({token});
    while((token = strtok(NULL,", "))) v.push_back(token);
    return reverse(v.begin(), v.end()), v;
}
void debugg(vector<char*>) { cerr << ""; }
template <typename Head, typename... Tail>
void debugg(vector<char*> args, Head H, Tail... T) {
    debug() << " [" << args.back() << ": " << H << "] ";
    args.pop_back(); debugg(args, T...);
}
#define harg(...) #__VA_ARGS__
#ifdef LOCAL
#define debug(...) { debugg(tokenizer(harg(LINE, __VA_ARGS__)),__LINE__, __VA_ARGS__); cerr << endl;}
#else
#define debug(...) { }
#endif
/// -----------------------------------------------------------------------
 
///------------------For Online test------------------ ///
#define dbg(...) [](const auto&...x){ char c='='; cerr<<#__VA_ARGS__<<" ";((cerr<<exchange(c,',')<<" "<<x),...); cerr<<endl; }(__VA_ARGS__);
///------------------For Online test------------------ ///
 
//Definitions 
#define ll long long
#define ld long double
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vector<int> > //For UnGraph
#define vvpi vector<vector<pii> > //For DirGraph
#define vviwv(vecname, N, M, value) vector<vector<int> > vecname(N, vector<int> (M, value)) //For DP
#define pii pair<int,int>   
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
//Input 
#define cini(i) int i; cin>>i;
#define cini2(i,j) int i,j; cin>>i>>j;
#define cini3(i,j,k) int i,j,k; cin>>i>>j>>k;
#define cini4(i,j,k,l) int i,j,k,l; cin>>i>>j>>k>>l;
#define cins(s) string s; cin>>s; s = "#" + s;
#define cinv(a, n) vi a(n+1); FE(i,1,n) { cin>>a[i]; }
 
// #define int ll
#define INFI (int)2e9
#define INFL (ll)7e18

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

int N = 2e5+10;
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
    cini(n);
    cinv(a, n);

    vector<vector<vector<int> > > dp(2, vector<vector<int> >(201, vector<int> (2, 0)));

    // if(n == 2 and a[1] == -1 and a[2] == -1)
    // {
    //     cout<<200<<"\n";
    //     return;
    // }

    // if(n == 2 and a[1] != -1)
    // {
    //     cout<<1<<"\n";
    //     return;
    // }

    if(a[1] == -1)
    {
        FE(i,1,200)
        {
            dp[1&1][i][0] = 1;
            // dp[1][i][1] = 1;
        }           
    }
    else
    {
        dp[1&1][a[1]][0] = 1;
        // dp[1][a[1]][1] = 1;
    }

    vvi prefdp(201, vi(2,0));
    // vector<vector<vector<int> > > prefdp(n+1, vector<vector<int> >(201, vector<int> (2, 0)));
    FE(i,2,n)
    { 
        FE(j,1,200)
        {
            prefdp[j][0] = add(prefdp[j-1][0], dp[(i-1)&1][j][0]); // Prefix sums over dp vector //
            prefdp[j][1] = add(prefdp[j-1][1], dp[(i-1)&1][j][1]);
        }

        if(a[i] == -1)
        {
            FE(j,1,200)
            {
                dp[(i)&1][j][0] = add(prefdp[j-1][0], prefdp[j-1][1]);  /* dp[i-1][1...j][0] + dp[i-1][1...j][1];*/
                dp[(i)&1][j][1] = add(sub(prefdp[200][1], prefdp[j-1][1]), dp[(i-1)&1][j][0]); 
            }            
        }
        else
        {
            FE(j,1,200)
            {
                if(j != a[i])
                {
                    dp[(i)&1][j][0] = 0;
                    dp[(i)&1][j][1] = 0;
                }
                else
                {
                    dp[(i)&1][a[i]][0] = add(prefdp[a[i]-1][0], prefdp[a[i]-1][1]);
                    dp[(i)&1][a[i]][1] = add(sub(prefdp[200][1], prefdp[a[i]-1][1]), dp[(i-1)&1][a[i]][0]);
                }
            }
        }
    }
    // debug(dp[1][1][0], dp[1][1][1]);
    // debug(dp[1][2][0], dp[1][2][1]);
    // debug(dp[2][2][0], dp[2][2][1]);
    // debug(dp[3][2][0], dp[3][2][1]);

    int ans = 0;
    if(a[n] == -1)
    {
        FE(i,1,200)
            ans = add(ans, dp[n&1][i][1]);        
    }
    else
        ans = dp[n&1][a[n]][1];

    cout<<ans<<"\n";
    return;
}
 
signed main()
{
    fastIO; 
    
    int T = 1;
    // cin>>T;
    
    FE(i,1,T)
        solve();
    
    return 0;
}