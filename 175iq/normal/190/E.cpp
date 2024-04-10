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
 
// #define int ll
#define INFI (int)2e9
#define INFL (ll)9e18
 
// typedef pair<int, int> pair;
 
// struct pair_hash
// {
//     template <class T1, class T2>
//     std::size_t operator() (const std::pair<T1, T2> &pair) const
//     {
//         return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
//     }
// };

// typedef std::pair<std::string,std::string> pair;
 
// struct pair_hash
// {
//     template <class T1, class T2>
//     std::size_t operator() (const std::pair<T1, T2> &pair) const
//     {
//         return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
//     }
// };
 
// int main()
// {
//     std::unordered_map<pair,int,pair_hash> unordered_map =
//     {
//         {{"C++", "C++11"}, 2011},
//         {{"C++", "C++14"}, 2014},
//         {{"C++", "C++17"}, 2017},
//         {{"Java", "Java 7"}, 2011},
//         {{"Java", "Java 8"}, 2014},
//         {{"Java", "Java 9"}, 2017}
//     };
 
//     for (auto const &entry: unordered_map)
//     {
//         auto key_pair = entry.first;
//         std::cout << "{" << key_pair.first << "," << key_pair.second << "}, "
//                   << entry.second << '\n';
//     }
 
//     return 0;
// }

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

const ll TIME = chrono::high_resolution_clock::now().time_since_epoch().count();
const ll SEED = (ll)(new ll);
const ll RANDOM = TIME ^ SEED;
const ll MOD = (int)1e9+7;
const ll MUL = (int)1e6+3;

// // (1) First hash function. 
// struct chash{
//     ll operator()(ll x) const { return std::hash<ll>{}((x ^ RANDOM) % MOD * MUL); }
// };

// // (2) Second hash function. 
// // To defeat anti hash tests.
// // See which hash function among (1) or (2) works better for our case.
// unsigned hash_f(unsigned x) {
//     x = ((x >> 16) ^ x) * 0x45d9f3b;
//     x = ((x >> 16) ^ x) * 0x45d9f3b;
//     x = (x >> 16) ^ x;
//     return x;
// }

// struct chash {
//     int operator()(int x) const { return hash_f(x); }
// };

// //Use it the same way as you use unordered_map
// //While unordered_set contains the count() function, gp_hash_table does not. 
// //Instead, you should use table.find(x) != table.end()

// gp_hash_table<int, int, chash> table;


struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(pair<uint64_t,uint64_t> x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x.first + FIXED_RANDOM)^(splitmix64(x.second + FIXED_RANDOM) >> 1);
    }
};


void solve()
{   
    cini2(n, m);
    // unordered_set<pair, pair_hash> 
    gp_hash_table<pii, int, custom_hash> st;
    // unordered_set<pair<int, int>,  custom_hash> st;
    FE(i,1,m)
    {
        cini2(u, v);
        st[{u, v}] = 1;
        st[{v, u}] = 1;
    }

    set<int> unvisited;
    FE(i,1,n)
        unvisited.insert(i);

    vvi arr(n+1);
    int ans = 0;
    function<void(int)> dfs = [&](int u)
    {
        unvisited.erase(u);
        arr[ans].pb(u);
        auto it = unvisited.begin();
        while(it != unvisited.end())        
        {
            int v = *it;
            if(st.find({u, v}) == st.end())
            {
                dfs(v);   
            }
            it = unvisited.upper_bound(v);
        }
        return; 
    };

    FE(i,1,n)
    {
        if(unvisited.count(i))
        {
            dfs(i);
            ans++;
        }
    }

    cout<<ans<<"\n";
    FE(i,0,ans-1)
    {
        cout<<arr[i].sz<<" ";
        FA(v, arr[i]){
            cout<<v<<" ";
        }
        cout<<"\n";        
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