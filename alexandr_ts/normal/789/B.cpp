#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e6 + 3;
const ll MOD = 10000*10000;
const ll INF = 2e9 + 10;

ll a[N];

int main() {
    ios_base::sync_with_stdio(false);
    //freopen("a.in", "r", stdin);
    ll b1, q, l, m;
    cin >> b1 >> q >> l >> m;
    set <ll> s;
    fr(i, m) {
        ll x;
        cin >> x;
        s.insert(x);
    }

    map <ll, ll> m1;
    if (abs(b1) > l) {
        cout << 0;
        return 0;
    }

    for (int i = 0; i < 1000; i++) {
        m1[b1]++;
        b1 *= q;
        if (abs(b1) > l) break;
    }

    for (auto t: m1)
        if (!s.count(t.first) && t.second > 1) {
            cout << "inf";
            return 0;
        }
    int ans = 0;
    for (auto t: m1)
        if (!s.count(t.first))
            ans++;
    cout << ans;
}