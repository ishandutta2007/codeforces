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

int pi(string &s, int from, int len) {
    int res = 0;
    for (int i = 0; i < len; i++) {
        res = res * 10 + s[from + i] - '0';
    }
    return res;
}

int cd[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool ok(string &s, int pos) {
    if (pos + 10 > s.length()) {
        return false;
    }
    for (int i = 0; i < 10; i++) {
        if ((i == 2 || i == 5) && s[i + pos] != '-') {
            return false;
        }
        if ((i != 2 && i != 5) && s[i + pos] == '-') {
            return false;
        }
    }

    int dn = pi(s, pos, 2);
    int mn = pi(s, pos + 3, 2);
    int yn = pi(s, pos + 6, 4);
    if (yn < 2013 || yn > 2015) {
        return false;
    }
    if (mn < 1 || mn > 12) {
        return false;
    }

    if (dn < 1 || dn > cd[mn]) {
        return false;
    }
    return true;
}

int main() {
    init_cin
    string s;
    cin >> s;

    map<string, int> cnts;

    int mx = 0;
    string ans;

    for (int i = 0; i < s.length(); i++) {
        if (ok(s, i)) {
            string ss = s.substr(i, 10);
            int x = ++cnts[ss];
            if (x > mx) {
                mx = x;
                ans = ss;
            }
        }
    }
    cout << ans;
    return 0;
}