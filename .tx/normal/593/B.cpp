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

lint x1, x2;

bool cmp(const pair<lint, lint> &a, const pair<lint, lint> &b) {
    lint y1 = a.first * x1 + a.second;
    lint y2 = b.first * x1 + b.second;
    if (y1 != y2) {
        return y1 < y2;
    }
    return a.first < b.first;
}

int main() {
    init_cin
    int n; cin >> n;
    cin >> x1 >> x2;
    vector<pair<lint, lint> > a;
    for (int i = 0; i < n; ++i) {
        lint k, b;
        cin >> k >> b;
        a.push_back({k, b});
    }
    sort(a.begin(), a.end(), cmp);
    for (int i = 0; i + 1 < n; i++) {
        if (a[i].first * x1 + a[i].second < a[i + 1].first * x1 + a[i + 1].second &&
                a[i].first * x2 + a[i].second > a[i + 1].first * x2 + a[i + 1].second) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";

    return 0;
}