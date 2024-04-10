#include <bits/stdc++.h>
using namespace std;
 
//Utility functions
#define pb push_back
#define sz size()
#define fi first
#define se second
#define all(c) (c).begin(),(c).end() 
 
//Constants
#define EPS 1e-6
#define INF INT_MAX
 
//Printing
#define coutRV(a,L,R) FE(i,L,R) cout<<a[i]<<" \n"[i==R] ;
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
#define cins(s) string s; cin>>s; s = "#"+s;
#define cinv(a, n) vi a(n+1); FE(i,1,n) { cin>>a[i]; }
#define cinvd(a, n) vd a(n+1); FE(i,1,n) { cin>>a[i]; }
#define cinvll(a, n) vll a(n+1); FE(i,1,n) { cin>>a[i]; }

int N = 2e5+10;
vll seg_tree(4*N);
vll arr(N);
int should;

void buildTree(int si, int ss, int se, int level)
{
    debug(si, ss, se);
    if(ss==se)
    {
        seg_tree[si] = arr[ss];
        return;  
    }

    int mid = (ss+se)/2;

    buildTree(2*si, ss, mid,level+1);
    buildTree(2*si+1, mid+1, se,level+1);

    if((level&1) == should)
        seg_tree[si] = (seg_tree[2*si])|(seg_tree[2*si+1]);
    else
        seg_tree[si] = (seg_tree[2*si])^(seg_tree[2*si+1]);

    debug(si, ss, se, seg_tree[si], seg_tree[2*si], seg_tree[2*si+1]);

    return;
}

void updateTree(int si, int ss, int se, int qi, int level)
{
    if(ss==se)
    {
        seg_tree[si] = arr[ss];
        return;
    }

    int mid = (ss+se)/2;

    if(qi <= mid)
        updateTree(2*si, ss, mid, qi, level+1);
    else
        updateTree(2*si+1, mid+1, se, qi, level+1);

    if((level&1) == should)
        seg_tree[si] = (seg_tree[2*si])|(seg_tree[2*si+1]);
    else
        seg_tree[si] = (seg_tree[2*si])^(seg_tree[2*si+1]);

    return;
}

ll queryTree(int si, int ss, int se, int qs, int qe, int level)
{
    if(qs>se || ss>qe)
    {
        if((level&1) == should)
            return 0;
        else
            return 1;
    }

    if(ss>=qs && se<=qe)
        return seg_tree[si];

    int mid = (ss+se)/2;
    ll lsum = queryTree(2*si, ss,  mid, qs, qe, level+1);
    ll rsum = queryTree(2*si+1, mid+1, se, qs, qe, level+1);

    if((level&1) == should)
        return lsum|rsum;
    else
        return lsum^rsum;
}

int main()
{
    fastIO;
    cini2(n,m);
            
    should = n&1;
    // debug(n,m,should);
    int N = (int)(pow(2,n));    
    FE(i,1,N)
        cin>>arr[i];

    buildTree(1, 1, N, 1);
    // debug(seg_tree);
    // FE(i,1,40)
    //     cout<<seg_tree[i]<<" ";
    // coutRV(seg_tree, 1, 20);

    while(m--)
    {
        cini2(i, v);
        arr[i] = v;
        updateTree(1,1,N,i,1);             //assuming 1 based indexing

        cout<<queryTree(1, 1, N, 1, N,1)<<"\n";
    }
    return 0;
}