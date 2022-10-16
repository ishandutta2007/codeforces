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
    cini4(n,m,K,w);
    vector<vector<vector<char>>> vec(K+1, vector<vector<char>>(n+1, vector<char>(m+1, '.')));

    FE(i,1,K)
        FE(j,1,n)
            FE(k,1,m)
                cin>>vec[i][j][k];

    function<int(int, int)> calc_weight = [&](int l1, int l2)
    {
        int diff = 0;
        FE(i,1,n)
        {
            FE(j,1,m)
            {
                if(vec[l1][i][j] != vec[l2][i][j])
                    diff++;
            }
        }
        // debug(l1, l2, diff);
        return diff*w;
    };

    vvpi gr(K+1);
    FE(i, 1, K)
    {   
        FE(j, i+1, K)
        {
            int wt = calc_weight(i, j);
            gr[i].pb({wt, j});
            gr[j].pb({wt, i});
        }
    }

    FE(i, 1, K)
    {
        gr[i].pb({n*m, 0});
        gr[0].pb({n*m, i});
    }

    debug(gr);

    n = K;
    int mst_wt = 0;
    vector<pii> min_edge(n+1);  // Stores the minimum edge going out from this vertex to an ""already marked vertex"".
    FE(i,1,n)
        min_edge[i] = {INFL, 0};

    vi included(n+1, 0);      
    set<pii> s;        // Stores ""unmarked"" vertex along with the edges from them to a ""marked"" vertex. 

    min_edge[0] = {0, 0};
    included[0] = 1;             
    s.insert({0, 0});  // Insert vertex 1 with an edge of 0 just to start the algorithm.

    vector<pii> ans;
    // FE(i,0,n)  //We should be able to mark n vertices as n_vert in mst = n 
    FE(i,0,n)
    {
        // if(s.empty())
        // {
        //     cout<<"MST doesn't exist\n";    // As we were not able to mark n vertices
        //     return;
        // }

        auto it = s.begin();

        int W = it->fi;      // This is the minimum wt edge amongst all edges from a ""marked to unmarked vertex(''u'')"".
        int u = it->se;      // u is unmarked as of now. Parent of u will be the other end of this edge(which we haven't stored)
        int pu = min_edge[u].se;   // This is the other end of the edge which has been picked
    
        s.erase(it);

        ans.pb({u, pu});

        included[u] = 1;
        mst_wt += W;

        FA(pv, gr[u])      //Now that u is marked we want to update min_edge for all other vertices adj to u.
        {
            int v      = pv.se;
            int w_from_u_to_v = pv.fi;
            if(!included[v] and w_from_u_to_v < min_edge[v].fi) //This edge goes from a ""marked vertex(u)"" to ""unmarked vertex v"".
            {
                s.erase({min_edge[v].fi, v}); //This might not exist in the set, in that case too, no error is thrown by set.
                min_edge[v] = {w_from_u_to_v, u};
                s.insert({w_from_u_to_v, v});
            }
        }          
    }

    cout<<mst_wt<<"\n";
    int cnt = 0;
    FA(x, ans)
    {
        if(cnt)
            cout<<x.fi<<" "<<x.se<<"\n";
        cnt++;
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