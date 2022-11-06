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
const int N = 50;

int a[N + 10], pre[N + 10];
int n, Q, x;
int main() {
    while (~scanf("%d%d", &n, &Q)) {
        memset(pre, -1, sizeof(pre));
        int m = 1;
        int cnt = 0;
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &x);
            if (pre[x] == -1) {
                pre[x] = cnt;
                a[m++] = x;
            } else ++cnt;
        }
        while (Q--) {
            scanf("%d", &x);
            int id = -1;
            for (int i = 1; i <= m; ++i) {
                if (a[i] == x) id = i;
            }
            printf("%d ", pre[x] + id);
            pre[x] = 0;
            for (int i = id; i > 1; --i) a[i] = a[i - 1];
            a[1] = x;
        }puts("");
    }
    return 0;
}

/*
7 5
2 1 1 4 3 3 1
3 2 1 1 4
*/