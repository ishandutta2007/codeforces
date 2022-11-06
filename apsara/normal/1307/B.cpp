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
int _, n, K, a[V];
int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d%d", &n, &K);
        int mx = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
            mx = max(mx, a[i]);
        }
        int ans = K / mx;
        if (ans == 0) {
            bool has = false;
            for (int i = 0; i < n; ++i) if (K - ans * mx == a[i]) has = true;
            if (has) ans++;
            else ans += 2;
        } else {
            if (K % mx != 0) ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}

/*
4
2 4
1 3
3 12
3 4 5
1 5
5
2 10
15 4
*/