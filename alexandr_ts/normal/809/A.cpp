#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define pb push_back
#define mp make_pair
#define frab(i, a, b) for (int i = a; i < b; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 1000000007;
const ll P1 = 17;
const ll P2 = 19;
const ld PI = acos(-1);
const ll MAX = 63211236 + 10;
const ll INF = 1e9 + 10;
const ld EPS = 1e-9;
const int M = 4e5;
const int N = 1e6 + 10;

ll a[N];
int l[N];

int main() {
    //freopen("a.in", "r", stdin);
    int n;
    cin >> n;
    fr(i, n)
        cin >> a[i + 1];
    if (n == 1) {
        cout << 0;
        return 0;
    }
    sort(a + 1, a + n + 1);

    ll ans = (a[n] - a[n - 1]) % MOD;
    ll cur = (a[n] - a[n - 1]) % MOD;
    ll tw = 1;
    ll sumtw = 1;
    //ans += cur;
    for (int i = n - 2; i >= 1; i--) {
        cur = (cur + sumtw * (a[i + 1] - a[i])) % MOD;
        cur = (cur * 2) % MOD;
        tw = (tw * 2) % MOD;
        sumtw = (sumtw + tw) % MOD;
        cur = (cur + a[i + 1] - a[i]) % MOD;
        ans = (ans + cur) % MOD;
    }
    cout << ans;
}