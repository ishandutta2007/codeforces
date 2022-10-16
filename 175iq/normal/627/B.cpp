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

ll n, k, a, b, q;

class SegTree
{
    public: 
    vll seg_tree;
    vll arr;

    SegTree(int N)
    {   
        FE(i,1,4*N)
            seg_tree.pb(0);

        FE(i,1,N)
            arr.pb(0);
    }

    void buildTree(int si, int ss, int se)
    {
        if(ss==se)
        {
            seg_tree[si] = arr[ss];
            return;  
        }

        int mid = (ss+se)/2;

        buildTree(2*si, ss, mid);
        buildTree(2*si+1, mid+1, se);

        seg_tree[si] = seg_tree[2*si] + seg_tree[2*si+1];

        return;
    }

    void updateTree(int si, int ss, int se, int qi)
    {
        if(ss==se)
        {
            seg_tree[si] = arr[ss];
            return;
        }

        int mid = (ss+se)/2;

        if(qi <= mid)
            updateTree(2*si, ss, mid, qi);
        else
            updateTree(2*si+1, mid+1, se, qi);

        seg_tree[si] = seg_tree[2*si] + seg_tree[2*si+1];

        return;
    }

    ll queryTree(int si, int ss, int se, int qs, int qe)
    {
        if(qs>se || ss>qe)
            return 0;

        if(ss>=qs && se<=qe)
            return seg_tree[si];

        int mid = (ss+se)/2;
        ll lsum = queryTree(2*si, ss,  mid, qs, qe);
        ll rsum = queryTree(2*si+1, mid+1, se, qs, qe);

        return lsum + rsum;
    }
};

int main()
{
    fastIO;
    cin>>n>>k>>a>>b>>q;

    int N = 2e5+10;
    SegTree segA(N), segB(N);

    while(q--)
    {
        cini(qi);
        if(qi == 1)
        {
            cini2(di, oi);
            segB.arr[di] = min((ll)b, (ll)(segB.arr[di] + oi));
            segB.updateTree(1, 1, n, di);

            segA.arr[di] = min((ll)a, (ll)(segA.arr[di] + oi));
            segA.updateTree(1, 1, n, di);
        }
        else
        {
            cini(pi);
            ll ansB, ansA;
            if(pi == 1)
                ansB = 0;
            else
                ansB = segB.queryTree(1, 1, n, 1, pi-1);

            if(pi + k - 1 == n)
                ansA = 0;
            else
                ansA = segA.queryTree(1, 1, n, pi+k, n);
            cout<<ansA+ansB<<"\n";
        }
    }
    return 0;
}