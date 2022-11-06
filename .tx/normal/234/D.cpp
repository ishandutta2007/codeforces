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

bool fav[111];

struct film {
    string name;
    int mn, mx;
};

film a[111];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    init_cin
    int m, k;
    cin >> m >> k;
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        fav[--x] = true;
    }
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;
        int t;
        cin >> t;
        int c0 = 0;
        int cf = 0;
        int cnf = 0;
        for (int j = 0; j < t; j++) {
            int x;
            cin >> x;
            --x;
            if (x != -1) {
                if (fav[x]) {
                    cf++;
                } else {
                    cnf++;
                }
            } else {
                c0++;
            }
        }
        int mn = cf + max(0, c0 - (m - k - cnf));
        int mx = min(k, cf + c0);
        a[i] = film{name, mn, mx};
    }

    for (int i = 0; i < n; i++) {
        int mx = -1;
        int mn = -1;
        for (int j = 0; j < n; j++) {
            if (i != j) {
                mx = max(mx, a[j].mx);
                mn = max(mn, a[j].mn);
            }
        }
        if (a[i].mn >= mx) {
            cout << 0;
        } else if (a[i].mx < mn) {
            cout << 1;
        } else {
            cout << 2;
        }
        cout << "\n";
    }


    return 0;
}