#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 3e5 + 10;
const int INF = 2e9 + 1;
const ll MOD = 1e9 + 7;
const ld EPS = 1e-8;
const int MAX = 1e6 + 1;

ll a[N];

int main() {
    //freopen("input.txt", "r", stdin);
    ll n;
    cin >> n;
    fr(i, n)
        cin >> a[i];
    ll ans = n * *min_element(a, a + n);
    fr(i, n)
        a[i] -= ans / n;

    ll l = 0, r = 0;

    fr(i, n)
        if (a[i])
            l++;
        else
            break;
    for (ll i = n - 1; i >= 0; i--)
        if (a[i])
            r++;
        else
            break;

    ll curr = 0, mx = 0;
    fr(i, n)
        if (!a[i]) {
            mx = max(mx, curr);
            curr = 0;
        }
        else {
            curr++;
            mx = max(mx, curr);
        }
    cout << ans + max(mx, l + r);

}