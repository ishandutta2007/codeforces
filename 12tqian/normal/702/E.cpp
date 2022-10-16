#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define ld long double
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define pii pair <int, int>
#define vi vector<int>
#define f first
#define s second

#define f0r(i,a) for(int i=0;i<a;i++)
#define f1r(i,a,b) for(int i=a;i<b;i++)

#define read1(a) int a; scanf("%d", &a)
#define read2(a,b) int a,b; scanf("%d %d", &a, &b)
#define read3(a,b,c) int a,b,c; scanf("%d %d %d", &a, &b, &c)
#define read(n,arr) int arr[n]; f0r(i,n){ scanf("%d", &arr[i]); }
#define print1(a) printf("%d \n", a)
#define print2(a, b) printf("%d %d \n", a, b)
#define print3(a, b, c) printf("%d %d %d \n", a, b, c)
#define print(v) for (int i : v) { printf("%d ", i); } printf("\n")

#define debug printf("asdf\n");
#define newl printf("\n");
#define usaco(in, out) freopen(in, "r", stdin); freopen(out, "w", stdout);
void fast_io(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
}
void io(string taskname){
    string fin = taskname + ".in";
    string fout = taskname + ".out";
    const char* FIN = fin.c_str();
    const char* FOUT = fout.c_str();
    freopen(FIN, "r", stdin);
    freopen(FOUT, "w", stdout);
    fast_io();
}
const int MAX = 1e5 + 5;
const int LOG = 35;
static ll adj[MAX];
static ll w[MAX];
static pair<ll, ll> dp[MAX][LOG];
static pair<ll, ll> dp1[MAX][LOG];
static ll n, k;
void preprocess(){
    f0r(i, n){
        dp[i][0] = mp(adj[i], w[i]);
        dp1[i][0] = mp(adj[i], w[i]);
    }
    f1r(j ,1, LOG){
        f0r(i, n){
            ll x = dp[dp[i][j-1].f][j-1].f;
            ll y = 0;
            y += dp[i][j-1].s;
            y += dp[dp[i][j-1].f][j-1].s;
            dp[i][j] = mp(x, y);
            ll z = min(dp1[i][j-1].s, dp1[dp1[i][j-1].f][j-1].s);
            dp1[i][j] = mp(x, z);
        }
    }
}
static ll query(ll i, ll k){
    ll ans = 0;
    ll idx = 0;
    ll cur = i;
    while(k >0){
        if(k%2 == 1){
            ans += dp[cur][idx].s;
            cur = dp[cur][idx].f;
        }
        k  = (k >> 1);
        idx += 1;
    }
    return ans;
}
static ll query1(ll i, ll k){
    ll ans = 1e9;
    ll idx = 0;
    ll cur = i;
    while(k >0){
        if(k%2 == 1){
            ans = min(ans, dp1[cur][idx].s);
            cur = dp1[cur][idx].f;
        }
        k  = (k >> 1);
        idx += 1;
    }
    return ans;
}
int main(){
    cin >> n >> k;
    f0r(i, n){
        ll d;
        cin >> d;
        adj[i] = d;
    }
    f0r(i, n){
        ll d;
        cin >> d;
        w[i] = d;
    }
    preprocess();
    f0r(i, n){
        cout << query(i, k) <<  " " << query1(i, k) << endl;
    }
    return 0;
}