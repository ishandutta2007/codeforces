#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; ++i)
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 2e9 + 7;
const int M = 321;
const int N = 1e6 + 10;
const int POW = 20;

int a[N], l[N], r[N];

int main() {
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    ll x, y, l, r;
    cin >> x >> y >> l >> r;
    ll cur = 1;
    set <ll> s1, s2;

    while (true) {
        s1.insert(cur);
        if (cur > r / x + 1) break;
        cur *= x;
        if (cur > r) break;
    }

    cur = 1;
    while (true) {
        s2.insert(cur);
        if (cur > r / y + 1) break;
        cur *= y;
        if (cur > r) break;
    }

    vector <ll> s;

    for (auto t1: s1)
        for (auto t2: s2)
            if (t1 + t2 >= l && t1 + t2 <= r)
                s.pb(t1 + t2);

    s.pb(l - 1);
    s.pb(r + 1);

    sort(s.begin(), s.end());
    s.resize(unique(s.begin(), s.end()) - s.begin());

    ll ans = 0;
    fr(i, (int)s.size() - 1)
        ans = max(ans, s[i + 1] - s[i]);

    cout << ans - 1;



}