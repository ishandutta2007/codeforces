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
    cini2(n, k);
    cinv(x, k);

    vi leaves, deg(n+1, 0);
    vvi gr(n+1);
    FE(i,1,n-1)
    {
        cini2(u,v);
        gr[u].pb(v);
        gr[v].pb(u);
        deg[u]++;
        deg[v]++;
    }
    debug(x, gr,n,k);
    FE(i,1,n)
    {
        if(deg[i]==1)
            leaves.pb(i);
    }
    debug(deg,leaves);
    vi dstart(n+1), visited(n+1), parent(n+1);
        
    int start = 1;
    queue<int> q;
    q.push(start);
    dstart[start] = 0;
    visited[start] = 1;

    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        FA(v, gr[u])
        {
            if(!visited[v])
            {
                visited[v] = 1;
                dstart[v] = dstart[u] + 1;
                q.push(v);
            } 
        }
    }

    while(!q.empty())
        q.pop();

    visited.assign(n+1, 0);
    FE(i,1,k){
        q.push(x[i]);
        visited[x[i]] = 1;
    }


    vi dx(n+1, 0);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        FA(v, gr[u])
        {
            if(!visited[v])
            {
                visited[v] = 1;
                dx[v] = dx[u] + 1;
                q.push(v);
            } 
        }
    }
    debug(dstart);
    debug(dx);
    FA(l, leaves)
    {
        debug(l);
        if(l!=1)
        {
            if(dstart[l] < dx[l])
            {
                cout<<"YES\n";
                return;
            }            
        }
    }

    cout<<"NO\n";

    return;
}
 
signed main()
{
    fastIO; 
            
    int T = 1;
    cin>>T;

    FE(i,1,T)
        solve();

    return 0;
}