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
const int MAX = 55;
//using the ith element with j elmeents
static int dp[MAX][MAX];
vector<int> a;
int main(){
    fast_io();
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    f0r(i, n){
        int x = s[i] - 'a'+1;
        a.eb(x);
    }
    sort(a.begin(), a.end());
    for(int i = 0; i<n; i++){
        dp[i][1] = a[i];
        //cout << a[i] << endl;
    }

    for(int i = 1; i<n;i++){
        for(int w = 2; w<= k; w++){
            for(int j = 0; j<= i; j++){
                if(a[i] -a[j] <= 1){
                    continue;
                }
                if(dp[j][w-1] == 0){
                    continue;
                }
                if(dp[i][w] == 0){
                    dp[i][w] = dp[j][w-1] + a[i];
                    continue;
                }
                dp[i][w] = min(dp[i][w], dp[j][w-1] + a[i]);
            }
        }

    }
    int mn = 1e5;
    for(int i = 0; i<n; i++){
        if(dp[i][k] != 0 ){
            mn = min (mn, dp[i][k]);
        }
    }
    if(mn == 1e5){
        cout << -1;
        return 0;
    }
    cout << mn << endl;
    return 0;
}