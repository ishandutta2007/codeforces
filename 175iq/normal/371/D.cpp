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
#define INF 2e9
 
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
#define cins(s) string s; cin>>s; s = "#" + s;
#define cinv(a, n) vi a(n+1); FE(i,1,n) { cin>>a[i]; }
#define cinvd(a, n) vd a(n+1); FE(i,1,n) { cin>>a[i]; }
#define cinvll(a, n) vll a(n+1); FE(i,1,n) { cin>>a[i]; }

int N = 2e5+10;
vi parent(N), siz(N), nxt(N);

void init(int n) 
{
    // We are making nodes from [1,n]
    FE(v,1,n)
    {
        parent[v] = v;
        siz[v] = 1;
        nxt[v] = v+1;
    }
    return;
}

int find_set(int v) 
{
    if(v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) 
{
    a = find_set(a);
    b = find_set(b);
    if(a != b) 
    {
        if (siz[a] < siz[b])
            swap(a, b);

        parent[b] = a;
        siz[a] += siz[b];
        debug(nxt[a], nxt[b]);
        nxt[a] = max(nxt[a], nxt[b]);
        nxt[b] = max(nxt[a], nxt[b]);
    }
}

void solve()
{
    cini(n);
    cinv(a,n);

    vi fill(n+1, 0);
    vi actual(n+1, 0);

    init(n+1);
    cini(q);
    while(q--)
    {
        cini(type);
        if(type == 1)
        {
            cini2(p, x);
            while(x)
            {
                if(p == n+1)
                {
                    x = 0;
                }
                else if(!fill[p])
                {
                    int prev = actual[p];
                    actual[p] = min(a[p], actual[p] + x);
                    if(actual[p] == a[p])
                    {
                        fill[p] = 1;
                        if(p-1 <= n and fill[p-1])
                            union_sets(p, p-1);
                        x -= (a[p] - prev);
                        p = nxt[find_set(p)];
                    }
                    else
                    {
                        x = 0;
                    }
                }
                else if(fill[p])
                {
                    p = nxt[find_set(p)];
                }
            }
        }
        else
        {
            cini(k);
            cout<<actual[k]<<"\n";
        }
    }

    return; 
}

signed main()
{
    fastIO;
    int t = 1;
    // cin>>t;    
    while(t--)
        solve();
    return 0;
}