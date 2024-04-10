#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define pii pair<ll, ll>
#define f first
#define s second
#define readl(_s) getline(cin, (_s));
#define boost() cin.tie(0); cin.sync_with_stdio(0)

const int MN = 100005, MOD = 1e9 + 7;

int m; ll st[MN * 10], n, x, y;
pii a[MN];
map<ll, int> mp;
vector<ll> pts;

void upd(int l, int r, int x, ll val, int idx) {
    if (l == r) {
        st[idx] += val;
        st[idx] %= MOD;
        return;
    }
    int mid = (l + r) >> 1;
    if (x > mid) upd(mid + 1, r, x, val, idx * 2 + 1);
    else upd(l, mid, x, val, idx * 2);
    st[idx] = st[idx * 2] + st[idx * 2 + 1];
    st[idx] %= MOD;
}

ll qry(int l, int r, int x, int y, int idx) {
    if (r < x || l > y) return 0;
    if (r <= y && l >= x) return st[idx];
    int mid = (l + r) >> 1;
    return qry(l, mid, x, y, idx * 2) % MOD + qry(mid + 1, r, x, y, idx * 2 + 1) % MOD;
}

bool cmp(pii x, pii y) {
    return x.s < y.s;
}

int main() {
    boost();

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        x++, y++;
        a[i] = {x, y};
        pts.push_back(x);
        pts.push_back(y);
    }
    pts.push_back(1);
    pts.push_back(n + 1);
    sort(pts.begin(), pts.end());
    pts.erase(unique(pts.begin(), pts.end()), pts.end());
    for (int i = 0; i < pts.size(); i++) {
        mp[pts[i]] = i;
    }
    sort(a, a + m, cmp);
    upd(0, pts.size(), 0, 1, 1);
    for (int i = 0; i < m; i++) {
        pii p = a[i];
        p.f = mp[p.f];
        p.s = mp[p.s];
        ll ways = qry(0, pts.size(), p.f, p.s - 1, 1) % MOD;
        upd(0, pts.size(), p.s, ways, 1);
    }
    printf("%lld\n", qry(0, pts.size(), pts.size() - 1, pts.size() - 1, 1) % MOD);

    return 0;
}