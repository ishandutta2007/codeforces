#include <bits/stdc++.h>
#define fr(i, n) for (ll i = 0; i < n; i++)
#define frab(i, a, b) for (ll i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 6e6 + 10;
const ll INF = 2e9;
const ld EPS = 1e-8;
const int MAX = 6e6 + 1;

int a[N];

int main() {
    //freopen("input.txt", "r", stdin);
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    ll n, k, l, r, sall, sk;
    cin >> n >> k >> l >> r >> sall >> sk;
    ll mn = sk / k;
    ll mx = sk / k + 1;
    ll cntMx = sk % k;
    ll cntMn = k - cntMx;
    fr(i, cntMx)
        cout << mx << " ";
    fr(i, cntMn)
        cout << mn << " ";
    if (n != k) {
        mn = (sall - sk) / (n - k);
        mx = (sall - sk) / (n - k) + 1;
        cntMx = (sall - sk) % (n - k);
        cntMn = n - k - cntMx;
        fr(i, cntMx)
            cout << mx << " ";
        fr(i, cntMn)
            cout << mn << " ";
    }
}