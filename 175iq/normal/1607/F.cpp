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
    cini2(n, m);
    vector<vector<char> > vec(n+1, vector<char>(m+1, '.'));

    FE(i,1,n)
        FE(j,1,m)
            cin>>vec[i][j];

    debug(vec);
    vviwv(dp, n+1, m+1, 0);

    auto isvalid = [&](int x, int y)
    {
        return (x >= 1 and x <= n and y >= 1 and y <= m);
    };

    auto calc = [&](int x, int y)
    {
        int cur_x = x, cur_y = y;
        set<pii> st;
        vector<pii> cur_path;
        while(isvalid(cur_x, cur_y) and dp[cur_x][cur_y] == 0)
        {
            if(st.count({cur_x, cur_y}))
                break;

            debug(cur_x, cur_y);
            st.insert({cur_x, cur_y});
            cur_path.pb({cur_x, cur_y});

            if(vec[cur_x][cur_y] == 'L')
                cur_y--;
            else if(vec[cur_x][cur_y] == 'R')
                cur_y++;
            else if(vec[cur_x][cur_y] == 'U')
                cur_x--;
            else 
                cur_x++;
        }   

        if(!isvalid(cur_x, cur_y))
        {
            debug("up");
            int nc = cur_path.sz;
            int cnt = 0;
            FRE(i,nc-1,0)
                dp[cur_path[i].fi][cur_path[i].se] = ++cnt;
        }
        else
        {
            if(st.count({cur_x, cur_y}))
            {
                debug("down");
                int nc = cur_path.sz;
                int cnt = 0;
                int pos = -1;
                FRE(i,nc-1,0)
                {   
                    cnt++;
                    debug(cur_path[i].fi, cur_path[i].se, cnt);
                    if(cur_path[i].fi == cur_x and cur_path[i].se == cur_y)
                    {
                        pos = i;
                        break;
                    }
                }
                FRE(i,nc-1,0)
                {
                    if(i >= pos)
                        dp[cur_path[i].fi][cur_path[i].se] = cnt;
                    else
                        dp[cur_path[i].fi][cur_path[i].se] = ++cnt;
                }
            }
            else
            {
                debug("down2");
                int nc = cur_path.sz;
                int cnt = dp[cur_x][cur_y];
                FRE(i,nc-1,0)
                    dp[cur_path[i].fi][cur_path[i].se] = ++cnt;                
            }
        }
    };

    calc(1, 1);
    int ans = 0;
    int ans_co_x, ans_co_y;
    FE(i,1,n)
    {
        FE(j,1,m)
        {
            if(dp[i][j] == 0)
                calc(i, j);

            if(ans < dp[i][j])
            {
                ans = dp[i][j];
                ans_co_x = i;
                ans_co_y = j;
            }
        }        
    }

    cout<<ans_co_x<<" "<<ans_co_y<<" "<<ans<<"\n";
    return;
}   
 
signed main()
{
    fastIO; 
            
    int T = 1;
    cin>>T;
    
    FE(i,1,T)
    {
        solve();
    }
    return 0;
}