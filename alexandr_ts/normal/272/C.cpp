#include <bits/stdc++.h>
#define frab(i, a, b) for (ll i = a; i < b; i++)
#define fr(i, n) for (ll i = 0; i < n; i++)
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pr;

const ll M = 1e5 + 10;
const ll INF = 2e9 + 10;
const ll N = 1e6 + 10;
const ll MOD = 1e9 + 7;

ll a[N], w[N], h[N], ans[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("a.in", "r", stdin);
    int n;
    cin >> n;
    fr(i, n) {
        cin >> a[i + 1];
    }
    int m;
    cin >> m;
    fr(i, m) {
        cin >> w[i] >> h[i];
        ans[i] = max(i ? ans[i - 1] + h[i - 1] : 0, a[w[i]]);
        cout << ans[i] << endl;
    }

}