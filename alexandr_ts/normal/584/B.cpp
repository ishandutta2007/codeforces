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

const ll N = 2e4 + 1;
const ll M = 211;
const ld EPS = 1e-8;
const ll INF = 2 * 1e9 + 1;
const ll MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    srand(time(NULL));
    //freopen("input.txt", "r", stdin);
    ll n;
    cin >> n;
    ll ans = 0;
    frab(i, 1, 4)
        frab(j, 1, 4)
            frab(k, 1, 4)
                if (i + j + k == 6) {
                    //cout << i << " " << j << " " << k << endl;
                    ans++;
                }
    ll cur = 1;
    fr(i, 3 * n)
        cur = cur * 3 % MOD;
    ll cur2 = 1;
    fr(i, n)
        cur2 = cur2 * 7 % MOD;
    cout << ((cur - cur2 + MOD) % MOD + MOD) % MOD;
}