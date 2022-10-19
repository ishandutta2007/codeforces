#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define int long long
const int INF = 1e15;

pair <int, int> merge(pair <int, int> a, pair <int, int> b) {
    return make_pair(min(a.first, b.first), max(a.second, b.second));
}

struct SegTree {
    int n;
    vector <pair <int, int>> t;

    SegTree(int n) : n(n) {
        t.resize(4 * n, make_pair(INF, -INF));
    }

    void update(int v, int l, int r, int i, int x) {
        if (l > i || i > r) return;
        if (l == r) {
            t[v] = make_pair(x, x);
            return;
        }
        int m = (l + r) / 2;
        update(2 * v, l, m, i, x);
        update(2 * v + 1, m + 1, r, i, x);
        t[v] = merge(t[2 * v], t[2 * v + 1]);
    }

    pair <int, int> get_seg(int v, int l, int r, int A, int B) {
        if (l > B || A > r) return make_pair(INF, -INF);
        if (A <= l && r <= B) return t[v];
        int m = (l + r) / 2;
        return merge(get_seg(2 * v, l, m, A, B), get_seg(2 * v + 1, m + 1, r, A, B));
    }
};

signed main(){
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
    }
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        vector <int> bll(n, -1), blr(n, n), st;
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && a[st.back()] < a[i]) {
                blr[st.back()] = i;
                st.pop_back();
            }
            st.push_back(i);
        }
        st.clear();
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && a[st.back()] < a[i]) {
                bll[st.back()] = i;
                st.pop_back();
            }
            st.push_back(i);
        }
        SegTree tr(n + 1);
        int now = 0;
        tr.update(1, 0, n, 0, 0);
        for (int i = 0; i < n; ++i) {
            now += a[i];
            tr.update(1, 0, n, i + 1, now);
        }
        bool ok = true;
        for (int i = 0; i < n; ++i) {
            int right_sum = tr.get_seg(1, 0, n, i + 1, blr[i]).second;
            int left_sum = tr.get_seg(1, 0, n, bll[i] + 1, i).first;
            if (a[i] < right_sum - left_sum) {
                ok = false;
                break;
            }
        }
        if (ok) cout << "YES\n";
        else cout << "NO\n";
    }
}