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
 
///------------------For Online test------------------ ///
#define dbg(...) [](const auto&...x){ char c='='; cerr<<#__VA_ARGS__<<" ";((cerr<<exchange(c,',')<<" "<<x),...); cerr<<endl; }(__VA_ARGS__);
///------------------For Online test------------------ ///

//Definitions 
#define ll long long
#define ld long double
#define vi vector<int>
#define vll vector<ll>
#define vd vector<double> 
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
#define cind(d) double d; cin>>d;
#define cins(s) string s; cin>>s; s = "#" + s;
#define cinv(a, n) vi a(n+1); FE(i,1,n) { cin>>a[i]; }
#define cinvd(a, n) vd a(n+1); FE(i,1,n) { cin>>a[i]; }

#define int ll
#define INFI (int)2e9
#define INFL (ll)9e18
 
void solve()
{   
    // debug("a");
    cini3(n, m, k);
    // debug(n, m, k);

    vvpi gr(n+1);
    FE(i,1,m)
    {
        cini3(x, y, w);
        debug(x, y, w);
        gr[x].pb({w, y});
        gr[y].pb({w, x});
    }   

    vi a(k+1), b(k+1);
    FE(i,1,k)
    {
        cini2(aa, bb);
        a[i] = aa;
        b[i] = bb;
    }   
    debug(a, b);

    vviwv(d, n+1, n+1, INFL);

    function<int(int)> dijkstra = [&](int src)
    {
        set<pii> q;

        d[src][src] = 0;
        q.insert({0, src});

        while(!q.empty())
        {
            pii temp = *(q.begin());
            q.erase(q.begin());

            int u = temp.se;
            // int w = temp.fi;

            FA(pv, gr[u])
            {
                int v = pv.se;
                int w = pv.fi;

                if(d[src][u] + w < d[src][v])
                {
                    q.erase({d[src][v], v});
                    d[src][v] = d[src][u] + w;
                    q.insert({d[src][v], v});   
                }
            }
        }
        return 0;
    };

    FE(i,1,n)
        dijkstra(i);

    debug(d);

    int ans = INFL;
    FE(u,1,n)
    {
        FA(pv, gr[u])
        {
            int v = pv.se;
            int w = pv.fi;

            debug(u, v);
            int tempans = 0;
            FE(i,1,k)
            {
                tempans += min({d[a[i]][b[i]], d[a[i]][u] + d[v][b[i]], d[b[i]][u] + d[v][a[i]]});
            }
            ans = min(ans, tempans);
        }
    }
    cout<<ans<<"\n";
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