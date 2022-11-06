#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <stack>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 100011
#define mod 1000000007
#define lSon (node << 1)
#define rSon (lSon | 1)

const ll limit = 1000000000000000LL;

struct aint {
    ll mult[maxN * 4 + 11], sum[maxN * 4 + 11];

    void init() {
        for (int i = 1; i <= 4 * maxN; i++) mult[i] = sum[i] = 1;
    }

    void upd(int node, int l, int r, int qL, int qR, ll val) {
        if (qL <= l && r <= qR) {
            mult[node] = (mult[node] * val) % mod;
            sum[node] = (sum[node] * val) % mod;
            if (l == r) sum[node] = mult[node];
            return;
        }

        int mid = (l + r) >> 1;
        if (qL <= mid) upd(lSon, l, mid, qL, qR, val);
        if (qR > mid) upd(rSon, mid + 1, r, qL, qR, val);

        sum[node] = (sum[lSon] + sum[rSon]) % mod;
        sum[node] = (sum[node] * mult[node]) % mod;
    }

    ll que(int node, int l, int r, int qL, int qR) {
        if (qL <= l && r <= qR)
            return sum[node];

        int mid = (l + r) >> 1;
        ll ans = 0;

        if (qL <= mid)
            ans += que(lSon, l, mid, qL, qR);
        if (qR > mid)
            ans += que(rSon, mid + 1, r, qL, qR);

        ans %= mod;
        ans = (ans * mult[node]) % mod;
        return ans;
    }
};

ll n, q, i, l, r;
ll a[maxN];
set<ll> S;
vector< pair<int, int> > Q[maxN];
ll ans[maxN];
aint work;
ll poww[maxN], inv_poww[maxN];
stack<ll> st;

ll raise(ll a, ll b) {
    ll ans = 1;

    while (b > 0) {
        if (b & 1) ans = (ans * a) % mod;
        b >>= 1;
        a = (a * a) % mod;
    }

    return ans;
}

void pow2(ll& a, ll b) {
    if (a == 0) return;
    while (a < limit && b-- > 0)
        a = min(limit, a * 2);
}

void spec_add(ll& a, ll b) {
    a = min(a + b, limit);
}

void solve() {
    int i, l, r, _l, _r;
    ll act_sum, aux, act_val;

    work.init();

    for (i = 1; i <= n; i++) {
        l = r = i;

        act_val = a[i];
        a[i] = (2LL * mod + 2LL * (a[i] % mod)) % mod;
        work.upd(1, 1, n, i, i, a[i]);


        while (S.size() > 0) {
            act_sum = work.que(1, 1, n, l, r);
            if (act_val < 0) break;

            auto it = S.end(); it--;
            _l = *it;
            _r = l - 1;
            S.erase(it);

            work.upd(1, 1, n, l, r, poww[_r - _l + 1]);
            l = _l;

            pow2(act_val, _r - _l + 1);
            spec_add(act_val, st.top());
            st.pop();
        }

        S.insert(l);
        st.push(act_val);

        for (auto e : Q[i]) {
            int pos = e.first;
            int id = e.second;
            int last = i + 1;

            auto it = S.upper_bound(pos);
            if (it != S.end())
                ans[id] = work.que(1, 1, n, *it, i), last = *it;

            it--;
            int pre_pos = *it;
            aux = work.que(1, 1, n, pos, last - 1);
            aux *= inv_poww[pos - pre_pos + 1];
            aux %= mod;

            ans[id] = (ans[id] + aux) % mod;
        }
    }

}

int main()
{
    //freopen("test.in","r",stdin);

    cin >> n >> q;
    for (i = 1; i <= n; i++)
        cin >> a[i];

    for (i = 1; i <= q; i++) {
        cin >> l >> r;
        Q[r].pb(mp(l, i));
    }

    poww[0] = 1;
    for (i = 1; i <= n; i++) poww[i] = (poww[i - 1] * 2) % mod;

    inv_poww[n] = raise(poww[n], mod - 2);
    for (i = n - 1; i > 0; i--) inv_poww[i] = (inv_poww[i + 1] * 2) % mod;
    inv_poww[0] = 1;

    solve();

    for (i = 1; i <= q; i++)
        cout << ans[i] << '\n';

    return 0;
}