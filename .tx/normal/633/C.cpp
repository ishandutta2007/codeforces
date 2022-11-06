#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <string>
#include <memory.h>

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

#define scid(a) int a; sci(a)
#define sciid(a, b) int a, b; scii(a, b)
#define sciiid(a, b, c) int a, b, c; sciii(a, b, c)

#define rea(a, n) for (int i = 0; i < n; i++) sci(a[i])

#define init_cin ios_base::sync_with_stdio(false); cin.tie(0);

typedef long long lint;

using namespace std;

char toLow(char c) {
    if (c >= 'a' && c <= 'z') {
        return c;
    }
    return c - 'A' + 'a';
}

bool can[11111];
string ww[11111];

int main() {
    init_cin
    int n;
    cin >> n;
    string a;
    cin >> a;
    unordered_set<string> s;
    unordered_map<string, string> tow;
    int m;
    cin >> m;
    s.reserve(m);
    tow.reserve(m);
    for (int i = 0; i < m; i++) {
        string t;
        cin >> t;
        string x = t;
        for (int j = 0, len = t.length(); j < len; j++) {
            x[j] = toLow(t[len - 1 - j]);
        }
        s.insert(x);
        tow[x] = t;
    }
    can[0] = true;
    for (int i = 0; i < n; i++) {
        if (can[i]) {
            string cur = "";
            for (int j = 1; j <= 1000 && i + j <= n; j++) {
                cur += a[i + j - 1];
                if (can[i + j]) {
                    continue;
                }
                if (s.find(cur) != s.end()) {
                    can[i + j] = true;
                    ww[i + j] = cur;
                }
            }
        }
    }
    vector<string> ans;
    int x = n;
    while (x > 0) {
        ans.push_back(ww[x]);
        x = x - ww[x].length();
    }
    reverse(ans.begin(), ans.end());
    for (string i : ans) {
        cout << tow[i] << " ";
    }

    //bla

    return 0;
}