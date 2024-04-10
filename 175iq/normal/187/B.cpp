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
 
#define int ll
#define INFI (int)2e9
#define INFL (ll)1e18

void solve()
{
    cini3(n, m, r);

    int t[65][65][65];

    FE(i,1,m)
        FE(j,1,n)
            FE(k,1,n)
                cin>>t[i][j][k];

    vi s(r+1), e(r+1), K(r+1);
    FE(i,1,r)
        cin>>s[i]>>e[i]>>K[i];

    // debug(K);

    int d[65][65][65];
    FE(i,0,m)
        FE(j,1,n)
            FE(k,1,n)
            {
                if(i == 0)
                    d[0][j][k] = INFL;
                else
                    d[i][j][k] = t[i][j][k];
            }

    FE(c,1,m)
        FE(k,1,n)
            FE(i,1,n)
                FE(j,1,n)
                    d[c][i][j] = min(d[c][i][j], d[c][i][k] + d[c][k][j]);

    // FE(c,1,m)
    // {
    //     FE(i,1,n)
    //     {
    //         FE(j,1,n)
    //         {
    //             cout<<d[c][i][j]<<" ";
    //         }
    //         cout<<"\n";            
    //     }
    //     cout<<"----------\n";
    // }

    FE(i,1,n)
        FE(j,1,n)
        {
            // debug(i, j);
            FE(c,1,m)
            {
                d[0][i][j] = min(d[0][i][j], d[c][i][j]);
                // debug(c, d[c][i][j], d[0][i][j]);
            }
        }

    // FE(i,1,n)
    //     FE(j,1,n)
    //         debug(i, j, d[0][i][j]);

    int dp[65][65][65];
    memset(dp, -1, sizeof(dp));
    function<int(int, int, int)> calc = [&](int st, int en, int kk)
    {   
        debug(st,en,kk);
        if(kk == 0)
            return d[0][st][en];

        if(st == en)
            return 0ll;

        int& ans = dp[st][en][kk];
        if(ans!=-1)
            return ans;

        ans = INFL;
        FE(intr, 1, n)
        {
            if(intr != st)
                ans = min(ans, d[0][st][intr] + calc(intr, en, kk-1));
        }

        return ans;
    };

    FE(i,1,r)
    {
        int ans;
        ans = calc(s[i], e[i], min(K[i], n-1));
        cout<<ans<<"\n";
    }
    return;
}             
 
signed main()
{
    fastIO;
 
    int T = 1;
    // cin>>T;
 
    FE(t,1,T)
    {
        // cout<<"Case #"<<t<<": "; 
        solve();
    }
    return 0;
}