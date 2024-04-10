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

int n;
string s, t;

char opp(char a, char b) {
    if (a > b) {
        swap(a, b);
    }
    return (a == 'N' && b == 'S') || (a == 'E' && b == 'W');
}

int nxt(int cur, char c, string &s) {
    if (cur < n && s[cur] == c) {
        return cur + 1;
    }
    if (cur > 0 && opp(s[cur - 1], c)) {
        return cur - 1;
    }
    return cur;
}

const char *dir = "NSEW";

bool used[555][555];

bool dfs(int i, int j) {
    if (used[i][j]) {
        return false;
    }
    used[i][j] = true;
    if (i == n && j == n) {
        return true;
    }
    for (int k = 0; k < 4; k++) {
        if (dfs(nxt(i, dir[k], s), nxt(j, dir[k], t))) {
//            cout << i << " " << j << " " << dir[k] << endl;
            return true;
        }
    }
    return false;
}

string getRand(int len) {
    string s;
    for (int i = 0; s.length() < len; i++) {
        char c = dir[rand() % 4];
        if (i == 0 || !opp(c, s.back())) {
            s += c;
        }
    }
    return s;
}

bool ok(string s, string t) {
    int n = s.length();
    char inv[256];
    inv['S'] = 'N';
    inv['N'] = 'S';
    inv['E'] = 'W';
    inv['W'] = 'E';
    for (int i = 0; i < n; i++) {
        t[i] = inv[t[i]];
    }
    for (int i = 0; i * 2 < n; i++) {
        swap(t[i], t[n - 1 - i]);
    }
    lint hs1 = 0;
    lint hs2 = 0;
    lint ht1 = 0;
    lint ht2 = 0;
    lint p1 = 31;
    lint p2 = 239;
    lint ps1 = 1;
    lint ps2 = 1;
    for (int i = 0; i < n; i++) {
        lint sx = s[n - 1 - i] - 'a' + 1;
        hs1 += sx * ps1;
        hs2 += sx * ps2;
        ps1 *= p1;
        ps2 *= p2;
        lint tx = t[i] - 'a' + 1;
        ht1 = ht1 * p1 + tx;
        ht2 = ht2 * p2 + tx;
        if (hs1 == ht1 && hs2 == ht2) {
            return false;
        }
    }
    return true;
}


int main() {
    srand(31);
    init_cin
//    n = 10;
//    s = getRand(n - 5);
//    s += "NWSWN";
//    t = getRand(n - 5);
//    t += "SENES";
//    n = 10;
//    for (int i = 0; i < 100000; i++) {
//        s =  getRand(n);
//        t =  getRand(n);
//        memset(used, false, sizeof(bool) * 555 * 555);
//        bool df = dfs(0, 0);
//        bool fs = ok(s, t);
//        if (df != fs) {
//            cerr << s << endl << t << endl;
//            cerr << "df: " << df << endl << "fs: " << fs << endl;
//            return 0;
//        }
//    }
//    cerr << "OK" << endl;
    cin >> n;
    cin >> s >> t;
    if (ok(s, t)) {
        puts("YES");
    } else {
        puts("NO");
    }

    return 0;
}