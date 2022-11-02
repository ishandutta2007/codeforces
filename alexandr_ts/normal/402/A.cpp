#include <bits/stdc++.h>
#define fr(i, n) for (ll i = 0; i < n; i++)
#define frab(i, a, b) for (ll i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e5;
const ll INF = 2e9;
const ld EPS = 1e-8;
const int MAX = 1e6 + 1;

ll a[N];

int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll k, a, b, v;
    cin >> k >> a >> b >> v;
    for (ll i = 0; i <= MAX; i++) {
        ll cnt = min(i + b, i * (k));
        if (v * cnt >= a) {
            cout << i;
            return 0;
        }
    }
}