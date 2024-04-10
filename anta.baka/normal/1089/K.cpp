#include <bits/stdc++.h>

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
using vll = vector<ll>;

const int inf = 1e9+100;
const ll inf64 = 1e18L+100;
const int nax = 1e6+1;
const int qax = 3e5;

struct segTree {
    struct node {
        ll mx, add;
    };
    node combine(node& a, node& b) {
        return {max(a.mx, b.mx), 0};
    }
    node t[4 * nax];
    void build(int v, int l, int r) {
        if(l == r) {
            t[v] = {0, 0};
        } else {
            int m = (l + r) >> 1;
            build(v * 2 + 1, l, m);
            build(v * 2 + 2, m + 1, r);
            t[v] = combine(t[v * 2 + 1], t[v * 2 + 2]);
        }
    }
    void push(int v) {
        ll x = t[v].add;
        if(x) {
            t[v].add = 0;
            t[v * 2 + 1].mx += x;
            t[v * 2 + 1].add += x;
            t[v * 2 + 2].mx += x;
            t[v * 2 + 2].add += x;
        }
    }
    void upd(int v, int l, int r, int l1, int r1, ll x) {
        if(r < l1 || r1 < l) return;
        if(l1 <= l && r <= r1) {
            t[v].mx += x;
            t[v].add += x;
            return;
        }
        push(v);
        int m = (l + r) >> 1;
        upd(v * 2 + 1, l, m, l1, r1, x);
        upd(v * 2 + 2, m + 1, r, l1, r1, x);
        t[v] = combine(t[v * 2 + 1], t[v * 2 + 2]);
    }
    ll get(int v, int l, int r, int l1, int r1) {
        if(r < l1 || r1 < l) return 0;
        if(l1 <= l && r <= r1) return t[v].mx;
        push(v);
        int m = (l + r) >> 1;
        return max(get(v * 2 + 1, l, m, l1, r1), get(v * 2 + 2, m + 1, r, l1, r1));
    }
};

int q;
int jt[qax], jd[qax];
segTree st, dt;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef HOME
    freopen("in.txt", "r", stdin);
#endif // HOME
    st.build(0, 0, nax - 1);
    dt.build(0, 0, nax - 1);
    cin >> q;
    for(int i = 0; i < q; i++) {
        char ch; cin >> ch;
        if(ch == '+') {
            int t, d; cin >> t >> d; t--;
            jt[i] = t; jd[i] = d;
            st.upd(0, 0, nax - 1, t, t, t);
            st.upd(0, 0, nax - 1, 0, t, d);
            dt.upd(0, 0, nax - 1, 0, t, d);
        } else if(ch == '-') {
            int id; cin >> id; id--;
            int t = jt[id], d = jd[id];
            st.upd(0, 0, nax - 1, t, t, -t);
            st.upd(0, 0, nax - 1, 0, t, -d);
            dt.upd(0, 0, nax - 1, 0, t, -d);
        } else {
            int t; cin >> t; t--;
            cout << max(0LL, st.get(0, 0, nax - 1, 0, t) - max(0LL, dt.get(0, 0, nax - 1, t + 1, nax - 1)) - t) << '\n';
        }
    }
}