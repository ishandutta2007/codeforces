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

lint cc[51];

lint get_cnt(lint n) {
    if (cc[n] != -1) {
        return cc[n];
    }
    return cc[n] = get_cnt(n - 1) + get_cnt(n - 2);
}

int ans[51];

int main() {
    memset(cc, -1, sizeof(cc));
    cc[0] = cc[1] = 1;

    init_cin
    int n;
    lint k;
    cin >> n >> k;
    --k;
    int i = n;
    while (i > 0) {
        if (get_cnt(i - 1) > k) {
            ans[n - i + 1] = n - i + 1;
            i--;
        } else {
            k -= get_cnt(i - 1);
            ans[n - i + 1] = n - i + 2;
            ans[n - i + 2] = n - i + 1;
            i -= 2;
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }

    return 0;
}