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

pair<int, int> a[111111];
pair<int, int> b[111111];

bool np[111111];
int mp[111111];

int main() {
    scid(n);
    for (int i = 0; i < n; i++) {
        scid(x);
        a[i].first = x;
        b[i] = {x, i};
    }
    sort(b, b + n);
    for (int i = 0; i < n; i++) {
        a[b[i].second].second = i;
    }

    for (int i = 2; i <= 1e5; i++) {
        if (!np[i]) {
            for (int j = i + i; j <= 1e5; j += i) {
                np[j] = true;
            }
        }
    }

    int mx = 0;
    for (int i = 2; i <= 1e5; i++) {
        if (!np[i]) {
            mx = i;
        }
        mp[i] = mx;
    }

    vector<pair<int, int> > ans;

    for (int i = 0; i < n; i++) {
        int cp = b[i].second;
        if (cp == i) {
            continue;
        }
        while (cp > i) {
            int p = mp[cp - i + 1];
            int np = cp - p + 1;
            ans.push_back({np, cp});
            int nb = a[np].second;
            b[nb].second = cp;
            b[i].second = np;
            swap(a[np], a[cp]);
            cp = np;
        }
        while (cp < i) {
            int p = mp[i - cp + 1];
            int np = cp + p - 1;
            ans.push_back({cp, np});
            int nb = a[np].second;
            b[nb].second = cp;
            b[i].second = np;
            swap(a[np], a[cp]);
            cp = np;
        }
    }

    cout << ans.size() << "\n";
    for (auto& i : ans) {
        cout << i.first + 1 << " " << i.second + 1 << "\n";
    }

    return 0;
}