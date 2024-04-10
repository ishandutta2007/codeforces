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
const int N = 3;
const int M = N * N;
char s[M][M];
int ans[M][M], _;

int main() {
    scanf("%d", &_);
    while (_--) {
        for (int i = 0; i < M; ++i)
            scanf("%s", s[i]);
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < M; ++j) {
                ans[i][j] = s[i][j] - '0';
            }
        }
        for (int i = 0; i < M; ++i) {
            int r = i / N;
            int c = i % N;
            ans[r * N + c][c * N + r] = ans[r * N + c][c * N + r] % M + 1;
        }
        for (int i = 0; i < M; ++i, puts("")) {
            for (int j = 0; j < M; ++j) {
                putchar(ans[i][j] + '0');
            }
        }
    }
    return 0;
}

/*
1
154873296
386592714
729641835
863725149
975314628
412968357
631457982
598236471
247189563
*/