#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (ll i = 0; i < n; i++)
#define frab(i, a, b) for (ll i = a; i < b; i++)
#define SSTR(x) dynamic_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pr;

const ll N = 1e6;
const ll M = 311;
const ld EPS = 1e-8;
const ll INF = 2 * 1e15 + 1;
const ll MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    srand(time(NULL));
    //freopen("input.txt", "r", stdin);
    ll a[6];
    cin >> a[0] >> a[1];
    frab(i, 2, 6)
        a[i] = a[i - 1] - a[i - 2];
    ll n;
    cin >> n;
    cout << (a[(n - 1) % 6] % MOD + MOD) % MOD;
}