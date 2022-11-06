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

int firstEnter(string& s, string& t) {
    string st = t + "#" + s;
    int n = st.length();
    vector<int> z(n);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (i < r) {
            z[i] = min(r - i, z[i - l]);
        }
        while (i + z[i] < st.length() && st[i + z[i]] == st[z[i]]) {
            z[i]++;
        }
        if (i + z[i] > r) {
            r = i + z[i];
            l = i;
        }
    }
    for (int i = t.length() + 1; i < n; i++) {
        if (z[i] == t.length()) {
            return i - t.length() - 1;
        }
    }
    return -1;
}

bool can(string& s, string& t1, string& t2) {
    int fe = firstEnter(s, t1);
    if (fe == -1) {
        return false;
    }
    int newLen = s.length() - fe - t1.length();
    if (newLen < t2.length()) {
        return false;
    }
    string s1 = s.substr(fe + t1.length(), newLen);
    return firstEnter(s1, t2) != -1;
}

int main() {
    init_cin
    string s, t1, t2;
    cin >> s >> t1 >> t2;

    bool canForward = can(s, t1, t2);
    reverse(s.begin(), s.end());
    bool canBackward = can(s, t1, t2);
    if (canForward && canBackward) {
        cout << "both";
    } else if (canForward) {
        cout << "forward";
    } else if (canBackward) {
        cout << "backward";
    } else {
        cout << "fantasy";
    }

    return 0;
}