#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <cmath>
#include <algorithm>
#include <assert.h>
#include <vector>
#include <cstring>
#include <random>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

struct pt {
    ll x, y;
    pt() {}
    pt(ll x, ll y) : x(x), y(y) {}
    pt operator-(const pt& other) const {
        return {x - other.x, y - other.y};
    }
};

ll cross(const pt& p, const pt& q) {
    return p.x * q.y - p.y * q.x;
}

ll dot(const pt& p, const pt& q) {
    return p.x * q.x + p.y * q.y;
}

struct line {
    ll a, b, c;
    line() {}
    line(const pt& p, const pt& q) {
        a = p.y - q.y;
        b = q.x - p.x;
        c = cross(p, q);
    }
};

int sgn(ll val) {
    if (val > 0) {
        return 1;
    } else if (val == 0) {
        return 0;
    } else {
        return -1;
    }
}

bool diff(const pt& a, const pt& b, const line& l) {
    int x = sgn(a.x * l.a + a.y * l.b + l.c);
    int y = sgn(b.x * l.a + b.y * l.b + l.c);
    return ((x == -1 && y == 1) || (x == 1 && y == -1));
}

bool onSegment(const pt& p, const pt& a, const pt& b) {
    pt u = a - p, v = b - p;
    return cross(u, v) == 0 && dot(u, v) <= 0;
}

vector<pt> a, b;
int n;

vector<int> ans;

mt19937 rr(998244353);

const ll inf = 1e9;

void solve(vector<int> x, vector<int> y) {
    //cout << "!" << sz(x) << " " << sz(y) << endl;
    if (sz(x) == 1 && sz(y) == 1) {
        ans[x[0]] = y[0];
        return;
    }
    int zz;
    vector<pll> events;
    while (true) {
        int ii = rr() % sz(x);
        int jj = rr() % sz(y);
        line l(a[x[ii]], b[y[jj]]);
        events.clear();
        for (int i = 0; i < sz(x); ++i) {
            ll val = -l.a * a[x[i]].x - l.b * a[x[i]].y;
            events.pb({val, i});
        }

        for (int i = 0; i < sz(y); ++i) {
            ll val = -l.a * b[y[i]].x - l.b * b[y[i]].y;
            events.pb({val, i + sz(x)});
        }
        sort(all(events));
        int opt = -1;
        int cntx = 0, cnty = 0;
        //assert((events[0].second >= 2 && events[1].second >= 2) || (events[0].second < 2 && events[1].second < 2));
        for (pll& e : events) {
            //cout << "!" << e.first << " " << e.second << "\n";
            if (e.second < sz(x)) {
                ++cntx;
            } else {
                ++cnty;
            }
            if (cntx == cnty) {
                if (cntx == sz(x)) {
                    break;
                }
                if (opt == -1) {
                    opt = cntx;
                } else {
                    if (abs(sz(x) / 2 - opt) > abs(sz(x) / 2 - cntx)) {
                        opt = cntx;
                    }
                }
            }
        }
        if (opt == -1) {
            continue;
        }
        zz = opt;
        break;
    }

    vector<int> xl, xr, yl, yr;
    int cntx = 0, cnty = 0;
    //cout << "!!!!!!!!!!!" << sz(x) << " " << zz << endl;
    for (pll& e : events) {
        if (e.second < sz(x)) {
            if (cntx < zz) {
                xl.pb(x[e.second]);
            } else {
                xr.pb(x[e.second]);
            }
            ++cntx;
        } else {
            if (cnty < zz) {
                yl.pb(y[e.second - sz(x)]);
            } else {
                yr.pb(y[e.second - sz(x)]);
            }
            ++cnty;
        }
    }

    //assert(sz(xl) < sz(x));
    //assert(sz(xr) < sz(x));

    solve(xl, yl);
    solve(xr, yr);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    //n = 100;
    a.resize(n);
    b.resize(n);

    for (int i = 0; i < n; ++i) {
        //a[i].x = rr() % 10000;
        //a[i].y = rr() % 10000;
        cin >> a[i].x >> a[i].y;
    }
    for (int i = 0; i < n; ++i) {
        //b[i].x = rr() % 10000;
        //b[i].y = rr() % 10000;
        cin >> b[i].x >> b[i].y;
    }

    vector<int> id(n);
    for (int i = 0; i < n; ++i) {
        id[i] = i;
    }

    ans.assign(n, -1);

    solve(id, id);

    for (int i = 0; i < n; ++i) {
        cout << ans[i] + 1 << " ";
    }
    cout << "\n";

}