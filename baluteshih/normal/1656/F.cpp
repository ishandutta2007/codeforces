#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define X first
#define Y second
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(), v.end()
#define pb push_back

const ll C = 2e6;
ll w[200005];
int boss[200005], n;
ll mi[200005], mx[200005];

int finds(int x) {
    if (x == boss[x]) return x;
    return boss[x] = finds(boss[x]);
}

int Union(int x, int y) {
    x = finds(x), y = finds(y);
    if (x == y) return 0;
    mi[y] = min(mi[y], mi[x]);
    mx[y] = max(mx[y], mx[x]);
    boss[x] = y;
    return 1;
}

pll check(ll t) {
    pll rt = pll(0, 0);
    vector<int> idx(n);
    iota(boss + 1, boss + n + 1, 1);
    iota(ALL(idx), 1);
    for (int i = 1; i <= n; ++i)
        mi[i] = mx[i] = w[i];
    while (SZ(idx) > 1) {
        vector<int> nxt;
        ll bmi = -1, smi = -1;
        ll bmx = -1, smx = -1;
        for (int i : idx) {
            if (boss[i] == i) {
                if (bmi == -1 || w[i] < w[bmi])
                    smi = bmi, bmi = i;
                else if (smi == -1 || w[i] < w[smi])
                    smi = i;
                if (bmx == -1 || w[i] > w[bmx])
                    smx = bmx, bmx = i;
                else if (smx == -1 || w[i] > w[smx])
                    smx = i;
            }
        }
        for (int i : idx) {
            int u;
            if (w[i] + t >= 0)
                u = bmi == i ? smi : bmi;
            else
                u = bmx == i ? smx : bmx;
            if (Union(i, u)) {
                rt.X += w[u] + w[i];
                rt.Y += w[u] * w[i] + t * (w[u] + w[i]);
            }
        }
        for (int i : idx)
            if (finds(i) == i)
                nxt.pb(i);
        idx.swap(nxt);
    }
    return rt;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; ++i)
            cin >> w[i];
        if (check(C).Y < check(C + 1).Y || check(-C).Y < check(-C - 1).Y) {
            cout << "INF\n";
            continue;
        }
        ll l = -C, r = C;
        while (r - l > 1) {
            ll mid = (l + r) / 2;
            if (check(mid).X <= 0)
                r = mid;
            else
                l = mid;
        }
        ll ans = max(check(l).Y, check(r).Y);
        cout << ans << "\n";
    }
}