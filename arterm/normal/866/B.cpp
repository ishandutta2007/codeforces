// vim:ts=4:sts=4:sw=4:et
// MOSCOW IPT JINOTEGA
// Table #14
#include <bits/stdc++.h>
using namespace std;
#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;
typedef long long i64;

const int M = 100100;

typedef pair<ll, ll> pll;

ll n, s;
vector<pll> x, y;
ll ans = 0;
ll tot = 0;

void read() {
    cin >> n >> s;
    for (int i = 0; i < n; ++i) {
        ll cnt, a, b;
        cin >> cnt >> a >> b;

        tot += cnt;

        ll mn = min(a, b);

        ans += 1ll * cnt * mn;

        a -= mn;
        b -= mn;

        if (a)
            x.emplace_back(a, cnt);
        else
            y.emplace_back(b, cnt);
    }
}

pll rems(const vector<pll> &x) {
    ll cur = 0, sum = 0;
    for (auto p : x) {
        if (cur + p.second >= s) {
            ll need = s - cur;
            sum += need * p.first;

            p.second -= need;

            ans += sum;
            
            sum = 0, cur = 0;

            ans += (p.second / s) * s * p.first;

            p.second %= s;
        }
        cur += p.second;
        sum += p.first * p.second;
    }

    return {sum, cur};
}

void kill() {
    sort(all(x), greater<pll>());
    sort(all(y), greater<pll>());

    pll rA = rems(x);
    pll rB = rems(y);

    if (rA.second + rB.second <= s) {
        ans += max(rA.first, rB.first);
    } else {
        ans += rA.first + rB.first;
    }

    cout << ans << "\n";
}

int main() {
#ifdef LOCAL
    assert(freopen("b.in", "r", stdin));
#endif
    ios_base::sync_with_stdio(false);
    read();
    kill();

    return 0;
}