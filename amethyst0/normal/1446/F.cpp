#pragma comment(linker, "/STACK:1000000000")
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <cassert>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <ctime>
#include <random>
#include <bitset>
#include <limits.h>
#include <fstream>

#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define pll pair <ll, ll>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pss pair <short, short>
typedef long double ld;
#define uint unsigned int
#define mp make_pair

const int maxn = (int)1e5 + 10;

struct vt {
    ld x, y;
};

vt operator -(vt a, vt b) {
    a.x -= b.x;
    a.y -= b.y;
    return a;
}

vt operator +(vt a, vt b) {
    a.x += b.x;
    a.y += b.y;
    return a;
}

vt operator *(vt a, ld x) {
    a.x *= x;
    a.y *= x;
    return a;
}

ld dst(vt a) {
    return hypotl(a.x, a.y);
}

vt operator /(vt a, ld x) {
    a.x /= x;
    a.y /= x;
    return a;
}

const ld eps = 1e-18;

vector <vt> inter(vt a, ld r) {
    ld d = dst(a);
    if (d * d <= r * r) {
        return {};
    }

    ld x = r * r / d;
    ld y = r * sqrt(1. - (r / d) * (r / d));
    vt b = a * (x / dst(a));
    vt n = { -a.y, a.x };
    n = n / dst(n);
    return { b - n * y, b + n * y };
}

ld operator *(vt a, vt b) {
    return a.x * b.y - a.y * b.x;
}

int tp(vt a) {
    return a.y > eps || (abs(a.y) < eps && a.x > eps);
}

vt v[maxn];

bool operator <(vt a, vt b) {
    int tpa = tp(a);
    int tpb = tp(b);
    if (tpa != tpb) {
        return tpa < tpb;
    }

    return a * b > eps;
}

int tr[4 * maxn];

void change(int pos) {
    for (; pos < 4 * maxn; pos |= pos + 1) {
        tr[pos]++;
    }
}

int go(int pos) {
    int ans = 0;

    for (; pos >= 0; pos = (pos & (pos + 1)) - 1) {
        ans += tr[pos];
    }
    return ans;
}

int go(int l, int r) {
    return go(r) - go(l - 1);
}

ostream& operator <<(ostream &out, vt a) {
    return out << a.x << ' ' << a.y;
}

mt19937 rr;

int main() {
    int n;
    ll k;
    cin >> n >> k;
    //n = (int)1e5;
    //k = 10000000;

    for (int i = 0; i < n; i++) {
        cin >> v[i].x >> v[i].y;
        //v[i].x = rr() % 20001 - 10001;
        //v[i].y = rr() % 20001 - 10001;
    }

    k = (ll)n * (n - 1) / 2 - k;

    ld l = 0;
    ld r = sqrt(2.) * 1e4;

    for (int itr = 0; itr < 36; itr++) {
        ld m = (l + r) / 2;

        vector <vt> g;

        vector <pair <vt, vt> > f;

        for (int i = 0; i < n; i++) {
            auto a = inter(v[i], m);

            if (a.empty()) {
                continue;
            }

            f.push_back(mp(a[0], a[1]));
            g.push_back(a[0]);
            g.push_back(a[1]);
        }

        sort(all(g));

        vector <pii> a;

        memset(tr, 0, sizeof tr);

        for (int i = 0; i < (int)f.size(); i++) {
            a.push_back(mp(lower_bound(all(g), f[i].first) - g.begin(), lower_bound(all(g), f[i].second) - g.begin()));

            if (a.back().first > a.back().second) {
                change(a.back().second);
                a.back().second += (int)g.size();
            }
        }

        sort(all(a));

        ll tot = 0;

        for (int i = 0; i < (int)a.size(); i++) {
            tot += go(a[i].first, a[i].second);
            change(a[i].second);
        }

        if (tot <= k) {
            r = m;
        }
        else {
            l = m;
        }
    }

    printf("%.10lf\n", (double)r);
    //cout << (ld)clock() / CLOCKS_PER_SEC << '\n';
}