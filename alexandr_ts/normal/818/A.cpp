#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (ll i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;
const ll INF = 2e9 + 10;
const ld EPS = 1e-9;
const int N = 1e6 + 2;



int main() {
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    ll n, k;
    cin >> n >> k;
    ll t = n / (2 * (k + 1));
    cout << t << " " << t * k << " " << n - t * (k + 1);
}