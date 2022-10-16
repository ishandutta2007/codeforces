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
    cini3(n, m, T);

    vvpi gr(n+1);
    FE(i,1,m)
    {
        cini3(u, v, t);
        gr[u].pb({t, v});
    }

    vviwv(dp, n+1, n+1, -1);
    // vviwv(parent, n+1, n+1, 0);
    function<int(int, int)> calc = [&](int u, int nnodes)
    {
        if(u == n)
        {
            if(nnodes == 1)
                return 0ll;
            else
                return INFL;
        }

        int& ans = dp[u][nnodes];
        if(ans != -1)
            return ans;

        ans = INFL;
        FA(pv, gr[u])
        {
            int v = pv.se;
            int w = pv.fi;
            if(nnodes - 1 >= 1)
            {
                if(ans > w + calc(v, nnodes-1))
                {
                    ans = w + calc(v, nnodes-1);
                    // parent[v][nnodes-1] = u;
                }
            }
        }
        return ans;
    };  

    int zz = 0;
    FRE(i,n,1)
    {
        if(calc(1, i) <= T)
        {
            zz = i;
            cout<<i<<"\n";
            break;
        }
    }

    // debug(parent[n][1]);
    // int cur = 1;
    // vi ansvec;
    // FE(i, 1, zz)
    // {   
    //     int temp =  INFI;
    //     int tempv = -1;

    //     ansvec.pb(cur);

    //     if(cur == n)
    //         break;
    //     FA(curv, gr[cur])
    //     {
    //         int v = curv.se;
    //         if(temp > calc(v, zz-i))
    //         {
    //             temp = calc(v, zz-i);
    //             tempv = v;
    //         }
    //     }
    //     cur = tempv;
    // }

    // FA(x, ansvec)
    //     cout<<x<<" ";

    // int cur = n;
    // int len = 1;
    // vi ansvec;
    // ansvec.pb(n);

    // FE(i,1,zz-1)
    // {
    //     ansvec.pb(parent[cur][len]);
    //     cur = parent[cur][len++];
    // }

    // assert(ansvec.sz == zz);
    // reverse(all(ansvec));
    // FA(x, ansvec)
    //     cout<<x<<" ";

    // // FRE(i, ans-1, 0)
    // //     cout<<ansvec[i]<<" ";


    // void trace(int u, int cnt){
    //     printf("%d ", u + 1);
    //     if(u == n - 1 && !cnt)exit(0);
    //     for(auto v : adj[u]){
    //         if(v.second + solve(v.first, cnt - 1) == dp[u][cnt])
    //             trace(v.first, cnt - 1);
    //     }
    // }


    function<void(int, int )> trace = [&](int u, int nnode)
    {
        cout<<u<<" ";
        if(u == n)
            exit(0);

        FA(pv, gr[u])
        {
            int v = pv.se;
            int w = pv.fi;

            if(w + calc(v, nnode-1) == dp[u][nnode])
                trace(v, nnode-1);
        }
        return;
    };

    trace(1, zz);
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