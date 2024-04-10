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
#define INFL (ll)7e18

struct Edge
{
    int u, v, w;
    Edge(int uu, int vv, int ww)
    {
        u = uu, v = vv, w = ww;
    }
    bool operator<(Edge& other) const
    {
        return w < other.w;
    }
};

void solve()
{
    cini2(n, m);
    cinv(a, n);

    vector<Edge> edges;
    FE(i,1,m)    
    {
        cini3(a, b, c);
        edges.pb(Edge(a, b, c));
    }   

    int mini = INFL, minidx;
    FE(i,1,n)
    {
        if(a[i] < mini)
        {
            mini = a[i];
            minidx = i;
        }
    }

    FE(i,1,n)
    {
        if(i != minidx)
            edges.pb(Edge(i, minidx, a[i] + a[minidx]));
    }

    vi parent(n+1), siz(n+1);

    function<void()> init = [&]()
    {
        FE(v,1,n)
        {
            parent[v] = v;
            siz[v] = 1;
        }
        return;    
    };

    function<int(int)> find_set = [&](int v)
    {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);        
    };

    function<void(int, int)> union_sets = [&](int a, int b)
    {
        a = find_set(a);
        b = find_set(b);
        if (a != b) 
        {
            if (siz[a] < siz[b])
                swap(a, b);
            parent[b] = a;
            siz[a] += siz[b];
        }
        return;        
    };

    init();

    sort(all(edges));

    int mst_wt = 0;
    FA(edge, edges)
    {
        if(find_set(edge.u) != find_set(edge.v))
        {
            mst_wt += edge.w;
            union_sets(edge.u, edge.v);
        }
    }
    cout<<mst_wt<<"\n";
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