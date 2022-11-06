#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <string>
#include <memory.h>

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

#define scid(a) int a; sci(a)
#define sciid(a, b) int a, b; scii(a, b)
#define sciiid(a, b, c) int a, b, c; sciii(a, b, c)

#define rea(a, n) for (int i = 0; i < n; i++) sci(a[i])

#define init_cin ios_base::sync_with_stdio(false); cin.tie(0);

typedef long long lint;
typedef long double ldouble;

using namespace std;

const int M = 1e6;

int cnt[M + 1];
vector<int> divs[M + 1];
int a[1111111];

int main() {
    sciid(n, m);
    for (int i = 0; i < n; i++) {
        scid(x);
        if (x <= M) {
            cnt[x]++;
        }
        a[i] = x;
    }
    for (int i = 1; i <= m; i++) {
        for (int j = i; j <= m; j += i) {
            divs[j].push_back(i);
        }
    }
    int ans = -1;
    int l = -1;
    for (int i = 1; i <= m; i++) {
        int c = 0;
        for (int j : divs[i]) {
            c += cnt[j];
        }
        if (c > ans) {
            ans = c;
            l = i;
        }
    }
    printf("%d %d\n", l, ans);
    for (int i = 0; i < n; i++) {
        if (l % a[i] == 0) {
            printf("%d ", i + 1);
        }
    }


    return 0;
}