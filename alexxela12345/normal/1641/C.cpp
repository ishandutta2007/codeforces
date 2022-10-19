#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
// #define int ll

int n, q;

vector<int> ans;
vector<int> nxt;

set<pair<int, int>> segs;

vector<int> tree0;

void add0(int i0, int x) {
    for (int i = i0; i < (int) tree0.size(); i += i & (-i)) {
        tree0[i] += x;
    }
}

int get0(int i0) {
    if (i0 == 0)
        return 0;
    int ans = 0;
    for (int i = i0; i > 0; i -= i & (-i)) {
        ans += tree0[i];
    }
    return ans;
}

int get0(int l, int r) {
    return get0(r) - get0(l);
}

vector<int> tree1;
void add1(int  i0, int x) {
    for (int i = i0; i < (int) tree1.size(); i += i & (-i)) {
        tree1[i] += x;
    }
}

int get1(int i0) {
    if (i0 == 0)
        return 0;
    int ans = 0;
    for (int i = i0; i > 0; i -= i & (-i)) {
        ans += tree1[i];
    }
    return ans;
}

int get1(int l, int r) {
    return get1(r) - get1(l);
}

int getRight(int i) {
    if (nxt[i] == i) {
        return i;
    }
    return nxt[i] = getRight(nxt[i]);
}

vector<int> nxt0l, nxt0r;

void setAns(int i, int val) {
    nxt[i] = i + 1;
    ans[i] = val;
    if (val == 0) {
        add0(i + 1, 1);
        nxt0l[i] = i - 1;
        nxt0r[i] = i + 1;
    } else {
        add1(i + 1, 1);
        while (true) {
            auto it = segs.lower_bound({i + 1, -1});
            if (it == segs.begin())
                break;
            it--;
            int r = it->second;
            if (i < r) {
                segs.erase(it);
            } else {
                break;
            }
        }
    }
}

int getl(int i) {
    if (i == -1) {
        return i;
    }
    if (nxt0l[i] == i)
        return i;
    return nxt0l[i] = getl(nxt0l[i]);
}

int getr(int i) {
    if (i == n) {
        return i;
    }
    if (nxt0r[i] == i)
        return i;
    return nxt0r[i] = getr(nxt0r[i]);
}

void solve() {
    cin >> n >> q;
    ans.resize(n, -1);
    nxt.resize(n + 1);
    tree1.resize(n + 1);
    tree0.resize(n + 1);
    nxt0l.resize(n);
    nxt0r.resize(n);
    for (int i = 0; i < n + 1; i++) {
        nxt[i] = i;
    }
    for (int i = 0; i < n; i++) {
        nxt0l[i] = i;
        nxt0r[i] = i;
    }
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int i;
            cin >> i;
            i--;
            if (ans[i] == 0) {
                cout << "NO\n";
                continue;
            }
            int l = getl(i - 1) + 1;
            int r = getr(i + 1);
            auto it = segs.lower_bound({l, -1});
            if (it == segs.end()) {
                cout << "N/A\n";
            } else if (it->second <= r) {
                cout << "YES\n";
            } else {
                cout << "N/A\n";
            }
        } else {
            int l, r, x;
            cin >> l >> r >> x;
            l--;
            if (x == 0) {
                int cur = l;
                cur = getRight(cur);
                while (cur < r) {
                    assert(ans[cur] == -1);
                    setAns(cur, 0);
                    cur = getRight(cur);
                }
            } else {
                {
                    auto it = segs.lower_bound({l, -1});
                    if (it != segs.end() && it->second <= r) {
                        continue;
                    }
                }
                while (true) {
                    auto it = segs.lower_bound({l + 1, -1});
                    if (it == segs.begin())
                        break;
                    it--;
                    if (r <= it->second) {
                        segs.erase(it);
                    } else {
                        break;
                    }
                }
                if (get1(l, r) != 0) {
                    continue;
                }
                segs.insert({l, r});
            }
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
}