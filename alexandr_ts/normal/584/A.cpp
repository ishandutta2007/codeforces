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
    int n, t;
    cin >> n >> t;
    if (n == 1 && t == 10) {
        cout << -1;
        return 0;
    }
    if (t == 10) {
        cout << 10;
        fr(i, n - 2)
            cout << 0;
        return 0;
    }
    cout << t;
    fr(i, n - 1)
        cout << 0;
}