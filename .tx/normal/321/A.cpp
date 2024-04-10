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

int main() {
    sciid(a, b);
    string s;
    cin >> s;
    int n = s.length();
    vector<pair<int, int> > p;
    p.push_back({0, 0});
    int cx = 0, cy = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'R') {
            cx++;
        } else if (s[i] == 'L') {
            cx--;
        } else if (s[i] == 'U') {
            cy++;
        } else if (s[i] == 'D') {
            cy--;
        }
        p.push_back({cx, cy});
    }
    cx = p[n].first - p[0].first;
    cy = p[n].second - p[0].second;
    for (int i = 0; i <= n; i++) {
        int x = p[i].first;
        int y = p[i].second;
        if (a == x && b == y) {
            cout << "Yes";
            return 0;
        }
        if (cx == 0 && cy == 0) {
            continue;
        }
        if (cx == 0) {
            if (a != x) {
                continue;
            }
            if ((b - y) % cy == 0 && (b - y) / cy >= 0) {
                cout << "Yes";
                return 0;
            }
        } else if (cy == 0) {
            if (y != b) {
                continue;
            }
            if ((a - x) % cx == 0 && (a - x) / cx >= 0) {
                cout << "Yes";
                return 0;
            }
        } else {
            if ((a - x) % cx != 0 || (b - y) % cy != 0 || (a - x) / cx != (b - y) / cy || (a - x) / cx < 0) {
                continue;
            }
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";

    return 0;
}