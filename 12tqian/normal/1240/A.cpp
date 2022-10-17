#include <bits/stdc++.h>

using namespace std;

#define f1r(i, a, b) for (int i = a; i < b; i++)
#define f0r(i, a) f1r(i, 0, a)
#define each(t, a) for (auto& t : a)

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define f first
#define s second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
typedef vector<ll> vl;

void solve_case() {
    int n; cin >> n;
    vl p(n);
    f0r(i, n) cin >> p[i], p[i] /= 100;
    ll x, a, y, b; 
    cin >> x >> a >> y >> b;
    ll k; cin >> k;
    if (x < y) swap(x, y), swap(a, b);

    sort(all(p));
    reverse(all(p));

    vl pre(n);
    f0r(i, n) {
        pre[i] = (i?pre[i-1]:0) + p[i];
    }

    auto sum = [&](int l, int r) -> ll { 
        if (l > r) return 0;
        return pre[r]-(l?pre[l-1]:0);
    };

    auto check = [&](ll d) -> bool {
        ll A = d / a;
        ll B = d / b;
        ll C = d / (a / __gcd(a, b) * b);
        A -= C;
        B -= C;
        ll res = 0;
        res += sum(0, C-1) * (x + y);
        res += sum(C, C+A-1) * x;
        res += sum(C+A, C+A+B-1) * y;
        if (res >= k) return true;
        return false;
    };

    int lo = 1;
    int hi = n;
    while (hi - lo > 1) {
        int mid = (lo + hi) / 2;
        if (check(mid)) hi = mid;
        else lo = mid + 1;
    }

    if (check(lo)) cout << lo << '\n';
    else if (check(hi)) cout << hi << '\n';
    else cout << -1 << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int tt; cin >> tt;
    while (tt--) solve_case();
    return 0;
}