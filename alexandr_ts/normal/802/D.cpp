#include <bits/stdc++.h>
#define fr(i, n) for (ll i = 0; i < n; ++i)
#define pb push_back
#define mp make_pair
#define frab(i, a, b) for (ll i = a; i < b; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;
const int INF = 2e9 + 10;
const ld EPS = 1e-9;
const int M = 1e2 + 12;
const int N = 4e5 + 10;

void solve() {
    int n = 250;
    vector <int> a(n);
    fr(i, n)
        cin >> a[i];
    sort(a.begin(), a.end());

    int p = (accumulate(a.begin(), a.end(), 0) / n);

    ld m1 = (ld)p / 2.;
    ld m2 = (ld)p * (3. / 2.);
    int c1 = 0, c2 = 0, c3 = 0;
    fr(i, n)
        if (a[i] < m1) c1++;
        else if (a[i] > m2) c3++;
        else c2++;
    if (c2 > 3 * (c1 + c3))
        cout << "poisson\n";
    else
        cout << "uniform\n";
}

int main() {
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    int v;
    cin >> v;
    while (v--) {
        solve();
    }

}