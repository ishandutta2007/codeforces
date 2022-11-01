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

int a[N], b[N], c[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, k, p, x, y;
    cin >> n >> k >> p >> x >> y;
    fr(i, k)
        cin >> a[i];
    ll bigger = 0;
    fr(i, k)
        if (a[i] >= y)
            bigger++;
    ll cntx = max(0ll, (n + 1) / 2 - bigger);
    if (cntx + k > n || accumulate(a, a + k, 0ll) + cntx * y + (n - k - cntx) > x)
        cout << -1;
    else {
        fr(i, cntx) cout << y << " ";
        fr(i, n - k - cntx) cout << "1 ";
    }

}