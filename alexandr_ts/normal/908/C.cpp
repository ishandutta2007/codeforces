#include <bits/stdc++.h>
#define fr(i, n) for (ll i = 0; i < n; i++)
#define frab(i, a, b) for (ll i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 2e9 + 10;
const ll MOD = 1e9 + 7;
const ld EPS = 1e-9;
const ll N = 1e5 + 10;

int x[N];
ld y[N];

int main() {
    //freopen("a.in", "r", stdin);
    int n;
    ll r;
    cin >> n >> r;
    for (int i = 0; i < n; i++)
        cin >> x[i];

    y[0] = r;
    for (int i = 1; i < n; i++) {
        ld ya = r;
        for (int j = 0; j < i; j++)
            if (abs(x[i] - x[j]) <= 2 * r)
                ya = max(ya, y[j] + sqrt(4 * r * r - (x[i] - x[j]) * (x[i] - x[j])));
        y[i] = ya;
    }
    for (int i = 0; i < n; i++)
        cout << fixed << setprecision(12) << y[i] << " ";
}