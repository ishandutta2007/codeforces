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

#define scid(a) int a; scanf("%d", &a)
#define sciid(a, b) int a, b; scanf("%d%d", &a, &b)
#define sciiid(a, b, c) int a, b, c; scanf("%d%d%d", &a, &b, &c)

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

#define rveid(a, n) vector<int> a(n); for (int i = 0; i < n; i++) sci(a[i])
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).end()

typedef long long lint;

using namespace std;

void init_cin() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}

int main() {
    init_cin();
    int n, s;
    cin >> n >> s;
    map<int, int> a, b;
    for (int i = 0; i < n; i++) {
        char c;
        int x, y;
        cin >> c >> x >> y;
        if (c == 'S') {
            a[x] += y;
        } else {
            b[x] += y;
        }
    }
    vector<int> as;
    int i = 0;
    for (auto it = a.begin(); i < s && it != a.end(); ++it, ++i) {
        as.push_back(it->first);
    }
    for (int i = int(as.size()) - 1; i >= 0; i--) {
        cout << "S " << as[i] << " " << a[as[i]] << "\n";
    }
    i = 0;
    for (auto it = b.rbegin(); i < s && it != b.rend(); ++it, ++i) {
        cout << "B " << it->first << " " << it->second << "\n";
    }
    return 0;
}