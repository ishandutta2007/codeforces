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
const int V = 100100;
const int N = 200000;
int a[V], n;
int cnt[N + 10], vis[N + 10];
int main() {
    while (~scanf("%d", &n)) {
        for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < n; ++i) cnt[a[i]]++;
        LL ans = 1;
        memset(vis, 0, sizeof(vis));
        for (int i = 2; i <= N; ++i) {
            if (vis[i]) continue;
            for (int j = 2 * i; j <= N; j += i) vis[j] = 1;
            int mx = 1;
            for (int j = i; j <= N;) {
                int tc = 0;
                for (int k = j; k <= N; k += j) {
                    tc += cnt[k];
                }
                if (tc >= n - 1) mx = j;
                if ((LL) i * j > N) break;
                j *= i;
            }
            ans *= mx;
        }
        printf("%I64d\n", ans);
    }
    return 0;
}

/*
2
1 1
4
10 24 40 80
10
540 648 810 648 720 540 594 864 972 648
*/