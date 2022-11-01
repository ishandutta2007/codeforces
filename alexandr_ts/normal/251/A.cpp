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
const ld EPS = 1e-6;

ll a[N], b[N], ans[N];

ll cnt(ll x) {
    x--;
    if (x <= 1) return 0;
    return x * (x - 1) / 2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll n, d;
    cin >> n >> d;
    fr(i, n)
        cin >> a[i];
    ll cur = 0, ans = 0;
    fr(i, n) {
        while (cur < n - 1 && a[cur + 1] - d <= a[i])
            cur++;
        //cout << i << " " << cur << endl;
        ans += cnt(cur - i + 1);
    }
    cout << ans;
}