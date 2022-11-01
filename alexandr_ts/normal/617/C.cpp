#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pr;

const int N = 1e5;
const ll MOD = 1e9 + 7;
const ld EPS = 1e-9;
const int MAX = 1e6;

ll x[N];
ll y[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
//    freopen("a.in", "r", stdin);
    ll n;
    cin >> n;
    ll x1,y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    fr(i, n)
        cin >> x[i] >> y[i];
    ll ans = 1e16;
    fr(i, n) {
        ll r1 = (x[i] - x1) * (x[i] - x1) + (y[i] - y1) * (y[i] - y1);
        ll r2 = 0;
        fr(j, n)
            if ((x[j] - x1) * (x[j] - x1) + (y[j] - y1) * (y[j] - y1) > r1)
                r2 = max(r2, (x[j] - x2) * (x[j] - x2) + (y[j] - y2) * (y[j] - y2));
        ans = min(ans, r1 + r2);

    }
    ll r2 = 0;
    fr(j, n)
        r2 = max(r2, (x[j] - x2) * (x[j] - x2) + (y[j] - y2) * (y[j] - y2));
    cout << min(r2, ans);
}