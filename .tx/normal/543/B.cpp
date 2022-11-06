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

vector<int> g[3333];

int d[3333][3333];

int main() {
    sciid(n, m);
    for (int i = 0; i < m; i++) {
        sciid(x, y);
        --x; --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    sciiid(s1, t1, l1);
    --s1; --t1;
    sciiid(s2, t2, l2);
    --s2; --t2;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            d[i][j] = 1e9;
        }
    }

    for (int s = 0; s < n; s++) {
        d[s][s] = 0;
        queue<int> q;
        q.push(s);
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int i : g[v]) {
                if (d[s][i] > d[s][v] + 1) {
                    d[s][i] = d[s][v] + 1;
                    q.push(i);
                }
            }
        }
    }

    int ans = -1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int ws1 = d[s1][i];
            int ws2 = d[s2][i];
            int wt1 = d[j][t1];
            int wt2 = d[j][t2];
            int wc = d[i][j];
            if (ws1 + wc + wt1 <= l1 && ws2 + wc + wt2 <= l2) {
                ans = max(ans, m - ws1 - ws2 - wt1 - wt2 - wc);
            }
            ws2 = d[s2][j];
            wt2 = d[i][t2];
            if (ws1 + wc + wt1 <= l1 && ws2 + wc + wt2 <= l2) {
                ans = max(ans, m - ws1 - ws2 - wt1 - wt2 - wc);
            }
        }
    }

    if (d[s1][t1] <= l1 && d[s2][t2] <= l2) {
        ans = max(ans, m - d[s1][t1] - d[s2][t2]);
    }

    cout << ans;


    return 0;
}