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
const int V = 100100;
int _, n;
int a[V];

int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
        int mi = -1, mx = -1;
        for (int i = 1; i <= n; ++i) {
            if (a[i] == -1) continue;
            if ((i == 1 || a[i - 1] != -1) && (i == n || a[i + 1] != -1))
                continue;
            if (mi == -1 || a[i] < mi) mi = a[i];
            if (mx == -1 || a[i] > mx) mx = a[i];
        }
        int ans = (mi + mx) / 2;
        if (ans == -1) ans = 0;
        int res = 0;
        for (int i = 1; i <= n; ++i) {
            if (a[i] == -1) a[i] = ans;
            if (i > 1) res = max(res, abs(a[i] - a[i - 1]));
        }
        printf("%d %d\n", res, ans);
    }
    return 0;
}

/*
7
5
-1 10 -1 12 -1
5
-1 40 35 -1 35
6
-1 -1 9 -1 3 -1
2
-1 -1
2
0 -1
4
1 -1 3 -1
7
1 -1 7 5 2 -1 5
*/