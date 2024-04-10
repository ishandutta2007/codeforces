#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 2e5 + 1;
const int INF = 2e9 + 1;
const ll MOD = 1e9 + 7;
const ld EPS = 1e-8;
const int MAX = 1e6 + 1;

int main() {
    //freopen("input.txt", "r", stdin);
    ll a, b;
    cin >> a >> b;
    int ans = 0;
    for (ll p1 = 1; p1 <= 62; p1++)
        for (ll p2 = 0; p2 < p1 - 1; p2++) {
            ll x = (1ll << p1) - 1ll - (1ll << p2);
            if (x >= a && x <= b && x > 1)
                ans++;
        }
    cout << ans;
}