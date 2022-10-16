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
 
using namespace std;
const int inf = 1e9;
const int mx = 10;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
ll rnd(ll x=0, ll y=inf) {return (rng() % (y-x +1)) + x;};
 
namespace generator{
    ll get_num(ll a = 0 , ll b = inf){
        return rnd(a,b);
    }
    string get_string(int len = -1,bool lowercase_only = true){
        if(len==-1){
            len = rnd(1,mx);
        }
        string s(len,'0');
        for(int i = 0; i < len; i++)
            s[i] = (rnd(0,25) + 'a');
        if(lowercase_only) return s;
        for(auto&i:s){
            if(rng()&1) i^=32; // swap case (make c to C)
        }
        return s;
    }
    template<typename T>
    vector<T> get_array(int len = -1 , T a = 0,T b = inf){
        if(len==-1){
            len = rnd(1,mx);
        }
        vector<T> s(len);
        for(int i = 0; i < len; i++)
            s[i] = (rnd(a,b));
        return s;
    }
    vector<pair<int, int>> get_tree(int n = -1){
        if(n==-1) n = rnd(1,mx);
        vector<pair<int, int>> res(n-1);
        for(int i = 2; i <= n; i++){
            int u = i , v = rnd(1 , i-1);
            if(rng()&1) swap(u,v);
            res[i-2] = {u,v};
        }
        shuffle(res.begin() , res.end() , rng);
        return res;
    }
    vector<pair<int, int>> get_simple_graph(int n , int m , bool connected = true){
        vector<pair<int, int>> res;
        set<pair<int , int>> edge_set;
        assert(2*m <= 1ll*n*(n-1)); // maximum condition for edge
        if(connected){
            assert(m >= n-1); // minimum edges of connected graph
            res = get_tree(n);
            for(auto i:res) edge_set.insert(i);
            res.clear();
            for(int i = n; i <= m; i++){
                label:
                int u = rnd(1,n);
                int v = rnd(1,n);
                if(u==v or edge_set.count({u,v}) or edge_set.count({v,u})) goto label;
                else{
                    edge_set.insert({u,v});
                }
            }
        }
        else{
            for (int i = 1; i <= m; ++i)
            {
                label2:
                int u = rnd(1,n);
                int v = rnd(1,n);
                if(u==v or edge_set.count({u,v}) or edge_set.count({v,u})) goto label2;
                else{
                    edge_set.insert({u,v});
                }
            }
        }
        for(auto i:edge_set){
            res.push_back(i);
        }
        shuffle(res.begin() , res.end() , rng);
        return res;
    }
};
using namespace generator;
/*
    -> get_num (a , b); // gives a random number between [a,b] if a , b given. otherwise get_num() gives a random_number between 0 and 10**18;
    -> get_string(l , bool lowercase_only = true) gives a string of length , (by default lowercase you can change that by calling get_string(len,false)); 
    -> get_array(len , min_num_of_array , max_num_of_array) note that this returns a vector;
    -> get_tree(n) gives a tree of n nodes (list of edges)
    -> get_simple_graph(nodes, edges , bool  connected = 1) // you can change connected/disconnected option too. (list of edges)
*/
 
 
void solve()
{
    set<int> st;
    cini(n);
    cinv(a, n);
 
    sort(1+all(a));
    FE(i,1,n)
        st.insert(a[i]);
 
    int cnt = 0;
    int maxi = *st.rbegin();
    int mini = *st.begin();
 
    // if(mini == 1 or mini == 2)
    // {
    //     FE(i,1,n/2)
    //     {
    //         cout<<a[i+1]<<" "<<mini<<"\n";
    //     }
    //     return;
    // }
    FE(i,1,n-1)
    {
        if(cnt < n/2 and (st.count(a[i+1]%mini) == 0))
        {
            cout<<a[i+1]<<" "<<mini<<"\n";
            cnt++;
        }
    }
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