#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <queue>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <random>
#include <functional>

using namespace std;

#define F first
#define S second
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define dbv(a) cerr << #a << ": "; for (auto& xxxx: a) cerr << xxxx << " "; cerr << endl;
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)a.size()
#define pw(n) (1ll << (n))
#define equal equalll
#define less lesss

typedef double dbl;
typedef long long ll;
const int N = -1;
const int INF = 1.01e9;
typedef vector<int> vi;
const int MOD = 1e9 + 7;



int main() {
#ifdef HOME 
    assert(freopen("in", "r", stdin));
#endif
    int n;
    scanf("%d", &n);
    vector<vector<int>> a(n, vector<int> (n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    vector<vector<ll>> dp(n + 1, vector<ll> (n + 1));  
    vector<vector<ll>> dm(n + 1, vector<ll> (n + 1));
    for (int len = 1; len <= n; len++) {
        for (int l = 0; l + len <= n; l++) {
            int r = l + len - 1;
            if (len == 1) {
                dp[l][r] = 1;
                dm[l][r] = 1;
            }
            else {
                if (len == 2) {
                    dm[l][r] = 1;
                }
                else {
                    ll comb = 0;
                    for (int j = l + 1; j < r; j++) {
                        if (a[l][j]) {
                            comb = (comb + dm[j][r] * dm[l][j]) % MOD;
                        }
                    }  
                    comb = (comb + dp[l + 1][r]) % MOD;
                    dm[l][r] = comb;

                }


                ll comb = 0;
                for (int j = l + 1; j <= r; j++) {
                    if (a[l][j]) {
                        if (j - l == 1) {
                            comb = (comb + dp[j][r] * 1) % MOD;
                        }
                        else {
                            comb = (comb + dp[j][r] * (dm[l][j])) % MOD;
                        }
                        //comb = (comb + dp[j][r] * dp[l + 1][j]) % MOD;
                    }
                } 
                dp[l][r] = comb;
            }
        }
    } 
    cout << dp[0][n - 1] << endl;
    

    
#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}