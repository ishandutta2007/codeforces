#include <bits/stdc++.h>
#define fr(i, n) for (ll i = 0; i < n; i++)
#define frab(i, a, b) for (ll i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef pair <long long, long long> pr;
typedef long long ll;
typedef long double ld;

const ll MOD = 1e6 + 3;
const ll INF = 2e9;
const ll N = 1e6 + 2;
const ll MAX = 2e5 + 2;
const ld EPS = 1e-6;

ll a[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll x, y, m;
    ll ans = 0;
    cin >> x >> y >> m;
    if (x >= m || y >= m) {
        cout << 0;
        return 0;
    }
    if (x < 0 && y > 0 && m > y) {
        ans += abs(x / y);
        x += abs(x / y) * y;
        if (x < 0) x += y, ans++;
    }
    if (y < 0 && x > 0 && m > x) {
        ans += abs(y / x);
        y += abs(y / x) * x;
        if (y < 0) y += x, ans++;
    }
    if (x < 0 && y < 0 && m > max(x, y)) {
        cout << -1;
        return 0;
    }
    fr(i, 100000)
    {
        if (x >= m || y >= m) {
            cout << i + ans;
            return 0;
        }
        if (x < y) x = x + y;
        else y = x + y;
    }
    cout << -1;
}