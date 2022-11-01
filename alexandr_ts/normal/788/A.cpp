#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 3e5 + 3;
const ll MOD = 1e9 + 7;
const ll INF = 2e9 + 10;

ll a[N], b[N], p[N];

int main() {
    ios_base::sync_with_stdio(false);
    //freopen("a.in", "r", stdin);
    int n;
    cin >> n;
    fr(i, n) {
        cin >> a[i];
    }
    fr(i, n - 1)
        b[i] = abs(a[i + 1] - a[i]);

    for (int i = n - 2; i >= 0; i--) {
        p[i] = p[i + 1];
        if (i % 2 == (n - 2) % 2)
            p[i] += b[i];
        else
            p[i] -= b[i];
    }

    //for (int i = 0; i < 10; i++)
    //    cout << p[i] << " ";cout << endl;

    ll mx = 0;
    ll mn = 0;
    ll ans = -INF;
    for (int i = n - 2; i >= 0; i--) {
        if (i % 2 == (n - 2) % 2)
            ans = max(ans, p[i] - mn);
        else
            ans = max(ans, -p[i] + mx);
        mx = max(mx, p[i]);
        mn = min(mn, p[i]);
    }
    cout << ans;
}