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

int main() {
    scid(n);
    map<int, map<int, int> > a;
    for (int i = 0; i < n; i++) {
        sciid(x, y);
        a[x][y] = -1;
    }
    map<int, vector<int> > w;
    for (int i = 0; i < n; i++) {
        scid(x);
        w[x].push_back(i);
    }

    for (auto& i : w) {
        int t = i.first;
        int x, y;
        if (t < 0) {
            y = 0;
            x = -t;
        } else {
            y = t;
            x = 0;
        }
        for (int j : i.second) {
            if (a[x].find(y) == a[x].end()) {
                cout << "NO";
                return 0;
            }
            a[x][y] = j;
            x++; y++;
        }
    }

    vector<pair<int, int> > ans(n);

    for (int i = 0; i <= 100000; i++) {
        if (a.find(i) == a.end()) {
            break;
        }
        map<int, int>& x = a[i];
        for (int j = 0; j <= 100000; j++) {
            if (x.find(j) == x.end()) {
                break;
            }
            if (j > 0 && x[j - 1] > x[j]) {
                cout << "NO";
                return 0;
            }
            if (i > 0 && a[i - 1][j] > x[j]) {
                cout << "NO";
                return 0;
            }
            ans[x[j]] = {i, j};
        }
    }

    cout << "YES\n";

    for (auto& i : ans) {
        cout << i.first << " " << i.second << "\n";
    }

    return 0;
}