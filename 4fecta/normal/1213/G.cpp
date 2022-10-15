#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pii pair<int, int>
#define f first
#define s second
#define readl(_s) getline(cin, (_s));
#define boost() cin.tie(0); cin.sync_with_stdio(0)

const int MN = 200005;

int n, q, u, v, w;

pair<int, ll> par[MN];
vector<pair<int, pii>> a;

ll num[MN];

int find(int x) {
    if (x == par[x].f) return x;
    return par[x].f = find(par[x].f);
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (par[x].s < par[y].s) {
        par[x].f = par[y].f;
        par[y].s += par[x].s;
    } else {
        par[y].f = par[x].f;
        par[x].s += par[y].s;
    }
}

int main() {
    boost();

    cin >> n >> q;
    for (int i = 1; i < n; i++) {
        cin >> u >> v >> w;
        a.push_back({w, {u, v}});
    }
    sort(a.begin(), a.end());

    for (int i = 1; i <= n; i++) {
        par[i] = {i, 1};
    }

    ll sum = 0;
    int idx = 0;
    for (int i = 1; i <= 200000, idx < a.size(); i++) {
        while (a[idx].f <= i) {
            if (idx == a.size()) break;
            auto cur = a[idx];
            idx++;
            u = find(cur.s.f);
            v = find(cur.s.s);
            sum += par[u].s * par[v].s;
            //num[i] = sum;
            merge(u, v);
        }
        num[i] = sum;
    }

    for (int i = 200000; i > 0; i--) {
        if (num[i] == 0) {
            num[i] = sum;
        } else {
            break;
        }
    }

    for (; q > 0; q--) {
        cin >> u;
        printf("%lld ", num[u]);
    }

    return 0;
}