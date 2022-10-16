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
    cini(n);
    vector<pii> a(n+1), b(n+1);
    FE(i,1,n)
    {
        cini(x);
        a[i] = {x, i};
    }

    FE(i,1,n)
    {
        cini(x);
        b[i] = {x, i};
    }

    sort(1+all(a));
    sort(1+all(b));

    vvi gr(n+1);

    FE(i,2,n)
        gr[a[i-1].se].pb(a[i].se);

    FE(i,2,n)
        gr[b[i-1].se].pb(b[i].se);

    int dfs_time = 0;
    
    vi color(n+1,0);
    vi parent(n+1,-1);
    
    function<void(int)> dfs = [&](int u)
    {
        color[u] = 1;
        FA(v, gr[u])
        {
            if(color[v] == 0)
            {
                // Tree Edge
                parent[v] = u;
                dfs(v);
            }
        }
        color[u] = 2;
        return;
    };  

    vi color2(n+1,0);
    function<void(int)> dfs2 = [&](int u)
    {
        color2[u] = 1;
        FA(v, gr[u])
        {
            if(color2[v] == 0)
            {
                // Tree Edge
                parent[v] = u;
                dfs2(v);
            }
        }
        color2[u] = 2;
        return;
    };  

    dfs(a[n].se);
    dfs2(b[n].se);

    FE(i,1,n)
    {
        if(color2[i] or color[i])
            cout<<1;
        else
            cout<<0;
    }
    cout<<"\n";
    return;     
}
 
signed main()
{
    fastIO; 
    
    // test();
    int T = 1;
    cin>>T;
    
    FE(i,1,T)
        solve();
 
    return 0;
}