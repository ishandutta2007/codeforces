#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 5e5 + 10;
const int INF = 2e9 + 1;
const ll MOD = 1e9 + 7;
const ld EPS = 1e-8;
const int MAX = 1e6 + 1;

ll a[N];

int main() {
    //freopen("input.txt", "r", stdin);
    ll n, m;
    cin >> n >> m;
    fr(i, n) {
        ll t;
        cin >> t;
        a[t]++;
    }
    ll ans = 0;
    fr(i, m + 1)
        ans += (a[i] * accumulate(a, a + m + 1, 0ll) - a[i] * a[i]);
    cout << ans / 2;
}