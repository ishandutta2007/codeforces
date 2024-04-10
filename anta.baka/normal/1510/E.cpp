#ifndef DEBUG
#pragma GCC optimize("O3")
#endif

#include <bits/stdc++.h>

using namespace std;
using ld = double;

const ld eps = 1e-9;
const ld three = 1.0 / 3.0;

bool eq(ld a, ld b) {
    return abs(a - b) < eps;
}

struct P {
    ld x{}, y{};
    P() = default;
    P(ld x, ld y) : x(x), y(y) {}
    bool operator == (const P& o) const {
        return eq(x, o.x) && eq(y, o.y);
    }
    P operator + (const P& o) const {
        return {x + o.x, y + o.y};
    }
    P operator - (const P& o) const {
        return {x - o.x, y - o.y};
    }
    P operator * (const ld& a) const {
        return {x * a, y * a};
    }
    P operator / (const ld& a) const {
        return {x / a, y / a};
    }
    bool operator < (const P& o) const {
        if (*this == o) {
            return false;
        }
        return x < o.x || eq(x, o.x) && y < o.y;
    }
};

struct LHS {
    P m;
    int msk;
    int s2;
    int bal;
};

int rev(int msk, int m) {
    int res = 0;
    for (int i = 0; i < m; i++) {
        if (!(msk >> (m - 1 - i) & 1)) {
            res ^= (1 << i);
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    int n;
    P c;
    cin >> n >> c.x >> c.y;

    int m = n / 2;
    vector<vector<map<P, int>>> pre(19, vector<map<P, int>>(400));
    vector<LHS> kek;
    for (int msk = 0; msk < (1 << m); msk++) {
        int bal = 0;
        P cur;
        vector<P> p = { cur };
        for (int i = 0; i < m && bal >= 0; i++) {
            if (msk >> i & 1) {
                bal++;
                cur = cur + P(1, 1);
            } else {
                bal--;
                cur = cur + P(1, -1);
            }
            p.push_back(cur);
        }
        p.emplace_back(static_cast<ld>(m), 0);
        reverse(p.begin(), p.end());
        if (bal < 0) {
            continue;
        }
        int s2 = 0;
        P centr;
        for (int i = 0; i < p.size(); i++) {
            P one = p[i];
            P two = p[(i + 1) % p.size()];
            int cur2s = (int) (one.x * two.y - one.y * two.x);
            s2 += cur2s;
            centr = centr + P((one.x + two.x) * three, (one.y + two.y) * three) * cur2s * 0.5;
        }
        s2 = abs(s2);
        centr = centr / (0.5 * s2);
        kek.push_back({ centr, msk, s2, bal });
        pre[bal][s2][P(n - centr.x, centr.y)] = rev(msk, m);
    }
    for (auto lhs : kek) {
        P ml = lhs.m;
        int s2l = lhs.s2;
        int bal = lhs.bal;
        for (int s2r = 1; s2r < pre[0].size(); s2r++) {
            if (pre[bal][s2r].empty()) {
                continue;
            }
            // c = (ml * s2l + mr * s2r) / (s2l + s2r)
            P mr = (c * (s2l + s2r) - ml * s2l) / s2r;
            if (pre[bal][s2r].count(mr)) {
                for (int i = 0; i < m; i++) {
                    if (lhs.msk >> i & 1) {
                        cout << '(';
                    } else {
                        cout << ')';
                    }
                }
                int mskr = pre[bal][s2r][mr];
                for (int i = 0; i < m; i++) {
                    if (mskr >> i & 1) {
                        cout << '(';
                    } else {
                        cout << ')';
                    }
                }
                cout.flush();
                return 0;
            }
        }
    }
    assert(false);
}