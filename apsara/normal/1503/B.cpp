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
const int V = 110;

int E[V * V], O[V * V];
int n, w;
int main() {
    while (~scanf("%d", &n)) {
        int even = 0, odd = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (i % 2 == j % 2) E[even++] = i * n + j;
                else O[odd++] = i * n + j;
        int en = 0, on = 0;
        for (int step = 0; step < n * n; ++step) {
            scanf("%d", &w);
            if (en < even && w != 1) {
                int x = E[en] / n;
                int y = E[en] % n;
                ++en;
                printf("1 %d %d\n", x + 1, y + 1);
                fflush(stdout);
            } else if (on < odd && w != 2) {
                int x = O[on] / n;
                int y = O[on] % n;
                ++on;
                printf("2 %d %d\n", x + 1, y + 1);
                fflush(stdout);
            } else {
                if (en == even) {
                    int x = O[on] / n;
                    int y = O[on] % n;
                    ++on;
                    printf("3 %d %d\n", x + 1, y + 1);
                    fflush(stdout);
                } else {
                    int x = E[en] / n;
                    int y = E[en] % n;
                    ++en;
                    printf("3 %d %d\n", x + 1, y + 1);
                    fflush(stdout);
                }
            }
        }
    }
    return 0;
}

/*

*/