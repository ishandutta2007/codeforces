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

const int N = 100000;
const int K = 300;

//int xs[N * K];
//int lst[N * K];
//int cur[N * K];
lint ans[N + 1];
//bool was[N * K];

//pair<int, int> a[N];

struct Item {
    int x, y;
    bool open;
    int lbx;

    Item(int x, int y, bool open) : x(x), y(y), open(open) { }

    bool operator<(const Item& r) const {
        return y < r.y;
    }
};

//Item qs[N * 2];

int main() {
    sciid(n, k);
    vector<pair<int, int> > a(n);
    for (int i = 0; i < n; i++) {
        scii(a[i].first, a[i].second);
    }

    sort(a.rbegin(), a.rend());

    vector<Item> qs;

    int lx = -2e9;
    vector<int> xs;
    while (!a.empty()) {
        auto& p = a.back();
        int st = max(p.first, lx + 1);
        for (int j = st; j < p.first + k; j++) {
            xs.push_back(j);
            lx = j;
        }
        qs.push_back(Item(p.first, p.second, true));
        qs.push_back(Item(p.first, p.second + k, false));
        a.pop_back();
    }

    for (auto& q : qs) {
        q.lbx = lower_bound(xs.begin(), xs.end(), q.x) - xs.begin();
    }

    xs = vector<int>();

    sort(qs.begin(), qs.end());

    vector<int> lst(N * K, (int) -2e9);
    vector<int> cur(N * K, 0);

    for (int i = 0; i < 2 * n; i++) {
        auto& p = qs[i];
        int l = p.lbx;
        for (int j = l; j < l + k; j++) {
            if (lst[j] != -2e9) {
                ans[cur[j]] += p.y - lst[j];
            }
            lst[j] = p.y;
            if (p.open) {
                cur[j]++;
            } else {
                cur[j]--;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }

    return 0;
}