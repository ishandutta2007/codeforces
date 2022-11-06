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
const int ooo = 1e9+10;
const LL oo = (LL) ooo * ooo;
const int V = 300100;
int n, m, _, a[V], c[V];
LL s[V], s1[V];
int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
        for (int i = 1; i <= m; ++i) scanf("%d", &c[i]);
        sort(a, a + n);
        s[0] = c[a[0]];
        for (int i = 1; i < n; ++i) s[i] = s[i - 1] + c[a[i]];
        s1[0] = 0;
        for (int i = 1; i <= m; ++i) s1[i] = s1[i - 1] + c[i];
        LL ans = oo;
        for (int i = 0; i <= min(n, m); ++i) {
            LL tmp = 0;
            if (i != n) tmp += s[n - i - 1];
            tmp += s1[i];
            //printf("%d %I64d\n", i, tmp);
            ans = min(ans, tmp);
        }
        printf("%I64d\n", ans);
    }
    return 0;
}

/*
2
5 4
2 3 4 3 2
3 5 12 20
5 5
5 4 3 2 1
10 40 90 160 250

1
1 1
1
1
*/