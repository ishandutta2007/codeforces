#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

ll f() {
    ll a, b, p, q;
    cin >> a >> b >> p >> q;

    ll sz = 1;
    while (sz * sz < b - a + 1) ++sz;

    const auto md = [&q](const ll x) {
        return (x % (2 * q) + 2 * q) % (2 * q);
    };
    const auto mdAbs = [&md](const ll x) {
        return min(md(x), md(-x));
    };

    vector<pair<ll, ll>> v;
    for (int i = 0; i < sz; ++i)
        v.emplace_back(md(2 * p * i), i);

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end(), [](const pair<ll, ll> &p1, const pair<ll, ll> &p2) {
        return p1.first == p2.first;
    }), v.end());

    pair<ll, ll> res = {1LL << 60, -1};
    auto eval = [&](const ll i) {
        assert(a <= i && i <= b);
        return pair<ll, ll>(mdAbs(q - 2 * p * i), i);
    };
    for (int i = 0; a + i * sz + sz - 1 <= b; ++i) {
        const ll diff = md(q - 2 * p * (a + i * sz));
        auto it = lower_bound(v.begin(), v.end(), pair<ll, ll>{diff, -1});
        if (it == v.end()) it = v.begin();
        assert(eval(a + i * sz + it->second).first == mdAbs(it->first - diff));
        res = min(res, {mdAbs(it->first - diff), a + i * sz + it->second});
        (it == v.begin() ? it = v.end() : it)--;
        assert(eval(a + i * sz + it->second).first == mdAbs(it->first - diff));
        res = min(res, {mdAbs(it->first - diff), a + i * sz + it->second});
    }
    for (int i = max(a, b - sz); i <= b; ++i)
        res = min(res, eval(i));

    return res.second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
        cout << f() << endl;
    return 0;
}