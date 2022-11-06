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

map<lint, int> m;

lint tok(int x, int y) {
    return 1LL * x * lint(1e9) + y;
}

int get(lint x) {
    map<lint, int>::iterator it = m.find(x);
    if (it == m.end()) {
        return -1;
    }
    return it->second;
}

int get(int x, int y) {
    return get(tok(x, y));
}

void st(int x, int y, int v) {
    m[tok(x, y)] = v;
}

int main() {
    sciid(x0, y0);
    --x0; --y0;
    sciid(x1, y1);
    --x1; --y1;
    scid(n);
    for (int i = 0; i < n; i++) {
        sciiid(r, a, b);
        --r; --a; --b;
        for (int j = a; j <= b; j++) {
            st(r, j, 1e9);
        }
    }

    st(x0, y0, 0);
    queue<int> q;
    q.push(x0);
    q.push(y0);
    while (!q.empty()) {
        int vx = q.front(); q.pop();
        int vy = q.front(); q.pop();
        int v = get(vx, vy);
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                int x = vx + i;
                int y = vy + j;
                int t = get(x, y);
                if (t != -1 && t > v + 1) {
                    st(x, y, v + 1);
                    q.push(x);
                    q.push(y);
                }
            }
        }
    }

    int t = get(x1, y1);
    if (t == 1e9) {
        t = -1;
    }

    cout << t;

    return 0;
}