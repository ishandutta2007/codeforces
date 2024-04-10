#include "bits/stdc++.h"
using namespace std;

//Utility functions
#define pb push_back
#define sz size()
#define fi first
#define se second
#define all(c) (c).begin(),(c).end() 

//Constants
#define EPS 1e-8
#define INF 0x3f3f3f3f
#define MOD 1000000007 //998244353

//Printing
#define coutRV(a,L,R) FE(i,L,R) cout<<a[i]<<" \n"[i==R] ;
#define coutV(a) coutRV(a,0,a.size()-1)

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
#define vi vector<int>
#define vll vector<ll>
#define vd vector<double> 
#define vvi vector<vector<int> > //For UnGraph
#define vvpi vector<vector<pii> > //For DirGraph
#define vviwv(vecname, N, M, value) vector<vector<int> > vecname(N, vector<int> (M, value)) //For DP
#define vvlwv(vecname, N, M, value) vector<vector<ll> > vecname(N, vector<ll> (M, value)) //For DP  
#define pii pair<int,int>   
#define ll long long 
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

//Input 
#define cini(i) int i; cin>>i;
#define cini2(i,j) int i,j; cin>>i>>j;
#define cini3(i,j,k) int i,j,k; cin>>i>>j>>k;
#define cini4(i,j,k,l) int i,j,k,l; cin>>i>>j>>k>>l;
#define cinll(l) ll l; cin>>l;
#define cind(d) double d; cin>>d;
#define cins(s) string s; cin>>s;
#define cinv(a, n) vi a(n+1); FE(i,1,n) { cin>>a[i]; }
#define cinvll(a, n) vll a(n+1); FE(i,1,n) { cin>>a[i]; }
#define cinvd(a, n) vd a(n+1); FE(i,1,n) { cin>>a[i]; }

int N = 2e5+10;
vvi gr(N);
vi level(N);
vi countlevel(N);
vi parent(N); 
vi idx(N);

void dfs(int u, int prnt, int l)
{       
    level[u] =  l;
    debug(u, level[u]);
    FA(v, gr[u])
    {   
        if(v == prnt)
            continue;
        parent[v] = u;
        dfs(v,u,l+1);
    }
    return;
}

int main()                              
{                                                                                                  
    fastIO; 
    cini(n); 

    FE(i,1,n-1)
    {
        cini2(x,y);
        gr[x].pb(y);
        gr[y].pb(x);
    }

    cinv(a,n);
    FE(i,1,n)
        idx[a[i]] = i;

    dfs(1,-1,1);


    FE(i,1,n)
        countlevel[level[i]]++;

    int lvl = 1, curlvl, j, curlvlcnt = 0;
    for (int i = 1; i <=n; )
    {
        curlvl = lvl;
        curlvlcnt = 0;
        j = i;
        while(j <=n && level[a[j]]==curlvl)
        {
            curlvlcnt++;
            j++;
        }
        if(curlvlcnt!= countlevel[lvl])
        {
            //debug(curlvlcnt, lvl);
            cout<<"No";
            return 0;
        }

        i = j;
        lvl++;
    }
    
    int curr;
    int mxidxchildlst = 1, minidxchildlst = 1, mxidxchildcur,  minidxchildcur ;  
    FE(i,2,n)
    {
        curr = a[i];
        mxidxchildcur = -INF;
        minidxchildcur = INF;
        FA(v, gr[curr])
        {
            if(v==parent[curr])
                continue;
            debug(curr,v);
            mxidxchildcur = max(mxidxchildcur, idx[v]);
            minidxchildcur = min(minidxchildcur, idx[v]);
        }
        if(i==3)
        {
            debug(mxidxchildlst, minidxchildlst, mxidxchildcur, minidxchildcur);
        }
        if(minidxchildcur<=mxidxchildlst){
            debug(i, minidxchildcur, mxidxchildlst);
            cout<<"No";
            return 0;
        }
        minidxchildlst = minidxchildcur;
        mxidxchildlst = mxidxchildcur; 
    }
    cout<<"Yes";
    
    return 0;
}