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

lint gcd(lint a, lint b) {
    return b == 0 ? a : gcd(b, a % b);
}

int cnt[26][2222222];

lint calc(string& s, string& t) {
    int n = s.length();
    int m = t.length();
    for (int i = 0; i < 2 * m; i++) {
        for (int j = 0; j < 26; j++) {
            cnt[j][i] = i ? cnt[j][i - 1] : 0;
        }
        cnt[t[i % m] - 'a'][i]++;
    }
    lint res = 0;
    for (int i = 0; i < n; i++) {
        int c = s[i] - 'a';
        res += cnt[c][m - 1 + i];
        if (i) {
            res -= cnt[c][i - 1];
        }
    }
    return res;
}

int main() {
    init_cin
    lint n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    lint ls = s.length();
    lint lt = t.length();
    if (ls > lt) {
        swap(s, t);
        swap(ls, lt);
        swap(n, m);
    }
    lint g = gcd(ls, lt);
    lint ans = 0;
    for (int tt = 0; tt < g; tt++) {
        string st = "";
        for (int i = tt; i < lt; i += g) {
            st += t[i];
        }
        string ss = "";
        for (int i = tt; i < ls; i += g) {
            ss += s[i];
        }
        ans += calc(ss, st);
    }
    ans *= n / (lt / g);
    cout << ls * n - ans;

    return 0;
}