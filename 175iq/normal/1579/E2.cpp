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
 
ll MOD = 1e9+7;

map<int, int> compress(vector<int> &a)
{
    int order = 0;
    map<int, int> M;
    map<int, int> MpRev;
    int n = a.sz;
    int arbitrary_val = 1;         ///We can put any value here, doesn't matter

    FE(i,1,n-1)
        M[a[i]] = arbitrary_val;   /// Taking all unique elements

    debug(M);
    FA(x, M) 
        M[x.fi] = ++order;         /// Assign value for unique elements

    debug(M);

    FE(i,1,n-1)
    {
        MpRev[M[a[i]]] = a[i];
        a[i] = M[a[i]];            /// Assign value for array
    }
    debug(a);
    debug(M, MpRev);
    return MpRev;
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

        seg_tree[si] = seg_tree[2*si] + seg_tree[2*si+1];

        return;
    }

    void buildTree(vi& arr)
    {
        buildTree(1, 1, n, arr);
        return;
    }

    void updateTree(int si, int ss, int se, int qi, int v)
    {
        if(ss==se)
        {
            seg_tree[si] = v;
            return;
        }

        int mid = (ss+se)/2;

        if(qi <= mid)
            updateTree(2*si, ss, mid, qi, v);
        else
            updateTree(2*si+1, mid+1, se, qi, v);

        seg_tree[si] = seg_tree[2*si] + seg_tree[2*si+1];

        return;
    }

    void updateTree(int qi, int v)
    {
        updateTree(1, 1, n, qi, v);
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

        return lresult + rresult;
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

    map<int, int> rev = compress(a);

    deque<int> dq; 
    SegTree segA(n);
    FE(i,1,n)
    {
        int gr = segA.queryTree(a[i], n);
        int sm = segA.queryTree(1, a[i]);
        if(gr >= sm)
        {
            dq.push_front(rev[a[i]]);
        }
        else
            dq.pb(rev[a[i]]);

        int zz = segA.queryTree(a[i], a[i]);
        segA.updateTree(a[i], zz+1);
    }

    vi p; 
    p.pb(0);
    FA(y, dq)
        p.pb(y);

    compress(p);

    SegTree segB(n);

    int ans  = 0;    
    FE(i,1,n)
    {
        int x  = p[i];
        ans    += segB.queryTree(x+1, n);
        int zz = segB.queryTree(x, x);
        segB.updateTree(x, zz+1);
    }
    cout<<ans<<"\n";
    return; 
}              

signed main()
{
    fastIO;
 
    int T = 1;
    cin>>T;
    
    FE(t,1,T)
    {
        // cout<<"Case #"<<t<<": "; 
        solve();
    }
 
    return 0;
}