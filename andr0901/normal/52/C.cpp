#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

#define forn(i, s, f) for (int i = s; i < f; i++)
#define ll long long
#define ld long double
#define pii pair <int, int>
#define fs first
#define sc second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

int parse(const string& s, int l, int r) {
    int ans = 0, sign = 1;
    forn (i, l, r) {
        if ('0' <= s[i] && s[i] <= '9')
            ans = 10 * ans + s[i] - '0';
        if (s[i] == '-')
            sign = -1;
    }
    return sign * ans;
}

vector <int> a;
vector <ll> tr, to_add;

void build(int v, int vl, int vr) {
    if (vr - vl == 1) {
        tr[v] = a[vl];
        return;
    }
    int vm = vl + vr >> 1;
    build(2 * v, vl, vm), build(2 * v + 1, vm, vr);
    tr[v] = min(tr[2 * v], tr[2 * v + 1]);
}

void push(int v, int vl, int vr) {
    if (vr - vl != 1)
        to_add[2 * v] += to_add[v], to_add[2 * v + 1] += to_add[v];
    tr[v] += to_add[v];
    to_add[v] = 0;
}

void upd(int v, int vl, int vr, int l, int r, int x) {
    push(v, vl, vr);
    if (vr <= l || r <= vl)
        return;
    if (l <= vl && vr <= r) {
        to_add[v] += x;
        push(v, vl, vr);
        return;
    }
    int vm = vl + vr >> 1;
    upd(2 * v, vl, vm, l, r, x), upd(2 * v + 1, vm, vr, l, r, x);
    tr[v] = min(tr[2 * v], tr[2 * v + 1]);
}

ll get(int v, int vl, int vr, int l, int r) {
    push(v, vl, vr);
    if (vr <= l || r <= vl)
        return 1e18;
    if (l <= vl && vr <= r)
        return tr[v];
    int vm = vl + vr >> 1;
    return min(get(2 * v, vl, vm, l, r), get(2 * v + 1, vm, vr, l, r));
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    a.resize(n);
    forn (i, 0, n)
        cin >> a[i];
    tr.resize(4 * n, 1e18), to_add.resize(4 * n);
    build(1, 0, n);
    int m;
    cin >> m;
    string s;
    getline(cin, s);
    while (m --> 0) {
        getline(cin, s);
        vector <int> spaces;
        forn (i, 0, sz(s))
            if (s[i] == ' ')
                spaces.pb(i);
        if (sz(spaces) == 1) {
            int l = parse(s, 0, spaces[0]), r = parse(s, spaces[0] + 1, sz(s));
            //cout << l << " " << r << " " << "\n";
            r++;
            if (l < r)
                cout << get(1, 0, n, l, r);
            else 
                cout << min(get(1, 0, n, l, n), get(1, 0, n, 0, r));
            cout << "\n";
        } else {
            int l = parse(s, 0, spaces[0]), r = parse(s, spaces[0] + 1, spaces[1]), x = parse(s, spaces[1] + 1, sz(s));
            r++;
            //cout << l << " " << r << " " << x << "\n";
            if (l < r)
                upd(1, 0, n, l, r, x);
            else 
                upd(1, 0, n, l, n, x), upd(1, 0, n, 0, r, x);
        }
    }
    return 0;
}