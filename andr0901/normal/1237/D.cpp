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
    vector <int> tr;
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
    int n;
    cin >> n;
    vector <int> a(n);
    forn (i, 0, n) 
        cin >> a[i];
    forn (i, 0, n) 
        a.pb(a[i]);
    forn (i, 0, n) 
        a.pb(a[i]);
    SegTree tr_min(a);
    vector <int> until(3 * n);
    forn (i, 0, 3 * n) {
        int l = i, r = 3 * n + 1;
        while (r - l > 1) {
            int m = l + r >> 1;
            if (tr_min.get(i, m) * 2 < a[i])
                r = m;
            else
                l = m;
        }
        until[i] = l;
        //cout << until[i] << " ";
    }
    vector <int> greater_right(3 * n + 1, 3 * n);
    vector <int> st;
    forn (i, 0, 3 * n) {
        while (!st.empty() && a[i] > a[st.back()]) {
            greater_right[st.back()] = i;
            st.pop_back();
        }
        st.pb(i);
    }
    vector <int> dp(3 * n + 1, -1);
    for (int i = 3 * n - 1; i >= 0; --i) {
        if (until[i] < greater_right[i])
            dp[i] = until[i];
        else 
            dp[i] = dp[greater_right[i]];
    }
    forn (i, 0, n) {
        if (dp[i] == -1)
            cout << "-1 ";
        else
            cout << dp[i] - i << " ";
    }
   /* cout << "\n";
    forn (i, 0, 3 * n)
        cout << greater_right[i] << " " << until[i] << "\n";*/
    return 0;
}