#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (ll i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;
const ll INF = 2e9 + 10;
const ld EPS = 1e-9;
const int N = 1e6 + 2;

ll solve(ll n) {
    if (n <= 4) return n - 1;
    ll t = (2 * n + 1 - sqrt(8 * n + 1)) / 2;
    ll ans = 0;
    frab(i, -2, 3) {
        ll t1 = i + t;
        //cout << t1 << endl;
        ll k = n - t1;
        if (t1 <= k * (k - 1) / 2 && k >= 1)
            ans = max(ans, t1 + t1);
        if (t1 >= k * (k - 1) / 2 && k >= 1)
            ans = max(ans, t1 + k * (k - 1) / 2);
    }
    return ans;
}

int main() {
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << solve(n) << endl;
    }
}