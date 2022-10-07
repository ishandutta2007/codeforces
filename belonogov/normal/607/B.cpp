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

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define all(a) (a).begin(), (a).end()

#define equal equalll
#define less lesss
const int N = 555;
const long long INF = 1e9 + 19;

int n;
int a[N];
int dp[N][N];

void read() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

}

void solve() {
    memset(dp, 63, sizeof(dp));
    for (int i = 0; i < n; i++) {
        dp[i][i + 1] = 1;
        dp[i][i] = 1; 
    }   
    for (int len = 2; len <= n; len++) {
        for (int l = 0; l + len <= n; l++) {
            int r = l + len;
            if (a[l] == a[r - 1]) {
                dp[l][r] = min(dp[l][r], dp[l + 1][r - 1]);
            } 
            for (int i = 1; i < len; i++) {
                dp[l][r] = min(dp[l][r], dp[l + i][r] + dp[l][l + i]);
                dp[l][r] = min(dp[l][r], dp[l][r - i] + dp[r - i][r]);
            }
        }
    }
    cout << dp[0][n] << endl;
}

void stress() {

}


int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    if (1) {
        int k = 1;
        for (int tt = 0; tt < k; tt++) {
            read();
            solve();
        }
    }
    else {
        stress();
    }

    return 0;
}