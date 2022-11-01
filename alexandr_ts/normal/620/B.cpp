#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (ll i = 0; i < n; ++i)
#define frab(i, a, b) for (ll i = a; i < b; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 2e5 + 1;
const int INF = 2e9;
const ld EPS = 1e-16;

int cdig(int x) {
    if (x == 0) return 6;
    if (x == 1) return 2;
    if (x == 2) return 5;
    if (x == 3) return 5;
    if (x == 4) return 4;
    if (x == 5) return 5;
    if (x == 6) return 6;
    if (x == 7) return 3;
    if (x == 8) return 7;
    if (x == 9) return 6;
}

int cnt(int x) {
    int ans = 0;
    while (x > 0) {
        ans += cdig(x % 10);
        x /= 10;
    }
    return ans;
}

int main() {
    ld start = clock() / CLOCKS_PER_SEC;
    srand(time(NULL));
    //freopen("spacepin.in", "r", stdin);
    //freopen("spacepin.out", "w", stdout);
    int a, b;
    cin >> a >> b;
    ll ans = 0;
    frab(i, a, b + 1)
        ans += cnt(i);
    cout << ans;
}