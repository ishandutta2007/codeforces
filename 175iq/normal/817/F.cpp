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
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
 
//Definitions 
#define ll long long
#define ld long double
#define vi vector<int>
#define vll vector<ll>
#define vd vector<double> 
#define vvi vector<vector<int> > //For UnGraph
#define vvpi vector<vector<pii> > //For DirGraph
#define vviwv(vecname, N, M, value) vector<vector<int> > vecname(N, vector<int> (M, value)) //For DP
#define vvlwv(vecname, N, M, value) vector<vector<ll> > vecname(N, vector<ll> (M, value)) //For DP  
#define pii pair<int,int>   
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
//Input 
#define cini(i) int i; cin>>i;
#define cini2(i,j) int i,j; cin>>i>>j;
#define cini3(i,j,k) int i,j,k; cin>>i>>j>>k;
#define cini4(i,j,k,l) int i,j,k,l; cin>>i>>j>>k>>l;
#define cinll(l) ll l; cin>>l;
#define cind(d) double d; cin>>d;
#define cins(s) string s; cin>>s; s = "#" + s;
#define cinv(a, n) vi a(n+1); FE(i,1,n) { cin>>a[i]; }
#define cinvd(a, n) vd a(n+1); FE(i,1,n) { cin>>a[i]; }
#define cinvll(a, n) vll a(n+1); FE(i,1,n) { cin>>a[i]; }

// Constants
#define int ll
#define MOD 1e9+7
#define INF 2e9
  
class SegTree
{
    public: 
 
    vector<int> seg_tree;
    vector<int> lazy_tree1, lazy_tree2;
    int n, siz, NO_OPERATION1 = -1, NO_OPERATION2 = 0, OPERATION2 = 1;
    int neutral_element;

    void apply_modify_operation_lazy_tree1(ll& a, ll b)
    {
        if(b != NO_OPERATION1)
            a = b;
        return;
    }
 
    void apply_modify_operation_lazy_tree2(ll& a, ll b)
    {
        if(b == NO_OPERATION2)
            return;
        else
        {
            if(a == NO_OPERATION2)
                a = OPERATION2;
            else
                a = NO_OPERATION2;
        }
    }
 
    void apply_modify_operation_seg_tree1(ll& a, int val, int len)
    {
        if(val == NO_OPERATION1)
            return;
        else
            a = val*len;
        return; 
    }

    void apply_modify_operation_seg_tree2(ll& a, int val, int len)
    {
        if(val == NO_OPERATION2)
            return;
        else
            a = len - a;  
        return; 
    }
 
    void propagate(int si, int ss, int se)
    {
        if(ss == se)
            return;
    
        if(lazy_tree1[si] != NO_OPERATION1)
        {
            apply_modify_operation_lazy_tree1(lazy_tree1[2*si], lazy_tree1[si]);
            apply_modify_operation_lazy_tree1(lazy_tree1[2*si+1], lazy_tree1[si]);        
                        
            int mid = (ss+se)/2;
            apply_modify_operation_seg_tree1(seg_tree[2*si], lazy_tree1[si], mid-ss+1);  //IMP
            apply_modify_operation_seg_tree1(seg_tree[2*si+1], lazy_tree1[si], se-mid);  //IMP
            lazy_tree1[si] = NO_OPERATION1;
 
            lazy_tree2[2*si] = NO_OPERATION2;
            lazy_tree2[2*si+1] = NO_OPERATION2;
        }
 
        apply_modify_operation_lazy_tree2(lazy_tree2[2*si], lazy_tree2[si]);
        apply_modify_operation_lazy_tree2(lazy_tree2[2*si+1], lazy_tree2[si]);            
 
        int mid = (ss+se)/2;
        apply_modify_operation_seg_tree2(seg_tree[2*si], lazy_tree2[si], mid-ss+1);  //IMP
        apply_modify_operation_seg_tree2(seg_tree[2*si+1], lazy_tree2[si], se-mid);  //IMP
        lazy_tree2[si] = NO_OPERATION2;
 
        return;    
    }
 
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
        {
            seg_tree.pb(neutral_element);
            lazy_tree1.pb(NO_OPERATION1);
            lazy_tree2.pb(NO_OPERATION2);
        }
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
 
    void updateTree(int si, int ss, int se, int qs, int qe, int x, int type)
    {
        propagate(si, ss, se);        
        
        if(qs>se || ss>qe)
            return;
 
        if(ss>=qs && se<=qe)
        {
            if(type == 1)
            {
                apply_modify_operation_lazy_tree1(lazy_tree1[si], x);
                lazy_tree2[si] = NO_OPERATION2;
                apply_modify_operation_seg_tree1(seg_tree[si], x, se-ss+1);                 
            }
            else
            {
                apply_modify_operation_lazy_tree2(lazy_tree2[si], OPERATION2);
                apply_modify_operation_seg_tree2(seg_tree[si], OPERATION2, se-ss+1);                 
            }
            return;
        }
 
        int mid = (ss+se)/2;
 
        updateTree(2*si, ss, mid, qs, qe, x, type);
        updateTree(2*si+1, mid+1, se, qs, qe, x, type);
 
        seg_tree[si] = seg_tree[2*si] + seg_tree[2*si+1];
 
        return;
    }

    void updateTree(int qs, int qe, int x, int type)
    {
        updateTree(1, 1, n, qs, qe, x, type);
        return;
    }
 
    int queryTree(int si, int ss, int se)
    {
        propagate(si, ss, se);
 
        if(ss == se){
            return ss;
        }

        int mid = (ss+se)/2;
        if(seg_tree[2*si] < mid-ss+1)
            return queryTree(2*si, ss, mid);
        else
            return queryTree(2*si+1, mid+1, se);
    }
 
    int queryTree()
    {
        return queryTree(1, 1, n);
    }
};
 
void solve()
{
    cini(q);
    vvi query;
    while(q--)
    {
        cini3(t, l ,r);
        vi temp = {t, l ,r};
        query.pb(temp);
    }

    map<int, int> mp, mprev;
    mp[1] = 1;
    FA(x, query)
    {
        mp[x[1]] = 1;
        mp[x[2]] = 1;
        mp[x[2]+1] = 1;
    }

    int num = 1;
    FA(y, mp)
    {
        mp[y.fi]   = num;
        mprev[num] = y.fi;
        num++;
    }

    int n = 2e5+10; 
    vi arr(n+10, 0);
    
    SegTree segA(n);
    segA.buildTree(arr);

    debug(mp);
    debug(mprev);
    FA(x, query)
    {
        if(x[0] == 1)
        {
            debug("a");
            segA.updateTree(mp[x[1]], mp[x[2]], 1, 1);
        }
        else if(x[0] == 2)
        {
            debug("b");
            segA.updateTree(mp[x[1]], mp[x[2]], 0, 1);
        }
        else
        {
            debug("c");
            segA.updateTree(mp[x[1]], mp[x[2]], 1, 2);
        }
        cout<<mprev[segA.queryTree()]<<"\n";
    }

    return;
}

signed main()
{
    fastIO;
    int t = 1;
    // cin>>t; 

    FE(i, 1, t)
        solve();

    return 0;
}