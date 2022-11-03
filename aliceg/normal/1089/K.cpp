#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <iomanip>
#include <random>
#include <bitset>
#include <cassert>

#define sqr(x) ((x) * (x))
#define F first
#define S second
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(), (a).end()
#define int ll
#define mp(a) make_pair(a)
#define int long long
#ifndef _getchar_nolock
#define _getchar_nolock getchar_unlocked
#define _putchar_nolock putchar_unlocked
#endif

#pragma warning(disable : 4996)
//#pragma comment(linker, "/stack:16777216")
#ifndef LOCAL
#define endl '\n'
#endif

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<char> vc;

const ll INF = 1e18 + 10;
const ld PI = 3.141592653589793;
const ld EPS = 1e-9;
const int N = 1 << 20;
ll lst[N * 2];
ll psh[N * 2];

//[l, r)

int lv(int v) {
    return v * 2;
}

int rv(int v) {
    return v * 2 + 1;
}

void upd(int v) {
    lst[v] = max(lst[lv(v)], lst[rv(v)]);
}

void build() {
    for (ll i = 0; i < N; i++) {
        lst[i + N] = i;
    }
    //for (ll i = N - 2; i >= 0; i--) {
    //    lst[i + N] += lst[i + N + 1];
    //}
    for (int i = N - 1; i > 0; i--) {
        upd(i);
    }
}

void push(int v) {
    if (rv(v) < N * 2) {
        psh[lv(v)] += psh[v];
        psh[rv(v)] += psh[v];
    }
    lst[v] += psh[v];
    psh[v] = 0;
}

void add(int ql, int qr, ll d, int v = 1, int l = 0, int r = N) {
    push(v);
    if (r <= ql || qr <= l) {
        return;
    }
    if (ql <= l && r <= qr) {
        psh[v] = d;
        push(v);
        return;
    }
    int m = (l + r) / 2;
    add(ql, qr, d, lv(v), l, m);
    add(ql, qr, d, rv(v), m, r);
    upd(v);
}

void add(int t, ll d) {
    add(0, t + 1, d);
}

ll query(int ql, int qr, int v = 1, int l = 0, int r = N) {
    push(v);
    if (r <= ql || qr <= l) {
        return -INF;
    }
    if (ql <= l && r <= qr) {
        return lst[v];
    }
    int m = (l + r) / 2;
    ll a = query(ql, qr, lv(v), l, m);
    ll b = query(ql, qr, rv(v), m, r);
    return max(a, b);
}

void solve(int t) {
    ll prf = query(0, t + 1);
    ll cur = query(t + 1, t + 2) - (t + 1);
    cout << max(0ll, prf - cur - t) << endl;
}

void solution() {
    build();
    int n;
    cin >> n;
    unordered_map < int, pii > q;
    for (int i = 1; i <= n; i++) {
        char t;
        cin >> t;
        if (t == '+') {
            int t, d;
            cin >> t >> d;
            add(t, d);
            q[i] = { t, d };
        }
        else if (t == '-') {
            int j;
            cin >> j;
            pii p = q[j];
            add(p.first, -p.second);
        }
        else {
            int t;
            cin >> t;
            solve(t);
        }
    }
}

signed main() {
#ifdef LOCAL
    assert(freopen("input.txt", "r", stdin));
    assert(freopen("output.txt", "w", stdout));
#endif
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int t = 1;
    //cin >> t;
    for (int i = 0; i < t; ++i)
        solution();
    
    return 0;
}