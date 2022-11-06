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
    int x;
    vector<int> a;
    while (sci(x) == 1) {
        a.push_back(x);
        scanf(",");
    }
    sort(a.begin(), a.end());
    a.push_back(1e9);
    int n = a.size();

    vector<pair<int, int> > ans;

    int cb = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] > a[i - 1] + 1) {
            ans.push_back({a[cb], a[i - 1]});
            cb = i;
        }
    }
    for (int i = 0; i < ans.size(); i++) {
        if (i != 0) {
            cout << ",";
        }
        if (ans[i].first == ans[i].second) {
            cout << ans[i].first;
        } else {
            cout << ans[i].first << "-" << ans[i].second;
        }
    }

    return 0;
}