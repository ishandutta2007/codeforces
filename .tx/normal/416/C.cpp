#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <string>
#include <memory.h>

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

#define scid(a) int a; sci(a)
#define sciid(a, b) int a, b; scii(a, b)
#define sciiid(a, b, c) int a, b, c; sciii(a, b, c)

#define rvei(a, n) for (int i = 0; i < n; i++) sci(a[i])
#define rveid(a, n) vector<int> a(n); rvei(a, n)

#define init_cin ios_base::sync_with_stdio(false); cin.tie(0);

typedef long long lint;

using namespace std;

int main() {
    scid(n);
    vector<pair<pair<int, int>, int > > a;
    for (int i = 0; i < n; ++i) {
        sciid(c, p);
        a.push_back({{p, c}, i});
    }
    sort(a.rbegin(), a.rend());

    scid(m);
    vector<int> b;
    vector<int> used(m, false);
    for (int i = 0; i < m; ++i) {
        scid(x);
        b.push_back(x);
    }

    vector<pair<int, int> > pairs;
    int s = 0;

    for (auto& i : a) {
        int mn = -1;
        for (int j = 0; j < m; j++) {
            if (!used[j] && b[j] >= i.first.second && (mn == -1 || b[j] < b[mn])) {
                mn = j;
            }
        }
        if (mn != -1) {
            s += i.first.first;
            pairs.push_back({i.second, mn});
            used[mn] = true;
        }
    }

    cout << pairs.size() << " " << s << "\n";
    for (auto& i : pairs) {
        cout << i.first + 1 << " " << i.second + 1 << "\n";
    }

    return 0;
}