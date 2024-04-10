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
const int P = 1000000007;

const int V = 4100;

int a[V], b[V];
int dp[V];

int _, n, N, m;
int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d", &N);
        n = 2 * N;
        for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
        int pre = -1;
        m = -1;
        for (int i = 0; i < n; ++i) {
            if (pre == -1 || a[pre] < a[i]) {
                if (m >= 0) b[m] = i - pre;
                pre = i;
                ++m;
            }
        }
        b[m++] = n - pre;
        //for (int i = 0; i < m; ++i) printf("%d ", b[i]); puts("M");
        for (int i = 0; i <= N; ++i) dp[i] = 0;
        dp[0] = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = N; j >= b[i]; --j) {
                if (dp[j - b[i]]) dp[j] = 1;
            }
        }
        if (dp[N]) puts("YES");
        else puts("NO");
    }
    return 0;
}

/*
6
2
2 3 1 4
2
3 1 2 4
4
3 2 6 1 5 7 8 4
3
1 2 3 4 5 6
4
6 1 3 7 4 5 8 2
6
4 3 2 5 1 11 9 12 8 6 10 7
*/