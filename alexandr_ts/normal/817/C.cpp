#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; ++i)
#define mp make_pair
#define pb push_back
#define F first
#define S second
using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 1e9 + 7;
const int M = 1e3 + 5;
const int N = 1e6 + 5;
const int POW = 20;
const ll MOD = 1000 * 1000 * 1000 + 7;

ll sum(ll x) {
    ll ans = 0;
    while (x) {
        ans += (x % 10);
        x /= 10;
    }
    return ans;
}

int main() {
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    ll n, s;
    cin >> n >> s;

    ll cnt = 0;
    for (ll i = s - 200; i <= s + 200; i++)
        if (i >= 1 && i <= n && i - sum(i) >= s)
            cnt++;
    if (s + 201 <= n)
        cnt += n - s - 200;
    cout << cnt;
}