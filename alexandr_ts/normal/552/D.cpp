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
const ll N = 1e5 + 2;
const ll M = 211;
const ll MAX = 2e5 + 2;
const ld EPS = 1e-6;

ll x1[N], y1[N];
unordered_map <int, int> m[M][2 * M];

ll f(ll n) {
    if (n <= 2)
        return 0;
    return n * (n - 1) * (n - 2) / 6;
}

ll getn(ll n) {
    return 1 + (int)(sqrt(2 * n));
}

int main() {
    //ios_base::sync_with_stdio(false);
    //cout << fixed << setprecision(8);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll n;
    cin >> n;
    fr(i, n) {
        cin >> x1[i] >> y1[i];
        x1[i] += 100, y1[i] += 100;
    }

    fr(i, n)
        frab(j, i + 1, n) {
            ll b = x1[j] - x1[i], a = y1[i] - y1[j], c = x1[i] * (y1[i] - y1[j]) + y1[i] * (x1[j] - x1[i]);
            if (a < 0) a *= -1, b *= -1, c *= -1;
            if (a == 0 && b < 0) b *= -1, c *= -1;
            ll gcd = __gcd(__gcd(abs(a), abs(b)), abs(c));
            a /= gcd, b /= gcd, c /= gcd;
            m[a][b + M][c]++;
        }

    if (n <= 2) {
        cout << 0;
        return 0;
    }
    ll ans = f(n);
    fr(i, M)
        fr(j, 2 * M)
            for (auto it = m[i][j].begin(); it != m[i][j].end(); it++)
                ans -= f(getn(it->second));
    cout << ans;
}