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

struct frnd
{
    int x, k;
    vi listm;
    frnd(int xx, int kk)
    {
        x = xx, k = kk;
    }
    bool operator<(const frnd& other) const
    {
        return k > other.k;
    }
};

void solve()
{
    cini3(n, m, b);

    int val, t;
    vector<frnd> vec(n+1, frnd(0,0));
    FE(i,1,n)
    {
        cin>>vec[i].x>>vec[i].k>>t;
        FE(j,1,t)
        {
            cin>>val;
            --val;
            (vec[i].listm).pb(val);
        }
    }    

    sort(1+all(vec));

    // FE(i,1,n)
    // {
    //     debug(vec[i].x, vec[i].k);
    //     debug(vec[i].listm);
    // }
    
    // sort(1+all(vec));
    
    // debug("----------");
    
    // FE(i,1,n)
    // {
    //     debug(vec[i].x, vec[i].k);
    //     debug(vec[i].listm);
    // }

    // function<ll(int, int)> calc = [&](int pos, int pmask)
    // {   
    //     debug(pos, pmask);
    //     if(__builtin_popcount(pmask) == m)
    //         return 0ll;

    //     if(pos == n+1)
    //         return INFL;

    //     ll& ans = dp[pos&1][pmask];
    //     if(ans!=-1ll)
    //         return ans;

    //     int copy_mask = pmask;
    //     ll monitor_cost = 0ll;
    //     if(__builtin_popcount(copy_mask) == 0)
    //         monitor_cost = b*vec[pos].k;

    //     FA(que, vec[pos].listm)
    //         copy_mask |= (1<<que); 

    //     // ll take = monitor_cost + ((ll)vec[pos].x) + calc(pos+1, copy_mask);

    //     // ll not_take = calc(pos+1, pmask);
        
    //     return ans = min(monitor_cost + vec[pos].x + calc(pos+1, copy_mask), calc(pos+1, pmask));
    // };

    vector<vector<ll> > dp(2, vector<ll>((1<<m), INFL));

    dp[(1)&1][0] = 0;
    FE(pos, 1, n)
    {
        int que_mask = 0;
        FA(que, vec[pos].listm)
            que_mask |= (1<<que); 
        FE(msk, 0, (1<<m)-1)
        {
            int monitor_cost = 0;
            int copy_mask = msk;

            if(copy_mask == 0)
                monitor_cost = b*vec[pos].k;


            dp[(pos+1)&1][msk|que_mask] = min(monitor_cost + vec[pos].x + dp[(pos)&1][msk], dp[(pos+1)&1][msk|que_mask]);
            dp[(pos+1)&1][msk] = min(dp[(pos+1)&1][msk], dp[(pos)&1][msk]);
        }
    }

    debug(dp);

    int mini = INFL;
    FE(i,0,1)
        mini = min(mini, dp[i&1][(1<<m)-1]);

    debug(mini);
    if(mini < INFL)
        cout<<mini<<"\n";
    else
        cout<<"-1\n";

    return; 
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