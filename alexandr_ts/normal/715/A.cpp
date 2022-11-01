#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (ll i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long double ld;
typedef long long ll;

const int N = 2e5;
const ll MOD = 1e9 + 7;
const ld EPS = 1e-9;
const ll M = 1e3;
const ll INF = 2e9 + 10;



int main() {
    ios_base::sync_with_stdio(false);
    //freopen("manyangle.in", "r", stdin);
    ll n;
    cin >> n;
    cout << 2 << endl;
    frab(i, 2, n + 1)
        cout << i * (i + 1ll) * (i + 1ll) - (i - 1ll) << endl;
}