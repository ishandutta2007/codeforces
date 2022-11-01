#include <bits/stdc++.h>
#define fr(i, n) for (ll i = 0; i < n; i++)
#define frab(i, a, b) for (ll i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef pair <long long, long long> pr;
typedef long long ll;
typedef long double ld;

const ll MOD = 1e6 + 3;
const ll INF = 2e9;
const ll N = 1e6 + 2;
const ll MAX = 2e5 + 2;
const ld EPS = 1e-8;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
   // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll a, b;
    cin >> a >> b;
    if (a < b) {
        cout << 0;
        return 0;
    }
    if (a == b) {
        cout << "infinity";
        return 0;
    }
    ll t = a - b;
    ll ans = 0;
    frab(i, 1, sqrt(t) + 1)
        if (t % i == 0)
            if (i < t / i) {
                if (i > b)
                    ans += 2;
                else if (t / i > b)
                    ans++;
            }
            else if (i == t / i && i > b)
                ans++;
    cout << ans;
}