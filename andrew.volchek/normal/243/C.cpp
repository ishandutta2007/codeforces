#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>
#include <queue>
#include <math.h>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <bitset>
#include <list>
#include <ctype.h>
#include <cassert>
#include <stack>
#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include <ctime>
#include <functional>
#include <ctime>

using namespace std;

#define snd second
#define fst first
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define left _left
#define right _right

const ld pi = 3.14159265359;

template<typename T>
T abs(T x) {
    return x > 0 ? x : -x;
}

template<typename T>
T sqr(T x) {
    return x * x;
}

template<typename T>
void chmin(T &x, T y) {
    x = min(x, y);
}

template<typename T>
void chmax(T &x, T y) {
    x = max(x, y);
}

struct sg {
    ll x1, y1, x2, y2;
};


const int maxn = 3333;

char a[maxn][maxn];

int main() {
    srand(time(NULL));

#ifdef LOCAL

    //cerr << 1 << endl;
    freopen("a.in", "r", stdin);
#else
    //freopen("fract.in", "r", stdin);
    //freopen("fract.out", "w", stdout);
#endif

    vector<ll> cx, cy;

    int n;
    scanf("%d\n", &n);

    const ll dd = 10000000001LL;

    ll x = (dd - 1) / 2;
    ll y = (dd - 1) / 2;
    cx.pb(1);
    cx.pb(dd);
    cy.pb(1);
    cy.pb(dd);

    auto add = [&](ll x, vector<ll> &c) {
        c.pb(x - 1);
        c.pb(x);
        c.pb(x + 1);
    };

    add(x, cx);
    add(y, cy);

    vector<sg> s;

    for (int i = 0; i < n; i++) {
        char c;
        int d;
        scanf("%c %d\n", &c, &d);

        ll nx = x, ny = y;

        if (c == 'U') {
            nx += d;
        } else if (c == 'D') {
            nx -= d;
        } else if (c == 'R') {
            ny += d;
        } else if (c == 'L') {
            ny -= d;
        } else {
            assert(0);
        }

        add(nx, cx);
        add(ny, cy);

        s.pb({x, y, nx, ny});
        x = nx;
        y = ny;
    }

    sort(cx.begin(), cx.end());
    cx.resize(unique(cx.begin(), cx.end()) - cx.begin());

    sort(cy.begin(), cy.end());
    cy.resize(unique(cy.begin(), cy.end()) - cy.begin());

    for (auto &x : s) {
        x.x1 = lower_bound(cx.begin(), cx.end(), x.x1) - cx.begin();
        x.x2 = lower_bound(cx.begin(), cx.end(), x.x2) - cx.begin();

        if (x.x1 > x.x2) {
            swap(x.x1, x.x2);
        }

        x.y1 = lower_bound(cy.begin(), cy.end(), x.y1) - cy.begin();
        x.y2 = lower_bound(cy.begin(), cy.end(), x.y2) - cy.begin();

        if (x.y1 > x.y2) {
            swap(x.y1, x.y2);
        }

        for (int xx = x.x1; xx <= x.x2; xx++) {
            for (int yy = x.y1; yy <= x.y2; yy++) {
                a[xx][yy] = 1;
            }
        }
    }

    queue<pair<int,int>> q;
    q.push(mp(0, 0));
    a[0][0] = 2;
    while (!q.empty()) {
        auto c = q.front();
        q.pop();
        const int dirs[4][2] = {
                1, 0,
                -1, 0,
                0, 1,
                0, -1,
        };

        for (int i = 0; i < 4; i++) {
            int cx = c.fst + dirs[i][0];
            int cy = c.snd + dirs[i][1];

            if (cx < 0 || cx >= maxn || cy < 0 || cy >= maxn) {
                continue;
            }

            if (a[cx][cy] != 0) {
                continue;
            }

            a[cx][cy] = 2;
            q.push(mp(cx, cy));
        }
    }

    ll ans = 0;

    for (int i = 1; i + 1 < maxn; i++) {
        for (int j = 0; j < maxn; j++) {
            if (a[i][j] == 2) {
                continue;
            }
            int h = j;

            while (h < maxn && a[i][h] != 2) {
                h++;
            }

            ll ylen = cy[h - 1] - cy[j] + 1;

            bool all = true;
            for (int g = j; g < h; g++) {
                all &= a[i - 1][g] != 2;
            }

            if (all) {
                ans += ylen * (cx[i] - cx[i - 1]);
            } else {
                ans += ylen;
            }

            j = h - 1;
        }
    }

    cout << ans << endl;


    return 0;
}