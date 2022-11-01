#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;

const int N = 2e3;
const int INF = 2e9;

int a[N][N];
int mx[N];

int main() {
    //freopen("a.in", "r", stdin);
    ll n;
    cin >> n;
    map <ll, ll> m1, m2;
    fr(i, n) {
        ll x, y;
        cin >> x >> y;
        m1[x + y]++;
        m2[x - y]++;
    }
    ll ans = 0;
    for (auto it: m1)
        ans += it.second * (it.second - 1) / 2;
    for (auto it: m2)
        ans += it.second * (it.second - 1) / 2;
    cout << ans;
}