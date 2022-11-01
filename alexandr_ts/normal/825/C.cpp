#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define pb push_back
#define mp make_pair
#define frab(i, a, b) for (int i = a; i < b; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;
const ld PI = acos(-1);
const ll MAX = 2e7 + 10;
const ll INF = 1e9;
const ld EPS = 1e-9;
const int M = 1e2 + 12;
const int N = 1e6 + 10;

ll a[N];

int main() {
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    ll n, k;
    cin >> n >> k;
    fr(i, n)
        cin >> a[i];
    sort(a, a + n);

    ll cnt = 0;
    fr(i, n) {
        while (a[i] > 2 * k) {
            cnt++, k *= 2;
        }
        k = max(k, a[i]);
    }
    cout << cnt;


}