#include <bits/stdc++.h>
using namespace std;
#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
using ll = long long;
const ll INF = 1e18;
#define int long long

struct segTree {
    int n; vector<ll> t;
    segTree(int n) : n(n), t(2 * n, INF) {}
    void upd(int v, ll x) {
        t[v += n] = x;
        for(v >>= 1; v; v >>= 1) t[v] = min(t[v * 2], t[v * 2 + 1]);
    }
    ll get(int l, int r) {
        ll ret = INF;
        for(l += n, r += n; l <= r; l = (l + 1) >> 1, r = (r - 1) >> 1) {
            if(l & 1) ret = min(ret, t[l]);
            if(!(r & 1)) ret = min(ret, t[r]);
        }
        return ret;
    }
};

int32_t main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen("in.txt", "r", stdin);
    int n, a, b, c, d, len;
    ll start;
    cin >> n >> a >> b >> c >> d >> start >> len;
    vector<int> t(n), q(n);
    vector<int> tt;
    for(int i = 0; i < n; i++) {
        cin >> t[i] >> q[i];
        tt.push_back(max(0LL, t[i] - 1));
        tt.push_back(t[i]);
        tt.push_back(t[i] + 1);
        tt.push_back(max(0LL, t[i] - len - 1));
        tt.push_back(max(0LL, t[i] - len));
        tt.push_back(max(0LL, t[i] - len + 1));
    }
    sort(all(tt));
    tt.erase(unique(all(tt)), tt.end());

    segTree st(n);
    ll tmp = 0;
    for(int i = 0; i < n; i++) {
        if(q[i]) tmp += c;
        else tmp -= d;
        st.upd(i, tmp);
    }

    int pt = -1;
    tmp = 0;
    for(int i = 0; i < sz(tt); i++) {

        while(pt != n - 1 && t[pt + 1] < tt[i]) {
            pt++;
            if(q[pt]) start += a, tmp += c;
            else start -= b, tmp -= d;
        }

        if(start >= 0) {

            if(pt == n - 1 || tt[i] + len < t[pt + 1]) {
                return cout << tt[i], 0;
            }

            int lf = pt + 1, rg = n - 1;
            while(lf < rg) {
                int md = (lf + rg + 1) >> 1;
                if(t[md] < tt[i] + len) lf = md;
                else rg = md - 1;
            }

            ll bad = st.get(pt + 1, lf);
            assert(bad != INF);
            bad += start - tmp;
            if(bad >= 0) return cout << tt[i], 0;
        } else break;
    }
    cout << -1;
}