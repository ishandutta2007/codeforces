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
    fastIO;
    cini2(n, k);

    cinv(p, n);
    cinv(q, n);

    vvi gr(n+1), grrev(n+1);
    vi visited(n+1, 0);
    vi order, component;

    FE(i,1,n-1)
    {
        gr[p[i]].pb(p[i+1]);
        gr[q[i]].pb(q[i+1]);

        grrev[p[i+1]].pb(p[i]);
        grrev[q[i+1]].pb(q[i]);
    }

    function<void(int)> dfs1 = [&](int u)
    {       
        visited[u] = 1;
        FA(v, gr[u])
        {
            if(!visited[v])
                dfs1(v);
        }
        order.pb(u);
        return;
    };

    function<void(int)> dfs2 = [&](int u)
    {       
        component.pb(u);
        visited[u] = 1;
        FA(v, grrev[u])
        {
            if(!visited[v])
                dfs2(v);
        }
        return;
    };

    FE(i,1,n)
    {
        if(visited[i] == 0)
            dfs1(i);
    }

    visited.assign(n+1, 0);

    reverse(all(order));

    int nscc = 1;
    map<int, int> mp;
    vi node_leader(n+1, 0);
    vvi comp_no(n+1);    
    vi comp_nod(n+1);
    FA(ver, order)
    {
        if(!visited[ver])
        {
            dfs2(ver);

            // cout<<"SCC: ";

            int comp_leader = component.front();
            FA(node, component)
            {
                // cout<<node<<" ";
                comp_no[nscc].pb(node);
                comp_nod[node] = nscc;
                node_leader[node] = comp_leader;
                mp[nscc] = comp_leader; 
            }
            // cout<<"\n";
                
            nscc++;
            component.clear();
        }
    }

    // cout<<"\n";
    /////////////////////////////////////////////////////////////////////
    //CONDENSATION GRAPH comes out to be a DAG . 
    /////////////////////////////////////////////////////////////////////
    if(nscc - 1 < k)
    {
        cout<<"NO\n";
        return;
    }
    else
        cout<<"YES\n";
    // Condensation Graph
    // Number of nodes in condensation graph is nscc-1
    vvi condens_graph(nscc); 

    FE(u, 1, n)
    {
        FA(v, gr[u])
        {
            if(comp_nod[u] != comp_nod[v])
            {
                condens_graph[comp_nod[u]].pb(comp_nod[v]);
            }
        }
    }

    // order.clear();
    // visited.assign(2*n+1, 0);
    // function<void(int)> topo = [&](int u)
    // {   
    //     visited[u] = 1;
    //     FA(v, condens_graph[u])
    //     {
    //         if(!visited[v])
    //             topo(v);
    //     }
    //     order.pb(u);
    //     return;
    // };

    // FE(i,1,nscc-1)
    // {
    //     if(!visited[i])
    //         topo(i);
    // }

    // reverse(all(order));
    // debug(order);

    vector<char> ans(n+1);
    char c = 'a';
    FE(i, 1, nscc-1)
    {
        FA(j, comp_no[i])
        {
            debug(i, j);
            ans[j] = c; 
        }
        c++;
        if(c > 'z')
            c = 'z'; 
        // c = min(c+1, 'z');
    }    
    assert(c-'a' <= 26);

    FE(i,1,n)
        cout<<ans[i];

    // FE(u, 1, nscc-1)
    // {
    //     cout<<"Node "<<u<<" of condensation graph belongs to component with leader(node from original graph) : "<<mp[u]<<"\n";
    //     cout<<"Edges from this node in condensation graph are : \n";
    //     FA(v, condens_graph[u])
    //     {
    //         cout<<u<<" "<<v<<"\n";
    //     }
    //     cout<<"\n";
    // }

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