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
int f[V];
int fd(int x) {
    if (f[x] != x) f[x] = fd(f[x]);
    return f[x];
}

int U(int x, int y) {
    int px = fd(x);
    int py = fd(y);
    if (px == py) return 1;
    f[px] = py;
    return 0;
}

int _, n, m, u, v;
int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; ++i) f[i] = i;
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            scanf("%d%d", &u, &v);
            if (u == v) continue;
            ans++;
            ans += U(u, v);
        }
        printf("%d\n", ans);
    }
    return 0;
}

/*
4
3 1
2 3

3 2
2 1
1 2

5 3
2 3
3 1
1 2

5 4
4 5
5 1
2 2
3 3
*/