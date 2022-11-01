#include <bits/stdc++.h>
#define frab(i, a, b) for (ll i = a; i < b; i++)
#define fr(i, n) for (ll i = 0; i < n; i++)
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pr;

const ll M = 1e3;
const ll INF = 2e9 + 10;
const ll N = 2e3 + 10;

int main() {
    //freopen("sweets.in", "r", stdin);
    ld d, l, v1, v2;
    cin >> d >> l >> v1 >> v2;
    cout << fixed << setprecision(12) << (l - d) / (v1 + v2);


}