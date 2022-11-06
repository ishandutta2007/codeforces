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
    sciiid(n, k, p);
    vector<int> odd, even;
    for (int i = 0; i < n; ++i) {
        scid(x);
        (x % 2 == 0 ? even : odd).push_back(x);
    }
    if (odd.size() % 2 != (k - p) % 2) {
        cout << "NO";
        return 0;
    }
    if (odd.size() < k - p || p > even.size() + (odd.size() - k + p) / 2) {
        cout << "NO";
        return 0;
    }
    cout << "YES\n";
    vector<vector<int> > ans;
    for (int i = 0; i < k - p; i++) {
        vector<int> t;
        t.push_back(odd.back());
        odd.pop_back();
        ans.push_back(t);
    }
    for (int i = 0; i < p; i++) {
        vector<int> t;
        if (!even.empty()) {
            t.push_back(even.back());
            even.pop_back();
        } else {
            t.push_back(odd.back());
            odd.pop_back();
            t.push_back(odd.back());
            odd.pop_back();
        }
        ans.push_back(t);
    }
    for (int i : even) {
        ans.back().push_back(i);
    }
    for (int i : odd) {
        ans.back().push_back(i);
    }
    for (auto& i : ans) {
        cout << i.size();
        for (int j : i) {
            cout << " " << j;
        }
        cout << "\n";
    }

    return 0;
}