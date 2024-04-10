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
int _, n, x, a[V];
int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) a[i] = 0;
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &x);
            a[x]++;
        }
        int cnt = 0, mx = 0;
        for (int i = 1; i <= n; ++i) {
            cnt += a[i] > 0;
        }
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            ans = max(ans, min(cnt, a[i] - 1));
            ans = max(ans, min(cnt - 1, a[i]));
        }
        printf("%d\n", ans);
    }
    return 0;
}

/*
4
7
4 2 4 1 4 3 4
5
2 1 5 4 3
1
1
4
1 1 1 3
*/