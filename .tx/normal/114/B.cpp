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

bool bad[22][22];
string bi[22];

int main() {
    init_cin
    int n, m;
    cin >> n >> m;
    map<string, int> bn;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        bn[s] = i;
        bi[i] = s;
    }
    for (int i = 0; i < m; i++) {
        string s, t;
        cin >> s >> t;
        int x = bn[s];
        int y = bn[t];
        bad[x][y] = bad[y][x] = true;
    }

    int ans = 0;
    int ams = 0;

    for (int ms = 0; ms < (1 << n); ms++) {
        bool ok = true;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if ((ms & (1 << i)) && (ms & (1 << j)) && bad[i][j]) {
                    ok = false;
                }
            }
        }
        if (ok) {
            int pc = __builtin_popcount(ms);
            if (pc > ans) {
                ans = pc;
                ams = ms;
            }
        }
    }

    cout << ans << "\n";

    vector<string> ns;
    for (int i = 0; i < n; i++) {
        if (ams & (1 << i)) {
            ns.push_back(bi[i]);
        }
    }
    sort(ns.begin(), ns.end());
    for (string& i : ns) {
        cout << i << "\n";
    }
    return 0;
}