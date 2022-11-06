#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <memory.h>
#include <stack>

#define scid(a) int a; scanf("%d", &a)
#define sciid(a, b) int a, b; scanf("%d%d", &a, &b)
#define sciiid(a, b, c) int a, b, c; scanf("%d%d%d", &a, &b, &c)

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

#define rveid(a, n) vector<int> a(n); for (int i = 0; i < n; i++) sci(a[i])

typedef long long lint;

using namespace std;

void init_cin() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}

int main() {
    scid(n);
    rveid(a, n);
    vector<int> l(n), r(n);
    stack<int> s;
    for (int i = 0; i < n; i++) {
        while (!s.empty() && a[s.top()] >= a[i]) {
            s.pop();
        }
        if (!s.empty()) {
            l[i] = s.top() + 1;
        }
//        cerr << l[i] << " ";
        s.push(i);
    }
//    cerr << endl;
    while (!s.empty()) {
        s.pop();
    }
    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && a[s.top()] >= a[i]) {
            s.pop();
        }
        if (!s.empty()) {
            r[i] = s.top() - 1;
        } else {
            r[i] = n - 1;
        }
        s.push(i);
    }
//    for (int i = 0; i < n; i++) {
//        cerr << r[i] << " ";
//    }
//    cerr << endl;
//    cerr.flush();
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        ans[r[i] - l[i]] = max(ans[r[i] - l[i]], a[i]);
    }
    int t = *min_element(a.cbegin(), a.cend());
    for (int i = n - 1; i >= 0; i--) {
        if (ans[i] != 0) {
            t = max(t, ans[i]);
        }
        ans[i] = t;
    }
    for (auto i : ans) {
        cout << i << " ";
    }

    return 0;
}