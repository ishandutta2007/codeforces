#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
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
vector<ll> a;
vector<ll> b;
const int MAX = 3e5 + 5;
static ll dp[MAX][2];
static ll dp1[MAX];
static ll dp2[MAX];
static ll p[MAX];
static ll ans[MAX][2];
int main(){
    fast_io();
    int n;
    cin >> n;
    f0r(i, n){
        ll d;
        cin >> d;
        a.eb(d);
    }
    f0r(i, n){
        ll d;
        cin >> d;
        b.eb(d);
    }
    //sum from i to the end
    p[n-1] = a[n-1] + b[n-1];
    for(int i = n-2; i>=0 ; i--){
        p[i] = p[i+1] + a[i] + b[i];
    }
    f0r(i, n){
        dp[0][0] += i*a[i];
    }
    for(int i = n-1; i>= 0; i--){
        dp[0][0] += (n + n-1- i)*b[i];
    }
    f1r(i, 1, n){
        dp[i][0] = dp[i-1][0] - p[i] - (2*n - 2*(i-1)-1)*b[i-1];
    }
    f0r(i, n){
        dp[0][1] += i*b[i];
    }
    for(int i = n-1; i>= 0; i--){
        dp[0][1] += (n + n-1- i)*a[i];
    }
    f1r(i, 1, n){
        dp[i][1] = dp[i-1][1] - p[i] - (2*n - 2*(i-1)-1)*a[i-1];
    }
    dp1[0] = b[0];
    for(int i = 1; i<n; i++){
        if(i%2 == 0){
            dp1[i] = dp1[i-1] + (2*i)*a[i] + (2*i+1)*b[i];
        }
        else{
            dp1[i] = dp1[i-1] + (2*i)*b[i] + (2*i+1)*a[i];
        }
    }

    ll ans = dp1[n-1];
    ans = max(ans, dp[0][0]);
    for(int i = 1; i<n-1; i++){
        ll fin;
        if(i%2 == 0){
            fin = dp1[i-1];
            fin += dp[i][0];
            fin += p[i]*(2*i);
            ans = max(ans, fin);
        }
        if(i%2 == 1){
            fin = dp1[i-1];
            fin += dp[i][1];
            fin += p[i]*(2*i);
            ans = max(ans, fin);
        }
    }
    cout << ans << endl;
    return 0;
}