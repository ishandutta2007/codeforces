#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 42;

int mn[4 * maxn];

void upd(int p, int c, int v = 1, int l = 0, int r = maxn) {
    if(r - l == 1) {
        mn[v] = c;
    } else {
        int m = (l + r) / 2;
        if(p < m) {
            upd(p, c, 2 * v, l, m);
        } else {
            upd(p, c, 2 * v + 1, m, r);
        }
        mn[v] = max(mn[2 * v], mn[2 * v + 1]);
    }
}

int get(int a, int b, int v = 1, int l = 0, int r = maxn) {
    if(a <= l && r <= b) {
        return mn[v];
    } else if(r <= a || b <= l) {
        return 0;
    } else {
        int m = (l + r) / 2;
        return max(get(a, b, 2 * v, l, m), get(a, b, 2 * v + 1, m, r));
    }
}

void solve() {
    int n, q;
    cin >> n >> q;
    int t[q], l[q], r[q], x[q];
    int ask[q];
    for(int i = 0; i < q; i++) {
        cin >> t[i];
        if(t[i] == 0) {
            cin >> l[i] >> r[i] >> x[i];
            l[i]--;
        } else {
            cin >> ask[i];
            ask[i]--;
        }
    }
    vector<int> ans(n, -1), tim(n, q);
    set<int> unk;
    for(int i = 0; i < n; i++) {
        unk.insert(i);
    }
    for(int i = 0; i < q; i++) {
        if(t[i] == 0) {
            if(x[i] == 0) {
                auto it = unk.lower_bound(l[i]);
                while(it != end(unk) && *it < r[i]) {
                    //cout << "! " << *it << ' ' << 0 << endl;
                    ans[*it] = 0;
                    tim[*it] = i;
                    upd(*it, i);
                    it = unk.erase(it);
                }
            }
        }
    }
    for(int i = 0; i < q; i++) {
        if(t[i] == 0) {
            if(x[i] == 1) {
                auto it = unk.lower_bound(l[i]);
                if(next(it) == end(unk) || *next(it) >= r[i]) {
                    //cout << "! " << *it << ' ' << 1 << endl;
                    ans[*it] = 1;
                    tim[*it] = min(tim[*it], max(i, get(l[i], r[i])));
                }
            }
        }
    }
    for(int i = 0; i < q; i++) {
        if(t[i] == 1) {
            if(ans[ask[i]] == -1 || tim[ask[i]] > i) {
                cout << "N/A" << "\n";
            } else {
                cout << (ans[ask[i]] ? "YES" : "NO") << "\n";
            }
        }
    }
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    t = 1;
    //cin >> t;
    while(t--) {
        solve();
    }
}