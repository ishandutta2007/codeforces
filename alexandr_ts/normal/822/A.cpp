#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define pb push_back
#define mp make_pair
#define frab(i, a, b) for (int i = a; i < b; i++)

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;
const ll INF = 2e9 + 10;
const ld EPS = 1e-9;
const int M = 1e3 + 2;
const int N = 1e6 + 2;



int main() {
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    ll a, b;
    cin >> a >> b;
    ll c = min(a, b);
    ll ans = 1;
    frab(i, 1, c + 1)
        ans *= i;
    cout << ans;
}