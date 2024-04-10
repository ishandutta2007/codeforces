#include "bits/stdc++.h"
#define fr(i, n) for (ll i = 0; i < n; i++)
#define frab(i, a, b) for (ll i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const ll N = 1e3 + 1;
const ll INF = 2e9 + 1;
const ll MOD = 1e9 + 7;

int v[N], u[N], l[N];
bool sk[N];

int main() {
    //freopen("a.in", "r", stdin);
    ll x;
    cin >> x;
    ll x1 = x;
    if (x <= 2) {
        cout << -1;
        return 0;
    }
    ll cur = 1;
    while (x % 2 == 0) {
        x /= 2;
        cur *= 2;
    }
    if (x == 1) {
        cout << x1 * x1 / 4 - 1 << " " << x1 * x1 / 4 + 1;
        return 0;
    }
//    if (x == 1) {
//        cout << -1;
//        return 0;
//    }
    if (x % 2) {
        cout << cur * (x * x - 1) / 2 << " " << cur * (x * x + 1) / 2;
    }
}