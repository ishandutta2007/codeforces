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
    int neutral_tr = INT_MAX;

    int merge_tr(int a, int b) {
        return min(a, b);
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
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    vector <vector <int>> a(3);
    int n = 0;
    forn (i, 0, 3) {
        int t;
        cin >> t;
        n += t;
        a[i].resize(t);
    }
    forn (i, 0, 3) {
        forn (j, 0, sz(a[i]))
            cin >> a[i][j];
        sort(all(a[i]));
    }
    vector <int> needed_first(n + 2);
    vector <int> needed_last(n + 2);
    forn (i, 0, n + 2) {
        needed_first[i] = i - (lower_bound(all(a[0]), i + 1) - a[0].begin())  +
                          (a[0].end() - lower_bound(all(a[0]), i + 1)) - 
                          (lower_bound(all(a[2]), i + 1) - a[2].begin());
        needed_last[i] = (lower_bound(all(a[2]), i) - a[2].begin())  +
                         n - i + 1 - (a[2].end() - lower_bound(all(a[2]), i)) - 
                         (a[0].end() - lower_bound(all(a[0]), i));
        //cout << i << ": " <<  needed_first[i] << " " << needed_last[i] << "\n";
    }
    SegTree tr(needed_last);
    int ans = 1e9;
    forn (i, 0, n + 1) {
        ans = min(ans, needed_first[i] + 
                       tr.get(i + 1, n + 2)
                       );
    }
    cout << ans;
    return 0;
}