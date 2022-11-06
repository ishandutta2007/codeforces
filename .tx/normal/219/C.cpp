#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <memory.h>

#define scid(a) int a; scanf("%d", &a)
#define sciid(a, b) int a, b; scanf("%d%d", &a, &b)
#define sciiid(a, b, c) int a, b, c; scanf("%d%d%d", &a, &b, &c)

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

#define rveid(a, n) vector<int> a(n); for (int i = 0; i < n; i++) sci(a[i])

typedef long long lint;

using namespace std;

void init_cin() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}

int case2(string &s) {
    int res = 0;
    int n = s.length();
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i - 1]) {
            res++;
            s[i] = (s[i - 1] - 'A' + 1) % 2 + 'A';
        }
    }
    return res;
}

int main() {
    sciid(n, k);
    string s;
    cin >> s;
    if (k == 2) {
        string t = s;
        t[0] = (t[0] - 'A' + 1) % 2 + 'A';
        int a1 = case2(s);
        int a2 = case2(t) + 1;
        if (a1 < a2) {
            cout << a1 << "\n" << s;
        } else {
            cout << a2 << "\n" << t;
        }
        return 0;
    }

    int ans = 0;
    for (int i = 1; i < n; i++) {
        if (s[i - 1] == s[i]) {
            ans++;
            if (i + 1 == n) {
                s[i] = (s[i - 1] - 'A' + 1) % k + 'A';
            } else {
                for (char j = 'A'; j <= 'C'; j++) {
                    if (j != s[i - 1] && j != s[i + 1]) {
                        s[i] = j;
                        break;
                    }
                }
            }
        }
    }
    cout << ans << "\n" << s;

    return 0;
}