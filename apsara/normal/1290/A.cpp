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

const int oo = 1000000000;
const int V = 3510;
int a[V];
int _, n, m, K;
int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d%d%d", &n, &m, &K);
        for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
        K = min(K, m - 1);
        int ans = 0;
        for (int l = 0; l <= K; ++l) {
            int r = K - l;
            int re = m - 1 - K;
            int mi = oo;
            for (int i = 0; i <= re; ++i) {
                int j = re - i;
                int choose = max(a[l + i], a[n - 1 - r - j]);
                //printf("%d %d %d %d\n", l, i, a[l + i], a[n - 1 - r - j]);
                mi = min(mi, choose);
            }
            ans = max(ans, mi);
        }
        printf("%d\n", ans);
    }
    return 0;
}

/*
4
6 4 2
2 9 2 3 8 5
4 4 1
2 13 60 4
4 1 3
1 2 2 1
2 2 0
1 2

*/