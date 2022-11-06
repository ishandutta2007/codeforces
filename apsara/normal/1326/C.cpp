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
const int P = 998244353;
const int V = 200100;
int a[V], n, m;

int main() {
    while (~scanf("%d%d", &n, &m)) {
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
            if (a[i] > n - m) a[i] = 1;
            else a[i] = 0;
        }
        LL s = 0;
        for (int i = 0; i < m; ++i) s += n - i;
        int ans = 1;
        int pre = -1;
        for (int i = 0; i < n; ++i) {
            if (a[i] == 1) {
                if (pre != -1) ans = (LL) ans * (i - pre) % P;
                pre = i;
            }
        }
        printf("%I64d %d\n", s, ans);
    }
    return 0;
}

/*

*/