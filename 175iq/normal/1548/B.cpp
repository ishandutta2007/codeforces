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

ll gcd(ll a, ll b)
{
    return __gcd(abs(a), abs(b));
}

class SegTree
{
    public: 

    vll seg_tree;
    int n, siz, neutral_element;

    SegTree(int x)
    {           
        n = x;  // Storing a local copy of size of the array
        siz = 1;
        while(siz < x)
            siz *= 2;
        siz *= 2;

        // Set the neutral element. This should be the default value
        // of seg_tree array before buildTree too. 
        neutral_element = 0; 

        // Initializing seg_tree with default value i.e. neutral_element 
        FE(i, 1, siz)
            seg_tree.pb(neutral_element);
    }

    void buildTree(int si, int ss, int se, vi& arr)
    {
        if(ss==se)
        {
            seg_tree[si] = arr[ss];
            return;  
        }

        int mid = (ss+se)/2;

        buildTree(2*si, ss, mid, arr);
        buildTree(2*si+1, mid+1, se, arr);

        seg_tree[si] = gcd(seg_tree[2*si], seg_tree[2*si+1]);

        return;
    }

    void buildTree(vi& arr)
    {
        buildTree(1, 1, n, arr);
        return;
    }

    ll queryTree(int si, int ss, int se, int qs, int qe)
    {
        if(qs>se || ss>qe)
            return neutral_element;

        if(ss>=qs && se<=qe)
            return seg_tree[si];

        int mid = (ss+se)/2;
        ll lresult = queryTree(2*si, ss,  mid, qs, qe);
        ll rresult = queryTree(2*si+1, mid+1, se, qs, qe);

        return gcd(lresult, rresult);
    }

    ll queryTree(int qs, int qe)
    {
        return queryTree(1, 1, n, qs, qe);
    }
};

void solve()
{
    cini(n);
    cinv(a, n);

    if(n == 1)
    {
        cout<<"1\n";
        return;
    }
    vi d(n, 0);
    FE(i,1,n-1)
        d[i] = a[i+1] - a[i];

    SegTree segA(n-1);
    segA.buildTree(d);

    debug(d);
    int l = 1, ans = -1;
    FE(r, 1, n-1)
    {
        while(l <= r and segA.queryTree(l, r) == 1)
        {
            l++;
        }
        ans = max(ans, r-l+1);
    }
    if(ans >= 2)
    {
        cout<<ans+1<<"\n";
        return;
    }
    else
    {
        FE(i,1,n-1)
        {
            if(abs(a[i] - a[i+1]) >= 2)
            {
                cout<<2<<"\n";
                return;
            }
        }
    }
    cout<<"1\n"; 
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