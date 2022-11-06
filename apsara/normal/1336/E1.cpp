#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define PB push_back
#define fi first
#define se second
#define MP make_pair
const int P = 998244353;

const int M = 40;
const int V = 200100;
LL a[V], b[M], po[M];
int dp[2][M / 2][1<<18];
int ans[M], C[1<<18];
int n, K, m;

int main() {
    po[0] = 1;
    for (int i = 1; i < M; ++i) po[i] = po[i - 1] * 2;
    for (int i = 0; i < (1 << 18); ++i) {
        C[i] = 0;
        for (int j = 0; j < 18; ++j) if (i & (1 << j)) ++C[i];
    }
    while (~scanf("%d%d", &n, &K)) {
        for (int i = 0; i < n; ++i) scanf("%I64d", &a[i]);
        m = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] == 0) continue;
            int id = -1;
            for (int j = K; j >= 0; --j) {
                if (a[i] & po[j]) {
                    id = j;
                    break;
                }
            }
            for (int j = 0; j < n; ++j) {
                if (i != j && (a[j] & po[id])) a[j] ^= a[i];
            }
            m++;
        }
        sort(a, a + n);
        for (int i = 0; i < m; ++i) b[i] = a[n - i - 1];
        //for (int i = 0; i < m; ++i) printf("%I64d ", b[i]); puts("");
        memset(dp, 0, sizeof(dp));
        int L = K / 2;
        int R = m;
        for (int i = 0; i < m; ++i) {
            if (b[i] < (1LL << L)) {R = i; break;}
        }
        //printf("%d %d\n", L, R);
        for (int i = 0; i < (1LL << R); ++i) {
            LL tmp = 0;
            for (int j = 0; j < R; ++j) {
                if (i & (1LL << j)) tmp ^= b[j];
            }
            int cnt = 0;
            for (int j = L; j < M; ++j) if (tmp & (1LL << j)) cnt++;
            //printf("%d %d %I64d %d\n", i, cnt, tmp, (int)(tmp & ((1 << L) - 1)));
            dp[0][cnt][(int) (tmp & ((1LL << L) - 1))]++;
        }
        int now = 0, nxt = 0;
        for (int i = R; i < m; ++i) {
            nxt = 1 - now;
            memset(dp[nxt], 0, sizeof(dp[nxt]));
            for (int j = 0; j <= K - L; ++j) {
                for (int k = 0; k < (1LL << L); ++k) {
                    dp[nxt][j][(int) (k ^ b[i])] += dp[now][j][k];
                    dp[nxt][j][(int) (k ^ b[i])] %= P;
                    dp[nxt][j][k] += dp[now][j][k];
                    dp[nxt][j][k] %= P;
                }
            }
            now = nxt;
        }
        memset(ans, 0, sizeof(ans));
        for (int j = 0; j <= K - L; ++j) {
            for (int k = 0; k < (1LL << L); ++k) {
                ans[j + C[k]] += dp[now][j][k];
                ans[j + C[k]] %= P;
            }
        }
        int xs = 1;
        for (int i = m; i < n; ++i) xs = (LL) xs * 2 % P;
        for (int i = 0; i <= K; ++i) ans[i] = (LL) ans[i] * xs % P;
        for (int i = 0; i <= K; ++i) printf("%d ", ans[i]); puts("");
    }
    return 0;
}

/*
4 4
3 5 8 14
6 7
11 45 14 9 19 81
*/