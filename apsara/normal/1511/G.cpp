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
const int V = 200100;
const int MX = 20;
const int T = 6;
const int N = 1 << T;

char t[V];
bool s[T + 1][N][V], a[V];
int n, m, x, Q, L, R;

int main() {
    while (~scanf("%d%d", &n, &m)) {
        for (int i = 1; i <= m; ++i) a[i] = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &x);
            a[x] ^= 1;
        }
        for (int j = 0; j <= T; ++j) {
            for (int k = 0; k < (1 << j); ++k)
                s[j][k][0] = 0;
            for (int i = 1; i <= m; ++i) {
                for (int k = 0; k < (1 << j); ++k)
                    s[j][k][i] = s[j][k][i - 1];
                if (j == 0) s[j][i % (1 << j)][i] ^= a[i];
                else {
                    for (int k = 0; k < (1 << (j - 1)); ++k)
                        s[j][(i - k + (1 << (j - 1))) % (1 << j)][i] ^= a[i];
                }
            }
        }
        /*
        for (int j = 0; j <= T; ++j) {
            for (int k = 0; k < (1 << j); ++k) {
                printf("S %d %d\n", j, k);
                for (int i = 1; i <= m; ++i) if(s[j][k][i] != s[j][k][i - 1])printf("%d ", i); puts("");
            }
        }*/
        scanf("%d", &Q);
        for (int i = 0; i < Q; ++i) {
            scanf("%d%d", &L, &R);
            bool zero = true;
            for (int j = 1; j <= T; ++j) {
                int tmp = s[j][L % (1 << j)][R] ^ s[j][L % (1 << j)][L];
                if (tmp != 0) zero = false;
            }
            for (int j = T; j < MX; ++j) {
                int tmp = 0;
                for (int k = 0; ; k += (1 << (j + 1)) ) {
                    int tl = k + L + (1 << j) - 1;
                    int tr = min(R, k + L + (1 << (j + 1)) - 1);
                    if (tl > tr) break;
                   // printf("Q %d %d %d %d %d\n", j, tl, tr, s[0][0][tr] ^ s[0][0][tl], (1 << (j + 1)));
                    tmp ^= s[0][0][tr] ^ s[0][0][tl];
                }
                if (tmp != 0) zero = false;
            }
            if (zero) t[i] = 'B';
            else t[i] = 'A';
        }
        t[Q] = 0;
        puts(t);
    }
    return 0;
}

/*
8 10
1 3 3 7 4 2 6 9
7
2 3
1 3
1 4
1 10
5 10
8 10
9 10

10 10
1 2 3 4 5 6 7 8 9 10
1
1 10
*/