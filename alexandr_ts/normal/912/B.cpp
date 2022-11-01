#include <bits/stdc++.h>
#define fr(i, n) for (ll i = 0; i < n; i++)
#define frab(i, a, b) for (ll i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 2e9 + 10;
const ll MOD = 1e9 + 7;
const ld EPS = 1e-9;
const ll N = 1e6 + 10;



int main() {
    //freopen("a.in", "r", stdin);
    ll n, k;
    cin >> n >> k;
    if (k == 1) {
        cout << n;
        return 0;
    }
    ll cur = 1;
    while (cur * 2 <= n)
        cur = cur * 2;
    cur = cur * 2 - 1;
    cout << cur;
}