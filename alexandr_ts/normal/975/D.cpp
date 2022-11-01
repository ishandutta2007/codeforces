#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 2e9 + 10;
const ll MOD = 1e9 + 7;
const ld EPS = 1e-9;
const ld PI = acos(-1);
const int M = 1e3 + 10;
const int N = 1e6 + 100;

int x[N], vx[N], vy[N];

ll solve() {
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);
    for (int i = 0; i < n; i++)
        scanf("%d %d %d", &x[i], &vx[i], &vy[i]);
    map <ll, int> m;
    for (int i = 0; i < n; i++)
        m[(ll)vy[i] - (ll)a * vx[i]]++;
    ll ans = 0;
    map <pair <int, int>, int> m2;
    for (int i = 0; i < n; i++)
        m2[{vx[i], vy[i]}]++;
    for (auto t: m)
        ans += ((ll)t.second * (t.second - 1));
    for (auto t: m2)
        ans -= ((ll)t.second * (t.second - 1));
    return ans;
}

int main() {
    //freopen("a.in", "r", stdin);
    cout << solve();
}