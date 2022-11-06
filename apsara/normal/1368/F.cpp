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
int n;
const int V = 1100;
int is[V], cur[V], b[V];

int x;
int main() {
    while (~scanf("%d", &n)) {
        int K = 1, ans = 0;
        for (int i = 2; i < n - 1; ++i) {
            int part = n / i + 1;
            if (n % i == 0) --part;
            int tmp = n - part - (i - 1);
            if (tmp > ans) ans = tmp, K = i;
            //printf("%d %d %d\n", i, part, tmp);
        }
        //printf("%d %d\n", K, ans);
        memset(is, 0, sizeof(is));
        memset(cur, 0, sizeof(cur));
        for (int i = 0; i < n; ++i) {
            if (i % K != K - 1) is[i] = 1;
        }
        is[n - 1] = 0;
        while (true) {
            int cnt = 0;
            for (int i = 0; i < n; ++i) cnt += cur[i];
            if (cnt >= ans) {
                puts("0");
                fflush(stdout);
                break;
            }
            int m = 0;
            for (int i = 0; i < n; ++i) {
                if (cur[i] == 0 && is[i] == 1) b[m++] = i;
            }
            for (int i = 0; i < K; ++i) cur[b[i]] = 1;
            printf("%d", K);
            for (int i = 0; i < K; ++i) printf(" %d", b[i] + 1); puts("");
            fflush(stdout);
            scanf("%d", &x);
            for (int i = 0; i < K; ++i) cur[(x + i + n - 1) % n] = 0;
        }

    }
    return 0;
}

/*

*/