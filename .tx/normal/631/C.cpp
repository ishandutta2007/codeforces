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
#include <stack>

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

int a[222222];
int ans[222222];

int main() {
    sciid(n, m);
    rea(a, n);
    deque<pair<int, int> > s;
    for (int i = 0; i < m; i++) {
        sciid(t, x);
        while (!s.empty() && s.back().first <= x) {
            s.pop_back();
        }
        s.push_back({x, t});
    }
    int t = s.front().first;
    sort(a, a + t);
    for (int i = t; i < n; i++) {
        ans[i] = a[i];
    }
    int f = 0, l = t - 1;
    int ct = 2;
    int i = t;
    while (i > 0) {
        if (!s.empty()) {
            auto it = s.front();
            if (i == it.first) {
                ct = it.second;
                s.pop_front();
            }
        }
        if (ct == 1) {
            ans[--i] = a[l--];
        } else {
            ans[--i] = a[f++];
        }
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }

    return 0;
}