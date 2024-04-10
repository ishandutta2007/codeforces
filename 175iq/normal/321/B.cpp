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

void sovle()
{
    cini2(n, m);
    debug(n, m);

    vi jatt;
    jatt.pb(-1);
    
    vi jdef;
    jdef.pb(-1);

    vi catt(m+1);

    FE(i,1,n)
    {
        cins(s);
        cini(x);
        if(s == "#ATK")
            jatt.pb(x);
        else
            jdef.pb(x);
    }

    int n1 = jatt.sz-1; 
    int n2 = jdef.sz-1; 
    FE(i,1,m)
        cin>>catt[i];

    sort(1+all(jatt));
    sort(1+all(jdef));
    sort(1+all(catt));

    int dp[105][105][105][2];
    memset(dp, -1, sizeof(dp));

    debug(jatt, jdef, catt);

    function<int(int, int, int, bool)> calc = [&](int ca, int ja, int jd, bool kill_all)
    {
        if(ca == m+1)
        {
            if(kill_all)
            {
                if(ja <= n1 or jd<= n2)
                    return -INFL;
                else
                    return 0ll;
            }
            else
                return 0ll;
        }

        // if(ja > n1 and jd > n2)
        //     return catt[ca] + calc(ca+1, ja, jd, kill_all);

        // // if(jd > n2)
        // // {
        //     if(catt[ca] >= jatt[ja])
        //         return catt[ca]-jatt[ja] + calc(ca+1, ja+1, jd, kill_all);
        //     else
        //         return calc(ca+1, ja, jd, kill_all);
        // }

        // if(ja > n1)
        //     return 0ll;

        int& ans = dp[ca][ja][jd][kill_all];
        if(ans!=-1)
            return ans;

        ans = -INFL;

        //Assume everyone is dead and move to next one
        ans = max(ans, catt[ca] + calc(ca+1, ja, jd, 1));

        //attack attack card
        if(ja <= n1 and catt[ca] >= jatt[ja])
            ans = max(ans, catt[ca]-jatt[ja] + calc(ca+1, ja+1, jd, kill_all));

        //attack defense card
        if(jd<= n2 and catt[ca] > jdef[jd])
            ans = max(ans, calc(ca+1, ja, jd+1, kill_all));

        // skip this card
        ans = max(ans, calc(ca+1, ja, jd, kill_all));
        return ans;
    };

    cout<<max(calc(1, 1, 1, 0), calc(1, 1, 1, 1));
        
    return;
}
 
signed main()
{
    fastIO; 
    
    int T = 1;
    // cin>>T;
    
    FE(i,1,T)
        sovle();
    
    return 0;
}