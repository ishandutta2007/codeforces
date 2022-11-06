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
const int V = 300100;
int a[V], h[V], v[V];

int _, n;

int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
        for (int i = 0; i < n; ++i) h[i] = v[i] = 0;
        LL s = 0;
        for (int i = 1; i + 1 < n; ++i) {
            if (a[i] > a[i - 1] && a[i] > a[i + 1]) h[i] = 1;
            if (a[i] < a[i - 1] && a[i] < a[i + 1]) v[i] = 1;
        }
        for (int i = 0; i < n; ++i) if(h[i] || v[i]) s += 1;
        LL tmp = 0;
        for (int i = 0; i < n; ++i) {
            vector<int> b;
            if (i > 0) b.PB(a[i - 1] - 1), b.PB(a[i - 1]), b.PB(a[i - 1] + 1);
            if (i + 1 < n) b.PB(a[i + 1] - 1), b.PB(a[i + 1]), b.PB(a[i + 1] + 1);
            int org = a[i];
            for (int j = 0; j < b.size(); ++j) {
                a[i] = b[j];
                LL cost = 0;
                for (int k = -1; k <= 1; k++) {
                    int p = i + k;
                    if (p <= 0 || p >= n - 1) continue;
                    int th = 0, tv = 0;
                    if (a[p] > a[p - 1] && a[p] > a[p + 1]) th = 1;
                    if (a[p] < a[p - 1] && a[p] < a[p + 1]) tv = 1;
                    cost += (h[p] - th + v[p] - tv) * 1;
                    //printf("K %d %d %d\n", p, th, tv);
                }
                //printf("I %d %d %I64d\n", i, a[i], cost);
                tmp = max(tmp, cost);
            }
            a[i] = org;
        }
        printf("%I64d\n", s - tmp);
    }
    return 0;
}

/*
4
3
1 5 3
5
2 2 2 2 2
6
1 6 2 5 2 10
5
1 6 2 5 1
*/