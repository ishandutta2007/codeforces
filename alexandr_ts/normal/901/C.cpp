#include <bits/stdc++.h>
#define fr(i, n) for (ll i = 0; i < n; i++)
#define frab(i, a, b) for (ll i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 2e9 + 10;
const ll MOD = 1e9 + 7;
const ld EPS = 1e-9;
const ll N = 3e5 + 10;

vector <ll> g[N];

ll used[N];
vector <vector <ll> > cycles;
vector <ll> w;
ll pos[N];

void dfs(ll v, ll step, ll par) {
    used[v] = step;
    pos[v] = w.size();
    w.pb(v);
    for (auto u: g[v]) {
        if (used[u] && par != u) {
            ll ps = pos[u];
            vector <ll> tmp;
            for (ll j = ps; j < w.size(); j++)
                tmp.pb(w[j]);
            if (tmp.size())
                cycles.pb(tmp);
        }
        else if (!used[u]) {
            dfs(u, step, v);
        }
    }
    w.pop_back();
}

ll rr[N];

ll sm[N];

void add(ll * a, ll i, ll val, ll n) {
    while (i < n) {
        a[i] += val;
        i = (i | (i + 1));
    }
}

ll sum(ll * a, ll i) {
    ll ans = 0;
    while (i >= 0) {
        ans += a[i];
        i = (i & (i + 1)) - 1;
    }
    return ans;
}

ll f(ll x) {
    return x * (x + 1) / 2;
}

int main() {
    //freopen("a.in", "r", stdin);
    ll n, m;
    cin >> n >> m;
    for (ll i = 0; i < m; i++) {
        int v, u;
        scanf("%d %d", &v, &u);
        g[--v].pb(--u);
        g[u].pb(v);
    }

    ll st = 1;
    for (ll i = 0; i < n; i++)
        if (!used[i])
            dfs(i, st++, -1);

//    for (auto t: cycles) {
//        for (auto v: t) cout << v << " ";cout << endl;
//    }

    vector <pair <ll, ll> > ot;
    set <pair <ll, ll> > ss;
    ll k = cycles.size();
    //cout << k << endl;
    for (ll i = 0; i < k; i++) {
        sort(cycles[i].begin(), cycles[i].end());
        ss.insert({cycles[i].back(), cycles[i][0]});
    }


    fill(rr, rr + n, INF);
    ll curi = 0;
    for (ll i = 0; i < n; i++) {
        while (ss.size() && ss.begin()->second < i)
            ss.erase(ss.begin());
        if (ss.size())
            rr[i] = ss.begin()->first;
        add(sm, i, rr[i], n);
    }

//    for (ll i = 0; i < n; i++)
//        cout << rr[i] << " ";cout << endl;

    ll q;
    cin >> q;
    fr(i, q) {
        int l, r;
        scanf("%d %d", &l, &r);
        l--, r--;
        ll pos = upper_bound(rr, rr + n, r) - rr - 1;
        pos = min(pos, (ll)r);
        pos = max(pos, (ll)l - 1);
        //cout << l << " " << r << " " << pos << endl;
        ll ans = (r - pos) * (ll)(r - pos + 1) / 2;
        ans += sum(sm, pos) - sum(sm, l - 1) - (pos - l + 1) * (ll)(l) - f(pos - l);
        cout << ans << endl;
    }

}