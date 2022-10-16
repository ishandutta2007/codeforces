#include <bits/stdc++.h>
using namespace std;
        
//Utility functions
#define pb push_back
#define sz size()
#define fi first
#define se second
#define all(c) (c).begin(),(c).end() 
  
//Printing
#define coutRV(a,L,R) FE(i,L,R) cout<<a[i]<<" \n"[i==R];
#define coutV(a) coutRV(a,1,a.size()-1)
 
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
 
// #define int ll
#define INFI (int)2e9
#define INFL (ll)9e18
  
ll MOD = 1e9+7;

ll add(ll x, ll y)
{
    if(x >= MOD)
        x = x%MOD;
    if(y >= MOD)
        y = y%MOD;

    x = (x + y)%MOD;

    return x;
}

void solve()
{    
    cini2(r, g);
    int n = r + g;

    int h = sqrt(2*n);
    while((h*(h+1))/2 <= n)
        h++;

    h--;

    vviwv(dp, 2, r+1, 0);
    dp[0][0] = 1;
    // dp[1][1] = 1;
    // dp[1][0] = 1;

    FE(pos,1,h)
    {
        int t = pos&1;    
        FE(reu,0,r)
        {   
            dp[t][reu] = 0;
            int gru;
            gru = (pos)*(pos+1)/2 - reu;
            if(gru < 0 or gru > g)
                continue;

            int rleft = r - reu;
            int gleft = g - gru;

            if(rleft < 0 or rleft > r or gleft < 0 or gleft > g)
                continue;

            if(reu - pos >= 0)
                dp[t][reu] = add(dp[t][reu], dp[!t][reu-pos]);

            if(gru - pos >= 0)
                dp[t][reu] = add(dp[t][reu], dp[!t][reu]);
        }        
    }

    int ans = 0;
    FE(re, 0, r)
        ans = add(ans, dp[h&1][re]);

    cout<<ans<<"\n";
    // cout<<calc(1, 0)<<"\n";
    return;
}   
 
signed main()
{
    fastIO;
    int T = 1;
    // cin>>T;
 
    FE(i,1,T)
    {
        // cout<<"Case #"<<i<<": ";
        solve();    
    }
 
    return 0;
}