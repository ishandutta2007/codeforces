#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 2e5 + 5;
const int M = 500 * 1000 * 1000;
const ll MOD = 1000 * 1000 * 1000 + 7;
const ll INF = 2e9 + 10;
const ld EPS = 1e-7;

ll a[N];

int main() {
    //freopen("a.in", "r", stdin);
    ll n, h, k;
    cin >> n >> h >> k;
    fr(i, n)
        cin >> a[i];
    ll t = 0;
    ll cur = 0;
    ll curused = 0;
    while (cur < n) {
        while (cur < n && curused + a[cur] <= h)
            curused += a[cur++];
        ll t1 = max(1ll, (curused + a[cur] - h + k - 1) / k);
        curused = max(0ll, curused - k * t1);
        t += t1;
    }
    t += (curused + k - 1) / k;
    cout << t;
}