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

bool valid(const pt& a, const pt& b, const pt& c, const pt& d) {
    if (onSegment(a, c, d) || onSegment(b, c, d) || onSegment(c, a, b) || onSegment(d, a, b)) {
        return false;
    }
    line l(a, b), m(c, d);
    if (diff(a, b, m) && diff(c, d, l)) {
        return false;
    }
    return true;
}

vector<pt> a;
vector<pt> b;
vector<int> mt;
int n;
bool ok = false;

void f(int pos) {
    if (pos == n) {
        ok = true;
        return;
    }
    for (int j = 0; j < n; ++j) {
        if (mt[j] != -1) {
            continue;
        }
        pt p = a[pos], q = b[j];
        bool t = true;
        for (int k = 0; k < n; ++k) {
            if (mt[k] != -1) {
                if (!valid(p, q, b[k], a[mt[k]])) {
                    t = false;
                    break;
                }
            }
        }
        if (t) {
            mt[j] = pos;
            f(pos + 1);
            if (ok) {
                return;
            }
            mt[j] = -1;
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int x, y;
    cin >> x >> y;
    if (x != y) {
        cout << "No\n";
        return 0;
    }

    n = x;
    a.resize(n);
    b.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].x >> a[i].y;
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i].x >> b[i].y;
    }

    mt.assign(n, -1);
    f(0);

    cout << (ok ? "Yes\n" : "No\n");

}