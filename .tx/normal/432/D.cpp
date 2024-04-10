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

const int MX_S = 111111;

char s[MX_S];
int z[MX_S];
int sz[MX_S];

int main() {
    scanf("%s", s);
    int n = strlen(s);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (i < r) {
            z[i] = min(r - i, z[i - l]);
        }
        while (i + z[i] < n && s[i + z[i]] == s[z[i]]) {
            z[i]++;
        }
        if (i + z[i] > r) {
            r = i + z[i];
            l = i;
        }
        sz[i] = z[i];
    }
    sz[0] = z[0] = n;
    sort(sz, sz + n);
    vector<pair<int, int> > ans;
    for (int i = 0; i < n; i++) {
        if (z[n - 1 - i] == i + 1) {
            int x = lower_bound(sz, sz + n, i + 1) - sz;
            ans.push_back({i + 1, n - x});
        }
    }
    cout << ans.size() << "\n";
    for (auto& i : ans) {
        cout << i.first << " " << i.second << "\n";
    }

    return 0;
}