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

int z[6666];
int mx[2222];
int mxi[2222];

int n, m;

void calcZ(string& s, int from) {
    int l = 0, r = 0;
    for (int i = 1; i + from < s.length(); i++) {
        z[i] = 0;
        if (i < r) {
            z[i] = min(r - i, z[i - l]);
        }
        while (i + z[i] + from < s.length() && s[i + z[i] + from] == s[z[i] + from]) {
            z[i]++;
        }
        if (i + z[i] > r) {
            r = i + z[i];
            l = i;
        }
    }
    for (int i = m - from; i + from < s.length(); i++) {
        if (z[i] > mx[from]) {
            mx[from] = z[i];
            mxi[from] = i - (m - from) - 1;
        }
    }
}

int main() {
    init_cin
    string s, t;
    cin >> s >> t;
    n = s.length();
    m = t.length();
    string rs = s;
    reverse(rs.begin(), rs.end());
    string tsrs = t + "#" + s + "$" + rs;
    for (int i = 0; i < m; i++) {
        calcZ(tsrs, i);
    }

    vector<int> d(m, 1e9);
    vector<pair<int, int> > pp(m, {-1, -1});
    vector<int> p(m, -1);
    for (int i = 0; i < m; i++) {
        for (int j = i; j >= 0; j--) {
            if (mx[j] > i - j) {
                int costFrom = j == 0 ? 0 : d[j - 1];
                if (d[i] > costFrom + 1) {
                    d[i] = costFrom + 1;
                    p[i] = j;
                    if (mxi[j] < n) {
                        pp[i] = {mxi[j], mxi[j] + i - j};
                    } else {
                        pp[i] = {n - (mxi[j] - n - 1) - 1, n - (mxi[j] - n - 1 + i - j) - 1};
                    }
                }
            }
        }
    }

    vector<pair<int, int> > ans;
    if (d[m - 1] == 1e9) {
        cout << -1;
        return 0;
    }
    int x = m - 1;
    while (x != -1) {
        ans.push_back(pp[x]);
        x = p[x] - 1;
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for (auto& i : ans) {
        cout << i.first + 1 << " " << i.second + 1 << "\n";
    }

    return 0;
}