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
int a[120], _, n, K;

int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d%d", &n, &K);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        int ans = a[0];
        for (int i = 1; i < n; ++i) {
            int cnt = min(K / i, a[i]);
            K -= cnt * i;
            ans += cnt;
        }
        printf("%d\n", ans);
    }
    return 0;
}

/*
3
4 5
1 0 3 2
2 2
100 1
1 8
0
*/