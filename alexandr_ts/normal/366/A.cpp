#include <bits/stdc++.h>
#define fr(i, n) for (ll i = 0; i < n; i++)
#define frab(i, a, b) for (ll i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef pair <long long, long long> pr;
typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;
const ll INF = 2e9;
const ll N = 1e6 + 2;
const ll MAX = 2e5 + 2;
const ld EPS = 1e-8;

ll f(ll x) {
    return x * (x + 1) / 2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
   // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    fr(i, 4)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (min(a, b) + min(c, d) <= n) {
            cout << i + 1 << " " << min(a, b) << " " << n - min(a, b);
            return 0;
        }
    }
    cout << -1;
}