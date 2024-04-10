#include <bits/stdc++.h>
using namespace std;

template<typename T>
void sci(T& t) {
    cin >> t;
}

template<typename T, typename... Ts>
void sci(T& t, Ts&... ts) {
    sci(t);
    sci(ts...);
};

#define scid(vars...) int vars; sci(vars)
#define scidl(vars...) lint vars; sci(vars)
#define scidd(vars...) double vars; sci(vars)
#define scids(vars...) string vars; sci(vars)

typedef long long lint;

struct pt {
    int x, y, id;
};

lint ans[111111];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    scid(n, m, k);
    unordered_map<int, vector<pt>> d1(3 * k), d2(3 * k);

    for (int i = 0; i < k; i++) {
        scid(x, y);
        d1[x - y].push_back(pt{x, y, i});
        d2[x + y].push_back(pt{x, y, i});
    }

//    set<pair<int, int> > wd;
    fill(ans, ans + k, (lint) 1e18);

    int cd = 0;
    lint ct = 0;
    int cx = 0, cy = 0;
    int dir = 0;
    int cit = 3 * (n + m);
    for (int i = 0; cit-- > 0; i = 1 - i) {
        if (i == 0) {
            for (auto& p : d1[cd]) {
                ans[p.id] = min(ans[p.id], ct + abs(cx - p.x));
            }
        } else {
            for (auto& p : d2[cd]) {
                ans[p.id] = min(ans[p.id], ct + abs(cx - p.x));
            }
        }
        int ocx = cx;
        int ocy = cy;

        if (dir == 0) {
            if (n - cx == m - cy) {
                cx = n;
                cy = m;
                dir = 2;
            } else if (n - cx < m - cy) {
                dir = 1;
                cy += n - cx;
                cx = n;
            } else {
                dir = 3;
                cx += m - cy;
                cy = m;
            }
        } else if (dir == 1) {
            if (cx == m - cy) {
                dir = 3;
                cx = 0;
                cy = m;
            } else if (cx < m - cy) {
                dir = 0;
                cy += cx;
                cx = 0;
            } else {
                dir = 2;
                cx -= m - cy;
                cy = m;
            }
        } else if (dir == 2) {
            if (cx == cy) {
                dir = 0;
                cx = cy = 0;
            } else if (cx < cy) {
                dir = 3;
                cy -= cx;
                cx = 0;
            } else {
                dir = 1;
                cx -= cy;
                cy = 0;
            }
        } else {
            if (n - cx == cy) {
                dir = 1;
                cx = n;
                cy = 0;
            } else if (n - cx < cy) {
                dir = 2;
                cy -= n - cx;
                cx = n;
            } else {
                dir = 0;
                cx += cy;
                cy = 0;
            }
        }
        if (i == 1) {
            cd = cx - cy;
        } else {
            cd = cx + cy;
        }

        ct += abs(ocx - cx);
    }

    for (int i = 0; i < k; i++) {
        if (ans[i] == 1e18) {
            cout << -1;
        } else {
            cout << ans[i];
        }
        cout << "\n";
    }

    return 0;
}