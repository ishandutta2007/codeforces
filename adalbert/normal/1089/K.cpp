#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

#define double ld
#define pb push_back
#define fir first
#define sec second
#define int long long

const double EPS = 1e-9;
const double INF = 1e18;

int v[5000000];
int sum[5000000], push[5000000];

void change1(int i, int tl, int tr, int x, int y) {
    if (tl == tr) {
        sum[i] += y;
        return;
    }

    int d = (tl + tr) / 2;

    if (x <= d)
        change1(i * 2, tl, d, x, y); else
        change1(i * 2 + 1, d + 1, tr, x, y);

    sum[i] = sum[i * 2] + sum[i * 2 + 1];
}

int get1(int i, int tl, int tr, int l, int r) {
    if (tl >= l && tr <= r)
        return sum[i];

    if (tl > r || tr < l)
        return 0;

    int d = (tl + tr) / 2;

    return get1(i * 2, tl, d, l, r) + get1(i * 2 + 1, d + 1, tr, l, r);
}

void make_push(int i) {
    if (push[i] == 0)
        return;

    push[i * 2] += push[i];
    push[i * 2 + 1] += push[i];

    v[i * 2] += push[i];
    v[i * 2 + 1] += push[i];

    push[i] = 0;
}

void change2(int i, int tl, int tr, int l, int r, int y) {
    if (tl >= l && tr <= r) {
        v[i] += y;
        push[i] += y;
        return;
    }

    if (tl > r || tr < l)
        return;

    int d = (tl + tr) / 2;

    make_push(i);

    change2(i * 2, tl, d, l, r, y);
    change2(i * 2 + 1, d + 1, tr, l, r, y);

    v[i] = max(v[i * 2], v[i * 2 + 1]);
}

int get2(int i, int tl, int tr, int l, int r) {
    if (tl >= l && tr <= r)
        return v[i];

    if (tl > r || tr < l)
        return -1e18;

    make_push(i);
    int d = (tl + tr) / 2;

    return max(get2(i * 2, tl, d, l, r), get2(i * 2 + 1, d + 1, tr, l, r));
}

int mx = 1e6 + 10;

int t[400000], d[400000];

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;

    for (int i = 1; i <= mx; i++)
        change2(1, 1, mx, i, i, i);

    for (int i = 1; i <= n; i++){
        char c;
        cin >> c;
        if (c == '+') {
            cin >> t[i] >> d[i];
            change1(1, 1, mx, t[i], d[i]);
            change2(1, 1, mx, t[i] + 1, mx, -d[i]);
        } else
        if (c == '?') {
            cin >> t[i];

            cout << get2(1, 1, mx, 1, t[i]) + get1(1, 1, mx, 1, t[i]) - t[i] << '\n';
        } else
        if (c == '-') {
            int i;
            cin >> i;
            change1(1, 1, mx, t[i], -d[i]);
            change2(1, 1, mx, t[i] + 1, mx, +d[i]);
        }
    }
}