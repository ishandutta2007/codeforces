#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

#define forn(i, s, f) for (int i = (int)s; i < (int)f; i++)
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair <int, int>
#define fs first
#define sc second
#define pf push_front
#define pb push_back
#define pop_f pop_front
#define pop_b pop_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()


class SegTree{
private: 
    int n;
    vector <int> tr, to_add;
    int neutral_tr = INT_MIN;

    int merge_tr(int a, int b) {
        return max(a, b);
    }

    void build(int v, int vl, int vr, const vector <int>& a) {
        if (vr - vl < 1)
            return;
        if (vr - vl == 1) {
            tr[v] = a[vl];
            return;
        }
        int vm = vl + vr >> 1;
        build(2 * v, vl, vm, a), build(2 * v + 1, vm, vr, a);
        tr[v] = merge_tr(tr[2 * v], tr[2 * v + 1]);
    }

    int get(int v, int vl, int vr, int l, int r) {
        if (vr <= l || r <= vl)
            return neutral_tr;
        if (l <= vl && vr <= r)
            return tr[v];
        int vm = vl + vr >> 1;
        return merge_tr(get(2 * v, vl, vm, l, r), get(2 * v + 1, vm, vr, l, r));
    }
public: 
    SegTree(const vector <int>& a) {
        n = sz(a);
        tr.resize(4 * n, neutral_tr);
        build(1, 0, n, a);
    }

    int get(int l, int r) {
        return get(1, 0, n, l, r);
    }
};

void solve() {
    int n;
    cin >> n;
    vector <int> a(n);
    forn (i, 0, n)
        cin >> a[i];
    int m;
    cin >> m;
    vector <pii> b(m);
    forn (i, 0, m)
        cin >> b[i].fs >> b[i].sc;
    sort(all(b));
    vector <int> powers(m);
    forn (i, 0, m)
        powers[i] = b[i].fs;
    vector <int> tmp(m);
    forn (i, 0, m)
        tmp[i] = b[i].sc;
    int ans = 0;
    SegTree tr(tmp);
    forn (i, 0, n) {
        int j = i;
        int mx = a[i];
        while (j < n && 
               tr.get(lower_bound(all(powers), mx) - powers.begin(), m) >= j - i + 1) {
            mx = max(mx, a[j + 1]);
            j++;
        }
        //cout << i << " " << j << "\n";
        if (i == j) {
            cout << "-1\n";
            return;
        }
        i = j - 1;
        ans++;
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t --> 0)
        solve();
    return 0;
}