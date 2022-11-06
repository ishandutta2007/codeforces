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

char a[111111];

int calc(deque<int>& a) {
    int n = a.size();
    int l = -1, r = n;
    while (l + 1 < r) {
        int m = (l + r) >> 1;
        if (a[m] - a[0] < a.back() - a[m]) {
            l = m;
        } else {
            r = m;
        }
    }
    int res = 1e9;
    if (l != -1) {
        res = min(res, max(a[l] - a[0], a.back() - a[l]));
    }
    if (r != n) {
        res = min(res, max(a[r] - a[0], a.back() - a[r]));
    }
    return res;
}

int main() {
    sciid(n, k);
    k++;
    scanf("\n%s", a);
    deque<int> d;
    int ans = 1e9;
    int i = 0;
    while (d.size() < k) {
        if (a[i] == '0') {
            d.push_back(i);
        }
        i++;
    }
    ans = calc(d);
    while (i < n) {
        if (a[i] == '0') {
            d.pop_front();
            d.push_back(i);
            ans = min(ans, calc(d));
        }
        i++;
    }
    cout << ans;


    return 0;
}