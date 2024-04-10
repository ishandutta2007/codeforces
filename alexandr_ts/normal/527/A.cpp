#include <bits/stdc++.h>
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define frb(i, n) for (int i = n - 1; i >= 0; i--)

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e5;
const ld EPS = 1e-9;

ll ans = 0;

void gcd(ll a, ll b) {
    if (!b) return;
    ans += a / b;
    gcd(b, a % b);
}

int main() {
    //freopen("a.in", "r", stdin);
    ll a, b;
    cin >> a >> b;
    gcd(a, b);
    cout << ans;
}