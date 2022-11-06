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

using namespace std;

vector<int> p[256];

int main() {
    init_cin;
    string s, t;
    cin >> s >> t;
    for (int i = 0; i < s.length(); i++) {
        p[s[i]].push_back(i);
    }
    int ans = 1;
    int cp = -1;
    for (char c : t) {
        if (p[c].empty()) {
            cout << -1;
            return 0;
        }
        if (cp >= p[c].back()) {
            ans++;
            cp = p[c].front();
        } else {
            cp = *upper_bound(p[c].begin(), p[c].end(), cp);
        }
    }
    cout << ans;

    return 0;
}