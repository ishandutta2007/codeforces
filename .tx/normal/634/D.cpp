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

pair<int, int> a[222222];
int can[222222];

int main() {
    sciiid(d, n, m);
    int on = n;
    for (int i = 0; i < m; i++) {
        sciid(x, y);
        a[i] = {x, y};
    }
    sort(a, a + m);
    a[m] = {d, 0};
    priority_queue<pair<int, int> > q;
    lint ans = 0;
    int cp = 0;
    int last = -1;
    for (int i = 0; i <= m; i++) {
        int dx = a[i].first - cp;
        if (dx > on) {
            cout << -1;
            return 0;
        }
        if (dx > n) {
            while (dx > n && !q.empty()) {
                auto it = q.top();
                it.second = -it.second;
                if (it.second < last) {
                    q.pop();
                    continue;
                }
                if (last != -1 && it.second != last) {
                    can[it.second] = min(can[it.second], a[it.second].first - a[last].first + can[last]);
                }
                int t = min(can[it.second], dx - n);
                if (t > 0) {
                    last = it.second;
                }
                ans += 1LL * -it.first * t;
                n += t;
                can[it.second] -= t;
                if (can[it.second] == 0) {
                    q.pop();
                }
            }
        }
        if (dx > n) {
            cout << -1;
            return 0;
        }
        n -= dx;
        q.push({-a[i].second, -i});
        can[i] = on - n;
//        if (i > 0 && a[i].second >= a[i - 1].second) {
//            can[i] = min(can[i], a[i].first - a[i - 1].first);
//        }
        cp = a[i].first;
    }
    cout << ans;

    return 0;
}