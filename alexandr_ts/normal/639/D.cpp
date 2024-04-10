#include <bits/stdc++.h>
#define fr(i, n) for (ll i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<vector<ll> > mat;

const int N = 2e5 + 10;
const ll INF = 1e18 + 1;

ll a[N];
ll initAr[N];

void solve() {
    int n, k, b, c;
    cin >> n >> k >> b >> c;
    b = min(b, 5 * c);
    for (int i = 0; i < n; i++)
        cin >> initAr[i];
    sort(initAr, initAr + n);

    ll ans = INF;

    for (int r = 0; r < 5; r++) {
        for (int i = 0; i < n; i++) {
            a[i] = initAr[i];
            while ((a[i] % 5 + 5) % 5 != r)
                a[i]++;
        }

        multiset<ll, std::greater<ll>> ms;
        ll sum = 0;
        for (int i = 0; i < k; i++) {
            ll tmpVal = (a[i] - initAr[i]) * c + (a[k - 1] - a[i]) / 5 * b;
            ms.insert(tmpVal);
            sum += tmpVal;
        }
        ans = min(ans, sum);

        ll msAdd = 0;
        for (int i = k; i < n; i++) {
            ll hdif = (a[i] - a[i - 1]) / 5;
            sum += hdif * b * k;
            msAdd += hdif * b;
            sum += (a[i] - initAr[i]) * c;

            ms.insert((a[i] - initAr[i]) * c - msAdd);

            sum -= (*ms.begin() + msAdd);
            ms.erase(ms.begin());
            ans = min(ans, sum);
        }
    }

    cout << ans << endl;

}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("a.in", "r", stdin);
    int tst = 1;
    while (tst--)
        solve();
}