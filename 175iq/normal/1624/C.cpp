// #include <bits/stdc++.h>
// using namespace std;
  
// //Utility functions
// #define pb push_back
// #define sz size()
// #define fi first
// #define se second
// #define all(c) (c).begin(),(c).end() 
   
// //For loops
// #define FE(i,a,b)  for(int i=a; i<=b; i++)
// #define FRE(i,b,a) for(int i=b; i>=a; i--)
// #define FA(x,cont) for(auto& x : cont)
 
// //For debug 
// // ----------------------------- (Debug) ------------------------------
// #define sim template < class c
// #define ris return * this
// #define dor > debug & operator <<
// #define eni(x) sim > typename enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
// sim > struct rge { c b, e; }; sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
// sim > auto dud(c* x) -> decltype(cerr << *x, 0); sim > char dud(...);
// struct debug {
// #ifdef LOCAL
// eni(!=) cerr << boolalpha << i; ris; }
// eni(==) ris << range(begin(i), end(i));}
// sim, class b dor(pair < b, c > d) {ris << "(" << d.first << ", " << d.second << ")";}
// sim dor(rge<c> d) {*this << "["; for (auto it = d.b; it != d.e; ++it) *this << ", " + 2 * (it == d.b) << *it; ris << "]";}
// #else
// sim dor(const c&) { ris; }
// #endif
// };
// vector<char*> tokenizer(const char* args) {
//     char *token = new char[111]; strcpy(token, args); token = strtok(token, ", ");
//     vector<char*> v({token});
//     while((token = strtok(NULL,", "))) v.push_back(token);
//     return reverse(v.begin(), v.end()), v;
// }
// void debugg(vector<char*>) { cerr << ""; }
// template <typename Head, typename... Tail>
// void debugg(vector<char*> args, Head H, Tail... T) {
//     debug() << " [" << args.back() << ": " << H << "] ";
//     args.pop_back(); debugg(args, T...);
// }
// #define harg(...) #__VA_ARGS__
// #ifdef LOCAL
// #define debug(...) { debugg(tokenizer(harg(LINE, __VA_ARGS__)),__LINE__, __VA_ARGS__); cerr << endl;}
// #else
// #define debug(...) { }
// #endif
// /// -----------------------------------------------------------------------
 
// ///------------------For Online test------------------ ///
// #define dbg(...) [](const auto&...x){ char c='='; cerr<<#__VA_ARGS__<<" ";((cerr<<exchange(c,',')<<" "<<x),...); cerr<<endl; }(__VA_ARGS__);
// ///------------------For Online test------------------ ///
 
// //Definitions 
// #define ll long long
// #define ld long double
// #define vi vector<int>
// #define vll vector<ll>
// #define vvi vector<vector<int> > //For UnGraph
// #define vvpi vector<vector<pii> > //For DirGraph
// #define vviwv(vecname, N, M, value) vector<vector<int> > vecname(N, vector<int> (M, value)) //For DP
// #define pii pair<int,int>   
// #define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
// //Input 
// #define cini(i) int i; cin>>i;
// #define cini2(i,j) int i,j; cin>>i>>j;
// #define cini3(i,j,k) int i,j,k; cin>>i>>j>>k;
// #define cini4(i,j,k,l) int i,j,k,l; cin>>i>>j>>k>>l;
// #define cins(s) string s; cin>>s; s = "#" + s;
// #define cinv(a, n) vi a(n+1); FE(i,1,n) { cin>>a[i]; }
 
// #define int ll
// #define INFI (int)2e9
// #define INFL (ll)7e18

// void solve()
// {
//     return;
// }
 
// signed main()
// {
//     fastIO; 
    
//     int T = 1;
//     // cin>>T;

//     FE(i,1,T)
//         solve();
    
//     return 0;
// }

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

    cini(n);
    cinv(a, n);

    vi b = a;

    vvi gr(2*n+2);

    FE(i,1,n)
    {
        while(b[i])
        {
            if(b[i] <= n)
                gr[b[i]+n].pb(i);

            b[i] /= 2;
        }
    }

    multimap<int, set<int> > ms;
    FE(i,n+1,2*n)
    {
        set<int> st;
        st.insert(i); //first val
        FA(val, gr[i])
            st.insert(val);

        ms.insert({st.sz, st}); 
    }

    debug(ms);

    vi is_pres(2*n+2, 0);
    FE(i,1,n)
    {
        auto it = *(ms.begin());
        int permval = *(it.se.rbegin());
        set<int> indxs = it.se;
        debug(permval, indxs);

        if(indxs.sz == 1)
        {
            debug("tus", permval);
            cout<<"NO\n";
            return;
        }

        is_pres[permval] = 1;
        auto it2 = indxs.begin();
        int fromidx = *(it2);

        debug(fromidx);

        ms.erase(ms.begin());

        FA(pr, ms)
        {
            set<int>& st = pr.se;
            st.erase(fromidx);
        }
    }

    FE(i, n+1, 2*n)
    {
        if(!is_pres[i])
        {
            cout<<"NO\n";
            return;
        }
    }

    cout<<"YES\n";
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