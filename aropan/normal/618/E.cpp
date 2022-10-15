#include <iostream>
#include <cstdio>
#include <cassert>
#include <ctime>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }
template <typename T> T gcd(T a, T b) { return b? gcd(b, a % b) : a; }

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int MAXN = 300002;
const int MAXT = 4 * MAXN;
const ld EPS = 1e-12;
const ld PI = 3.141592653589793238462643383279;

ld a[MAXT];
ld d[MAXT];
ld dx[MAXT];
ld dy[MAXT];

void build_tree(int i, int l, int r)
{
    if (r - l == 1) {
        a[i] = 0;
        d[i] = 1;
        dx[i] = cos(a[i]) * d[i];
        dy[i] = sin(a[i]) * d[i];
        return;
    }
    int c = (l + r) / 2;
    build_tree(2 * i + 0, l, c);
    build_tree(2 * i + 1, c, r);

    dx[i] = dx[2 * i + 0] + dx[2 * i + 1];
    dy[i] = dy[2 * i + 0] + dy[2 * i + 1];
}

void update(int i, ld v)
{
    a[i] += v;
    ld dx_ = dx[i] * cos(v) - dy[i] * sin(v);
    ld dy_ = dx[i] * sin(v) + dy[i] * cos(v);
    dx[i] = dx_;
    dy[i] = dy_;
}

void modify(int i, int l, int r, int type, int ind, ld val)
{
    if (r - l == 1) {
        if (type == 1) {
            d[i] += val;
        } else {
            a[i] += val;
        }
        dx[i] = cos(a[i]) * d[i];
        dy[i] = sin(a[i]) * d[i];
        return;
    }

    if (abs(a[i]) > EPS) {
        update(2 * i + 0, a[i]);
        update(2 * i + 1, a[i]);
        a[i] = 0;
    }

    int c = (l + r) / 2;
    if (ind < c) {
        modify(2 * i + 0, l, c, type, ind, val);
        if (type == 2) {
            update(2 * i + 1, val);
        }
    } else {
        modify(2 * i + 1, c, r, type, ind, val);
    }

    dx[i] = dx[2 * i + 0] + dx[2 * i + 1];
    dy[i] = dy[2 * i + 0] + dy[2 * i + 1];
}

int main(int /* argc */, char** /* argv */)
{
    ios_base::sync_with_stdio(false);
    #ifdef LOCAL
    assert(freopen("inp", "r", stdin));
    assert(freopen("out", "w", stdout));
    #endif
    cout.precision(10);
    int n;
    while (cin >> n) {
        build_tree(1, 0, n);
        int m;
        cin >> m;
        while (m--) {
            int type, index;
            ld value;
            cin >> type >> index >> value;
            index -= 1;

            if (type == 2) {
                value = value * PI / 180;
                value = -value;
            }

            modify(1, 0, n, type, index, value);
            cout << fixed << dx[1] << " " << fixed << dy[1] << "\n";
        }
    }

    fprintf(stderr, "Time execute: %.3lf sec\n", clock() / (double)CLOCKS_PER_SEC);
    return 0;
}