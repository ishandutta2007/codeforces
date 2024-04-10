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
const int N = 222;
const int K = 1111;
const long long INF = 1e9 + 19;
const int MOD = 1e9 + 7;


int n, k;
int a[N];
int dp[N][N][K];

void read() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
}

void solve() {
    sort(a, a + n);
    dp[0][0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++)
            for (int t = 0; t <= k; t++) {
                for (int dj = -1; dj <= 1; dj++) {
                    if (i + 1 == n && j + dj > 0) continue;
                    int diff = a[i + 1] - a[i];
                    int nj = j + dj;
                    int nt = t + diff * nj;
                    int cof;
                    if (dj == 1) 
                        cof = 1;
                    if (dj == 0)
                        cof = (j + 1);
                    if (dj == -1)
                        cof = j;
                    if (nt <= k)
                        dp[i + 1][nj][nt] = (dp[i + 1][nj][nt] + (dp[i][j][t] * 1ll * cof) % MOD) % MOD;
                }
            } 
    } 

    int answer = 0;
    for (int i = 0; i <= k; i++)
        answer = (answer + dp[n][0][i]) % MOD;

    printf("%d\n", answer);

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