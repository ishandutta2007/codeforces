#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <string>
#include <memory.h>
#include <bitset>

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

vector<int> getZ(string s) {
    int n = s.length();
    vector<int> z(n);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (r > i) {
            z[i] = min(r - i, z[i - l]);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
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
    init_cin
    string t;
    cin >> t;
    string rt = t;
    reverse(rt.begin(), rt.end());
    int n = t.length();
    int m; cin >> m;
    int ans = 0;
    while (m-- > 0) {
        string s;
        cin >> s;
        int l = s.length();
        vector<int> pref(l, -1);
        vector<int> z = getZ(s + "#" + t);
        for (int i = 0; i < n; i++) {
            int cz = z[i + l + 1] - 1;
            if (cz >= 0 && pref[cz] == -1) {
                pref[cz] = i;
            }
        }

        for (int i = l - 2; i >= 0; i--) {
            if (pref[i + 1] != -1) {
                pref[i] = pref[i] == -1 ? pref[i + 1] : min(pref[i], pref[i + 1]);
            }
        }

        vector<int> suf(l, -1);
        reverse(s.begin(), s.end());
        z = getZ(s + "#" + rt);
        for (int i = 0; i < n; i++) {
            int cz = z[l + 1 + i] - 1;
            if (cz >= 0 && suf[cz] == -1) {
                suf[cz] = n - 1 - (i + cz);
            }
        }

        for (int i = l - 2; i >= 0; i--) {
            if (suf[i + 1] != -1) {
                suf[i] = max(suf[i], suf[i + 1] + 1);
            }
        }

//        if (pref[l - 1] != -1) {
//            ans++;
//            continue;
//        }

        bool ok = false;
        for (int i = 0; i + 1 < l; i++) {
            if (pref[i] != -1 && suf[l - i - 2] != -1 && pref[i] + i < suf[l - i - 2]) {
                ok = true;
                break;
            }
        }
        if (ok) {
            ans++;
        }
    }

    cout << ans;

    return 0;
}