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
const int M = 1e3 + 2;
const int N = 1e6 + 10;

void solve() {
    ll n;
    cin >> n;
    if (n == 9) {
        cout << "1\n";
        return;
    }
    int ans = 0;
    if (n % 2) {
        if (n < 9) {
            cout << "-1\n";
            return;
        }
        n -= 9;
        ans++;
    }
    if (n <= 2) {
        cout << "-1\n";
        return;
    }
    n /= 2;
    if (n % 2) {
        ans++;
        n -= 3;
    }
    ans += n / 2;
    cout << ans << "\n";
}

int main() {
    //freopen("a.in", "r", stdin);
    int n;
    cin >> n;
    while (n--) {
        solve();
    }
}