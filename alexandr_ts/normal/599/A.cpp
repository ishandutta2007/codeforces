#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, n) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef pair <int, int> pr;
typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;
const ll INF = 2e9;
const ll N = 1e6 + 1;
const ld EPS = 1e-8;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    ll a, b, c;
    cin >> a >> b >> c;
    ll ans = min(2 * a + 2 * b, a + b + c);
    ans = min(ans, 2 * a + 2 * c);
    ans = min(ans, 2 * b + 2 * c);
    cout << ans;
}