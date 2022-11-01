#include <bits/stdc++.h>
#define fr(i, n) for (ll i = 0; i < n; i++)
#define frab(i, a, b) for (ll i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e6;
const ll INF = 2e9;
const ld EPS = 1e-8;
const int MAX = 1e6 + 1;

ll a[N];

ll solve(ll a, ll b, ll c) {
    ll mn = min(min(a, b), c);
    ll ans = mn + (a - mn) / 3 + (b - mn) / 3 + (c - mn) / 3;
    ans = max(ans, a / 3 + b / 3 + c / 3 + min(min(a % 3, b % 3), c % 3));
    return ans;
}

int main() {
   // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll a, b, c;
    cin >> a >> b >> c;
    ll ans = solve(a, b, c);
    if (a > 0 && b > 0 && c > 0)
        ans = max(ans, 1 + solve(a - 1, b - 1, c - 1));
    if (a > 1 && b > 1 && c > 1)
        ans = max(ans, 2 + solve(a - 2, b - 2, c - 2));
    cout << ans;


}