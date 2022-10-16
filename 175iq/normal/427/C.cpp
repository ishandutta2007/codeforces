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
#define INFI 2e9
#define INFL 9e18
    
// struct edge
// {
//     int u, v;
//     ld w;
//     edge(int uu, int vv, ld ww)
//     {
//         u = uu, v = vv, w = ww;
//     }
// };

// void solve()
// {   
//     cini2(n, m);

//     cout<<fixed;
//     cout<<setprecision(18);

//     vector<edge> edges;
//     ld mini = INFL, maxi = -INFL;
//     FE(i,1,m)
//     {
//         cini2(x, y)
//         ld z;
//         cin>>z;
//         edges.pb(edge(x, y, z));
//         mini = min(mini, z);
//         maxi = max(maxi, z);
//     }

//     cini2(a, b);
//     function<int(ld)> f = [&](ld x)
//     {
//         // vector<edge> tedges = edges;
//         FA(edge, edges)
//             edge.w -= x;

//         vector<ld> d(n+1, INFL);
//         d[a] = 0;
//         FE(iter, 1, 2*n)
//         {
//             FA(edge, edges)
//             {
//                 if(iter > n)
//                 {
//                     if(d[edge.u] < INFL)
//                     {
//                         if(d[edge.v] > d[edge.u] + edge.w)
//                             d[edge.v] = -INFL;
//                     }                                        
//                 }
//                 else
//                 {
//                     if(d[edge.u] < INFL)
//                     {
//                         d[edge.v] = min(d[edge.v], d[edge.u] + edge.w);
//                     }                    
//                 }
//             }
//         }
//         FA(edge, edges)
//             edge.w += x;

//         if(d[b] <= 0)
//             return 1;
//         return 0;
//     };

//     ld l = mini, r = maxi;
//     ld ans = -1;
//     FE(iter,1,75)
//     {
//         ld mid = (l+r)/2;
//         if(f(mid))
//         {   
//             ans = mid;
//             r = mid;
//         }
//         else
//             l = mid;
//     }

//     cout<<ans<<"\n";

//     return;
// }             
 
// signed main()
// {
//     fastIO;
 
//     int T = 1;
//     cin>>T;
 
//     FE(t,1,T)
//     {
//         // cout<<"Case #"<<t<<": "; 
//         solve();
//     }
 
//     return 0;
// }


ll MOD = 1e9+7;

ll mul(ll x, ll y)
{   
    if(x >= MOD)
        x = x%MOD;
    if(y >= MOD)
        y = y%MOD;

    return (x*y)%MOD;
}

ll add(ll x, ll y)
{
    if(x >= MOD)
        x = x%MOD;
    if(y >= MOD)
        y = y%MOD;

    x = (x + y)%MOD;

    return x;
}

ll sub(ll x, ll y) 
{
    if(x >= MOD)
        x = x%MOD;
    if(y >= MOD)
        y = y%MOD;

    ll temp = x - y;
    if(temp < 0)
        temp += MOD;

    temp = (temp)%MOD;

    return temp;
}

//If the number is negative, get the positive value of mod using this way. 
ll negmod(ll a) 
{ 
    return (a%MOD + MOD)%MOD; 
} 

ll binpow(ll x, ll y)
{
    ll ans=1;
    while(y)
    {
        if(y%2==0)
        {
            y/=2;
            x*=x;
        }
        else
        {
            y--;
            ans*=x;
        }
    }
    return ans;
}

ll binpowmod(ll x, ll y)
{
    ll ans=1;
    while(y)
    {
        if(y%2==0)
        {
            y/=2;
            x = mul(x,x);
        }
        else
        {
            y--;
            ans = mul(ans,x);  
        }
    }
    return ans;
}

ll invmod(ll x)
{
    return binpowmod(x, MOD - 2);
}

ll divide(ll x, ll y)
{
    return mul(x, invmod(y));
}

int N = 2e5+10;
vll fact(N);

void precalc()
{
    fact[0] = 1;
    FE(i,1,N-1)
        fact[i] = mul(fact[i - 1], i);
}

ll C(ll n, ll k)
{
    if (n < k)
        return 0;
    if (n < 0 || k < 0) 
        return 0;

    return divide(fact[n], mul(fact[k], fact[n - k])); 
    //return mul( fact[n], mul( invmod(fact[k]), invmod(fact[n-k]) ) ) ; //Another way to do the same
}


signed main()
{
    fastIO;
    cini(n);
    cinv(cost, n);

    vvi gr(n+1), grrev(n+1);
    vi visited(n+1, 0);
    vi order, component;

    cini(m);
    FE(i,1,m)
    {
        cini2(x,y);
        gr[x].pb(y);
        grrev[y].pb(x);
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
        if(visited[i]==0)
            dfs1(i);
    }

    visited.assign(n+1, 0);

    reverse(all(order));

    int fincost = 0,  finways = 1;
    FA(ver, order)
    {
        if(!visited[ver])
        {
            dfs2(ver);

            int tempcost = INFL;
            map<int, int> mp;
            FA(node, component)
            {
                mp[cost[node]]++;
            }    
            component.clear();
            fincost += mp.begin()->fi;
            finways = mul(finways, mp.begin()->se);
        }
    }

    cout<<fincost<<" "<<finways;
    return 0;
}