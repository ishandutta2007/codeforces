#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define sz(x) (int)(x).size()
#define ll long long
#define ld long double
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define pii pair <int, int>
#define vi vector<int>
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()

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
const int MAX = 105;
ll p[MAX][MAX];
ll dp[MAX][MAX][MAX];  //minimum liters of paint to cover ith tree with color j using k changes so far
vi c;
int main(){
    fast_io();
    int n, m, k1;
    cin >> n >> m >> k1;
    f0r(i, n){
        int d;
        cin >> d;
        d--;
        c.eb(d);
    }
    f0r(i , n){
        f0r(j, m){
            cin >> p[i][j];
        }
    }
    f0r(i, 100){
        f0r(j, 100){
            f0r(k, 101){
                dp[i][j][k] = 1e15;
            }
        }
    }
    if(c[0] == -1){
        for(int i = 0; i<m; i++){
            dp[0][i][1] = p[0][i];
        }
    }
    else{
        dp[0][c[0]][1] = 0;
    }
    for(int i = 1; i<n; i++){
        if(c[i] == -1){
            for(int j = 0; j<m; j++){
                for(int k = 1; k<k1+1; k++){
                    f0r(pc, m){
                        if(j == pc){
                            dp[i][j][k] = min(dp[i-1][pc][k] + p[i][j], dp[i][j][k]);
                        }
                        else{
                            dp[i][j][k] = min(dp[i-1][pc][k-1] + p[i][j], dp[i][j][k]);
                        }

                    }
                }
            }
        }
        else{
            for(int j = 0; j<m; j++){
                for(int k = 1; k<k1+1; k++){
                    if(j!=c[i]){
                        dp[i][c[i]][k] =  min(dp[i-1][j][k-1],dp[i][c[i]][k]);
                    }
                    else{
                        dp[i][c[i]][k] = min(dp[i-1][j][k], dp[i][c[i]][k]);
                    }
                }

            }
        }
    }
    ll ans = 1e15;
    f0r(i, m){
        ans = min(ans, dp[n-1][i][k1]);
    }
    if(ans == 1e15){
        cout << -1;
        return 0;
    }
    cout << ans << endl;
    return 0;
}