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

int sufpos[5555];

lint h1[5555];
lint h2[5555];

int p1 = 31;
int p2 = 239;

lint pow1[5555];
lint pow2[5555];

lint hash1(int l, int r) {
    lint res = h1[r];
    if (l > 0) {
        res -= h1[l - 1] * pow1[r - l + 1];
    }
    return res;
}

lint hash2(int l, int r) {
    lint res = h2[r];
    if (l > 0) {
        res -= h2[l - 1] * pow2[r - l + 1];
    }
    return res;
}

const int mod = 1e9 + 7;

lint d[5555][5555];
lint sd[5555][5555];

int main() {
    init_cin
    int n;
    cin >> n;
    string s;
    cin >> s;
    string t = "";
    vector<pair<string, int> > a;
    for (int i = n - 1; i >= 0; i--) {
        t = s[i] + t;
        a.push_back({t, i});
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        sufpos[a[i].second] = i;
    }
    pow1[0] = pow2[0] = 1;
    for (int i = 1; i < 5555; i++) {
        pow1[i] = pow1[i - 1] * p1;
        pow2[i] = pow2[i - 1] * p2;
    }
    for (int i = 0; i < n; i++) {
        h1[i] = s[i] - '0' + 1;
        h2[i] = s[i] - '0' + 1;
        if (i > 0) {
            h1[i] += h1[i - 1] * p1;
            h2[i] += h2[i - 1] * p2;
        }
    }

    d[0][1] = 1;
    sd[0][1] = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= i + 1; j++) {
            int sj = i - j + 1;
            if (sj == 0) {
                d[i][j] = 1;
                sd[i][j] = (sd[i][j - 1] + 1) % mod;
                continue;
            }
            if (s[sj] == '0') {
                d[i][j] = 0;
                sd[i][j] = sd[i][j - 1];
                continue;
            }
            int t = min(j - 1, i - j + 1);
            d[i][j] = sd[i - j][t];
            if (2 * j <= i + 1) {
                lint hr1 = hash1(i - j + 1, i);
                lint hr2 = hash2(i - j + 1, i);
                lint hl1 = hash1(i - j - j + 1, i - j);
                lint hl2 = hash2(i - j - j + 1, i - j);
                if (!(hr1 == hl1 && hr2 == hl2)) {
                    if (sufpos[i - j - j + 1] < sufpos[i - j + 1]) {
                        d[i][j] += d[i - j][j];
                        d[i][j] %= mod;
                    }
                }
            }
            sd[i][j] = (sd[i][j - 1] + d[i][j]) % mod;
        }
    }

    lint res = 0;
    for (int i = 1; i <= n; i++) {
        res = (res + d[n - 1][i]) % mod;
    }
    cout << res;

    return 0;
}