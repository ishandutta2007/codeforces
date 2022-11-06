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

vector<int> calcZ(string& s) {
    int n = s.length();
    vector<int> z(n);
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
    }
    return z;
}

int main() {
    string s, t;
    cin >> s >> t;
    vector<int> zs = calcZ(s);
    vector<int> zt = calcZ(t);
    int nop = 0;
    for (int i = 0; i < min(s.length(), t.length()); i++) {
        if (s[i] == t[i]) {
            nop++;
        } else {
            break;
        }
    }
    int ans = 0;
    for (int i = 1; i <= nop; i++) {
        if (s.length() % i != 0 || i < s.length() && zs[i] < s.length() - i) {
            continue;
        }
        if (t.length() % i != 0 || i < t.length() && zt[i] < t.length() - i) {
            continue;
        }
        ans++;
    }
    cout << ans;
    return 0;
}