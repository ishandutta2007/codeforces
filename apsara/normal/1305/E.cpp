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

int n, m;
const int V = 5010;
int main() {
    while (~scanf("%d%d", &n, &m)) {
        int mx = 0;
        for (int i = 1; i <= n; ++i) mx += (i - 1) / 2;
        if (mx < m) {
            puts("-1");
            continue;
        }
        int pr = 0, pre = 0;
        for (int i = 0; i <= n; ++i) {
            if (pre + (i - 1) / 2 > m) break;
            pre += (i - 1) / 2;
            pr = i;
        }
        int need = m - pre;
        for (int i = 1; i <= pr; ++i) printf("%d ", i);
        int remain = n - pr;
        if (need != 0) {
            int np = -1;
            for (int i = pr + 1; ;++i) {
                int tc = 0;
                for (int j = 1; j <= pr; ++j) {
                    if (i - j > j && i - j <= pr) tc++;
                }
                //printf("TC %d %d\n", i, tc);
                if (tc == need) {np = i; break;}
            }
            --remain;
            printf("%d ", np);
        }
        for (int i = remain; i > 0; --i) printf("%d ", 1000000000 - 30000 * i);puts("");
    }
    return 0;
}

/*

*/