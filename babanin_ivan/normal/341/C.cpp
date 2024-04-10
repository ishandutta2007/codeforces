#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <stack>

using namespace std;

#define pb push_back
#define mp make_pair
#define fir first
#define fi first
#define sec second
#define y1 botva23
typedef long long int64;
typedef long double ld;

const int inf = 2000000000;
const ld eps = 1e-07;
int64 mod = 1000000007;

int n;
int a[3000];
int dp[3000][3000];
bool used[3000];
int m;
int k;
ld tim = clock();
int64 fact[3000];

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    fact[0] = 1;
    for (int i = 1; i <= 2010; ++i)
        fact[i] = (fact[i - 1] * int64(i)) % mod;

    cin >> n;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        --a[i];
        if (a[i] >= 0)  
            used[a[i]] = true;
        else ++m;
    }

    for (int i = 0; i < n; ++i)
        if (a[i] < 0 && !used[i])
            ++k;

    dp[m][k] = 1;//(fact[k] * fact[m - k]) % mod;

    for (int i = m; i >= 1; --i)
        for (int j = min(k, i); j >= 0; --j) {
            if (((i == 1) && (j == 1) ) || (dp[i][j] == 0))
                continue;
            if (i != j) {
                dp[i - 1][j] = (int64(dp[i - 1][j]) + int64(dp[i][j]) * int64(i - j)) % mod;
                dp[i - 1][j - 1] = (int64(dp[i - 1][j - 1]) + int64(dp[i][j]) * int64(j)) % mod;
            }
            else {
                dp[i - 1][j - 2] = (int64(dp[i - 1][j - 2]) + int64(dp[i][j]) * int64(j - 1)) % mod;
            }
        }
    cout << dp[0][0] << endl;
    return 0;
}