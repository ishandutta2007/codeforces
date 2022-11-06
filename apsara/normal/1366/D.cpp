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
const int V = 500100;
int ans[V][2];
const int N = 1e7;
int is[N + 10], p[N + 10];

void init() {
    memset(p, -1, sizeof(p));
    for (int i = 0; i <= N; ++i) is[i] = 1;
    for (int i = 2; i <= N; ++i) {
        if (!is[i]) continue;
        for (int j = i * 2; j <= N; j += i) {
            p[j] = i;
            is[j] = 0;
        }
    }
    memset(ans, -1, sizeof(ans));
}

void solve(int i, int x) {
    if (p[x] == -1) {
        return;
    }
    int y = p[x];
    while ((x / y) % p[x] == 0) y *= p[x];
    if (y == x) {
        return;
    }
    ans[i][0] = y;
    ans[i][1] = x / y;
}

int n, x;
int main() {
    init();
    while (~scanf("%d", &n)) {
        for (int i = 0; i < n; ++i) {
            scanf("%d", &x);
            solve(i, x);
        }
        for (int i = 0; i < n; ++i) printf("%d ", ans[i][0]); puts("");
        for (int i = 0; i < n; ++i) printf("%d ", ans[i][1]); puts("");
    }
    return 0;
}

/*
10
2 3 4 5 6 7 8 9 10 24
*/