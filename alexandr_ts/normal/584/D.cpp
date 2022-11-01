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

const ll N = 1e9 + 1;
const ll M = 211;
const ld EPS = 1e-8;
const ll INF = 2 * 1e9 + 1;
const ll MOD = 1e9 + 7;

bool check(ll n) {
    if (n < 2)
        return false;
    frab(i, 2, sqrt(n) + 1)
        if (!(n % i))
            return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    srand(time(NULL));
    //freopen("input.txt", "r", stdin);
    ll n;
    cin >> n;
    if (check(n)) {
        cout << 1 << endl << n;
        return 0;
    }
    if (check(n - 2)) {
        cout << 2 << endl << 2 << " " << n - 2;
        return 0;
    }
    for (ll i = n; i >= 0; i -= 2)
        if (check(i))
            for (ll j = n - i; j >= 0; j--)
                if (check(j))
                    if (check(n - i - j)) {
                        cout << 3 << endl;
                        cout << i << " " << j << " " << n - j - i;
                        return 0;
                    }
}