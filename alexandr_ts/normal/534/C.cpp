#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef pair <int, int> pr;
typedef long long ll;
typedef long double ld;

const ll MOD = 1073741824;
const ll INF = 2e9;
const ll N = 3e5 + 2;
const ll M = 211;
const ll MAX = 2e5 + 2;
const ld EPS = 1e-6;

ll d[N];

int main() {
    //ios_base::sync_with_stdio(false);
    //cout << fixed << setprecision(8);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll n, a;
    cin >> n >> a;
    fr(i, n)
        cin >> d[i];
    ll sum = accumulate(d, d + n, 0ll);
    fr(i, n) {
        ll mn = max(1ll, a + d[i] - sum);
        ll mx = min(d[i], a - n + 1);
        cout << d[i] - (mx - mn + 1) << " ";
    }
}