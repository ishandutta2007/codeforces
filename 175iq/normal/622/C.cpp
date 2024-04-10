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
vi seg_tree_min(4*N);
vi seg_tree_Max(4*N);
vi arr(N);

void buildTreeMin(int si, int ss, int se)
{
    if(ss==se)
    {
        seg_tree_min[si] = arr[ss];
        return;  
    }

    int mid = (ss+se)/2;

    buildTreeMin(2*si, ss, mid);
    buildTreeMin(2*si+1, mid+1, se);

    seg_tree_min[si] = min(seg_tree_min[2*si], seg_tree_min[2*si+1]);

    return;
}

int queryMin(int si, int ss, int se, int qs, int qe)
{
    if(qs>se || ss>qe)
        return INF;

    if(ss>=qs && se<=qe)
        return seg_tree_min[si];

    int mid = (ss+se)/2;
    int lsum = queryMin(2*si, ss,  mid, qs, qe);
    int rsum = queryMin(2*si+1, mid+1, se, qs, qe);

    return min(lsum,rsum);
}

int queryMax(int si, int ss, int se, int qs, int qe)
{
    if(qs>se || ss>qe)
        return 0;

    if(ss>=qs && se<=qe)
        return seg_tree_Max[si];

    int mid = (ss+se)/2;
    int lsum = queryMax(2*si, ss,  mid, qs, qe);
    int rsum = queryMax(2*si+1, mid+1, se, qs, qe);

    return max(lsum,rsum);
}


void buildTreeMax(int si, int ss, int se)
{
    if(ss==se)
    {
        seg_tree_Max[si] = arr[ss];
        return;  
    }

    int mid = (ss+se)/2;

    buildTreeMax(2*si, ss, mid);
    buildTreeMax(2*si+1, mid+1, se);

    seg_tree_Max[si] = max(seg_tree_Max[2*si],seg_tree_Max[2*si+1]);

    return;
}

int main()
{   
    fastIO;
    cini2(n,m);
    vvi pos(1e6);
    FE(i,1,n)
    {
        cin>>arr[i];
        pos[arr[i]].pb(i);
    }

    buildTreeMin(1,1,n);
    // debug(seg_tree_min);
    // cout<<queryMin(1,1,n,1,2);
    buildTreeMax(1,1,n);
    // cout<<queryMax(1,1,n,1,2);

    function<int(int, int)> find_pos = [&](int x, int l)
    {
        auto it = lower_bound(all(pos[x]), l); 
        // if(it == pos[x].end())
        int posi = *it; 
        return posi; 
    };

    int mini, maxi;
    FE(i,1,m)
    {
        cini3(l,r,x);
        mini = queryMin(1,1,n,l,r);
        maxi = queryMax(1,1,n,l,r);
        debug(l,r,x, mini, maxi);
        if(mini == maxi)
        {
            if(mini == x)
                cout<<-1<<"\n";
            else
                cout<<find_pos(mini, l)<<"\n";
        }
        else
        {
            if(mini!=x)
                cout<<find_pos(mini, l)<<"\n";
            else if(maxi!=x)
                cout<<find_pos(maxi, l)<<"\n";
        }
    }

    return 0;
}