#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e6 + 5;
const int M = 500 * 1000 * 1000;
const ll MOD = 1000 * 1000 * 1000 + 7;
const ll INF = 2e14 + 10;
const ld EPS = 1e-10;

int main() {
    //freopen("a.in", "r", stdin);
    ll n, k;
    cin >> n >> k;
    int cnt = 0;
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0)
            if (i * i == n) {
                cnt++;
                if (cnt + 1 == 2 * k) {
                    cout << i;
                    return 0;
                }
            }
            else
                cnt += 2;
    }

    if (k > cnt)
        cout << -1;
    else {
        int c1 = 0;
        for (ll i = 1; i * i <= n; i++) {
            if (n % i == 0)
                c1++;
            if (k == c1) {
                cout << i;
                return 0;
            }
            else if (k == cnt - c1 + 1) {
                cout << n / i;
                return 0;
            }
        }
    }

}