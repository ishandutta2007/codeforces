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
typedef long double ldouble;

using namespace std;

char s[111];

int main() {
    scanf("%s", s);
    int n = strlen(s);
    set<pair<int, int> > ok;
    int cx = 0, cy = 0;
    ok.insert({cx, cy});
    for (int i = 0; i < n; i++) {
        if (s[i] == 'L') {
            cx--;
        } else if (s[i] == 'R') {
            cx++;
        } else if (s[i] == 'D') {
            cy--;
        } else {
            cy++;
        }
        ok.insert({cx, cy});
    }
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    queue<pair<int, int> > q;
    q.push({0, 0});
    map<pair<int, int>, int> d;
    while (!q.empty()) {
        auto v = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int x = v.first + dx[i];
            int y = v.second + dy[i];
            if (ok.find({x, y}) == ok.end() || d.find({x, y}) != d.end()) {
                continue;
            }

            q.push({x, y});
            d[{x, y}] = d[v] + 1;
        }
    }

    if (d[{cx, cy}] == n) {
        cout << "OK";
    } else {
        cout << "BUG";
    }

    return 0;
}