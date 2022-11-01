#include <bits/stdc++.h>
#define frab(i, a, b) for (ll i = a; i < b; i++)
#define fr(i, n) for (ll i = 0; i < n; i++)
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pr;

const ll M = 2e6 + 10;
const ll INF = 2e9 + 10;
const ll N = 2e6 + 10;
const ll MOD = 1e9 + 7;

ll d[N];

int main() {
    //freopen("a.in", "r", stdin);
    ll n, a, b, t;
    string s;
    cin >> n >> a >> b >> t;
    cin >> s;
    s = s + s;

    frab(i, n, 2 * n) {
        if (i == n) {
            d[i] = 1;
            if (s[i] == 'w')
                d[i] += b;
            continue;
        }
        d[i] = d[i - 1] + 1 + a;
        if (s[i] == 'w')
            d[i] += b;
    }
    for (ll i = n - 1; i >= 0; i--) {
        d[i] = d[i + 1] + 1 + a;
        if (s[i] == 'w')
            d[i] += b;
    }



    fr(i, n)
        d[i] = -d[i];
    fr(i, n)
        d[i] += d[n];
    //fr(i, 2 * n)
    //    cout << d[i] << " ";cout << endl;


    ll ans = 0;
    ll l = 0;
    frab(i, n, 2 * n) {
        while (d[i] - d[l] + min((n - l), i - n) * a > t && l + 1 < n)
            l++;
        //cout << l << " " << i << endl;
        if (d[i] - d[l] + min((n - l), i - n) * a <= t)
            ans = max(ans, min(n, i - l + 1));
    }
    frab(i, n, 2 * n)
        if (d[i] <= t)
            ans = max(ans, min(n, i - n + 1));
    frab(i, 0, n)
        if (d[n] - d[i] <= t)
            ans = max(ans, min(n, n - i + 1));
    cout << ans;

}