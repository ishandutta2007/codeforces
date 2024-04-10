#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 2e9 + 10;
const ll MOD = 1e9 + 7;
const ld EPS = 1e-9;

const int N = 3e5 + 10;
const int M = 1e3 + 10;


ll a[N];

int main() {
    //freopen("a.in", "r", stdin);
    //ios_base::sync_with_stdio(false);
    ll n, k;
    cin >> n >> k;
    fr(i, n)
        cin >> a[i];
    int mn = *min_element(a, a + n);
    fr(i, n)
        if ((a[i] - mn) % k) {
            cout << -1;
            return 0;
        }
    ll ans = 0;
    fr(i, n)
        ans += (a[i] - mn) / k;
    cout << ans;
}