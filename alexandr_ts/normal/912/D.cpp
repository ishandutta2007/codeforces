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
const ll N = 1e6 + 10;

set <pair <int, int> > used;
set <pair <int, int> > taken;
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int main() {
    //freopen("a.in", "r", stdin);
    ll n, m, r, k;
    cin >> n >> m >> r >> k;

    int x = (n + 1) / 2;
    int y = (m + 1) / 2;
    used.insert(mp(x, y));
    taken.insert(mp(x, y));
    set <pair <ll, pair <int, int> > > best;
    best.insert(mp(0, mp(x, y)));

    while (taken.size() < k) {
        auto t = *best.begin();
        taken.insert(t.second);
        best.erase(best.begin());
        for (int i = 0; i < 4; i++) {
            int x = t.second.first + dx[i];
            int y = t.second.second + dy[i];
            ll tr, tl;
            if (x >= 1 && x <= n && y >= 1 && y <= m)
                if (!used.count(mp(x, y))) {
                    best.insert(mp(-(ll)(min(n, x + r - 1) - max(1ll, x - r + 1) - r + 2) *
                                    (ll)(min(m, y + r - 1) - max(1ll, y - r + 1) - r + 2),
                        mp(x, y)));
                    used.insert(mp(x, y));
                }
        }
    }

    ld ans = 0;
    assert(taken.size() == k);
    for (auto t: taken) {
        int x = t.first;
        int y = t.second;
        //cout << x << " " << y << endl;
        ll cnt = (ll)(min(n, x + r - 1) - max(1ll, x - r + 1) - r + 2) *
                                    (ll)(min(m, y + r - 1) - max(1ll, y - r + 1) - r + 2);
        //if (cnt > (((ll)n - r + 1) * (ll)(m - r + 1)))
        //    cout << x << ' ' << y << " !!" << endl;
        ans += (ld)cnt / (((ll)n - r + 1) * (ll)(m - r + 1));
    }
    cout << fixed << setprecision(12) << ans;
}