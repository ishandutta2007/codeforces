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
#define INF (ll)2e9
 
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
#define vviwv(vecname, N, M, value) vector<vector<int> > vecname(N+1, vector<int> (M+1, value)) //For DP
#define vvlwv(vecname, N, M, value) vector<vector<ll> > vecname(N+1, vector<ll> (M+1, value)) //For DP  
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
 
int BLOCK = 700; //Keeping a constant value is fine

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

//1. To defeat anti hash tests
const ll TIME = chrono::high_resolution_clock::now().time_since_epoch().count();
const ll SEED = (ll)(new ll);
const ll RANDOM = TIME ^ SEED;
const ll MOD = (int)1e9+7;
const ll MUL = (int)1e6+3;

//1. First hash function. 
// struct chash{
//     ll operator()(ll x) const { return std::hash<ll>{}((x ^ RANDOM) % MOD * MUL); }
// };

// 2. Second hash function. 
// To defeat anti hash tests.
// See which of 1 or 2 works better for our case.

unsigned hash_f(unsigned x) {
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = (x >> 16) ^ x;
    return x;
}

struct chash {
    int operator()(int x) const { return hash_f(x); }
};

//Use it the same way as you use unordered_map
//While unordered_set contains the count() function, gp_hash_table does not. 
//Instead, you should use table.find(x) != table.end()

gp_hash_table<int, int, chash> fre;

struct query
{
    int i, l, r;
};
 
bool comp(query a, query b)
{
    if(a.l / BLOCK != b.l / BLOCK)
        return a.l/BLOCK < b.l/BLOCK;
 
    return a.r < b.r;
}

int main()
{
    fastIO;
    cini2(n, q);
    cinv(a, n);

    BLOCK = sqrt(n);

    // map<int, int> fre;
    
    vi ans(q+1);
    vector<query> Q(q+1);
    FE(i,1,q)
    {
        cin>>Q[i].l>>Q[i].r;
        Q[i].i = i;
    }

    sort(1+all(Q), comp);

    int tempans = 0; 
    function<void(int)> add = [&](int pos)
    {
        if(fre[a[pos]] == a[pos])
        {
            tempans--;        
            fre[a[pos]]++;
        }
        else
        {
            fre[a[pos]]++;   
            if(fre[a[pos]] == a[pos])
                tempans++;
        }
    };

    function<void(int)> remove = [&](int pos)
    {
        if(fre[a[pos]] == a[pos])
        {
            tempans--;        
            fre[a[pos]]--;
        }
        else
        {
            fre[a[pos]]--;   
            if(fre[a[pos]] == a[pos])
                tempans++;
        }
    };

    int curL = 1 , curR = 0;
    for(int i = 1; i <= q; i++)
    {
        int L = Q[i].l;
        int R = Q[i].r;
 
        while(curL > L)
            curL-- , add(curL);
 
        while(curR < R)
            curR++ , add(curR);
 
        while(curL < L)
            remove(curL) , curL++;
 
        while(curR > R)
            remove(curR) , curR--;
        
        ans[Q[i].i] = tempans;
    }
 
    FE(i, 1, q)
        cout<<ans[i]<<"\n";

    return 0;
}