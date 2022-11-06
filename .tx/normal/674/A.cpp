#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <string>
#include <memory.h>
#include <bitset>

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

int cnt[5555];
int a[5555];
int ans[5555];

int main() {
    scid(n);
    rea(a, n);
    for (int i = 0; i < n; i++) {
        memset(cnt, 0, sizeof(cnt));
        int cm = -1;
        int ci = -1;
        for (int j = i; j < n; j++) {
            cnt[a[j]]++;
            int x = a[j];
            int c = cnt[a[j]];
            if (c > cm || (c == cm && x < ci)) {
                cm = c;
                ci = x;
            }
            ans[ci]++;
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }

    return 0;
}