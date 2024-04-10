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

const int MAX = 1e6;

int cnt[MAX + 1];

int main() {
    sciid(n, k);
    for (int i = 0; i < n; i++) {
        scid(x);
        cnt[x]++;
    }

    for (int i = 1; i <= MAX; i++) {
        cnt[i] += cnt[i - 1];
    }

    int ans = 0;

    for (int i = 1; i <= MAX; i++) {
        int l = min(k + 1, i);
        int c = 0;
        for (int j = i; j <= MAX; j += i) {
            int x = cnt[min(MAX, j + l - 1)];
            if (j > 0) {
                x -= cnt[j - 1];
            }
            c += x;
        }
        if (c == n) {
            ans = i;
        }
    }

    cout << ans;

    return 0;
}