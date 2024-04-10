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
int a[V], _, n, m, K;

int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d%d%d", &n, &m, &K);
        for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
        int ans = 0;
        int mx = 0;
        int s = a[1];
        for (int i = 2; i <= n; ++i) {
            mx = max(mx, a[i] + a[i - 1]);
            s += a[i];
            if ((i - 1) % 2 == m % 2) {
                int left = (m - i + 1) / 2;
                if (left < 0 || left > K) continue;
                ans = max(ans, mx * left + s);
            } else {
                int left = (m - i + 1 + 1) / 2;
                if (left < 1 || left > K) continue;
                ans = max(ans, mx * (left - 1) + s + a[i - 1]);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}

/*
4
5 4 0
1 5 4 3 2
5 4 1
1 5 4 3 2
5 4 4
10 20 30 40 50
10 7 3
4 6 8 2 9 9 7 4 10 9
*/