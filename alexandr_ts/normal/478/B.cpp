#include <bits/stdc++.h>
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define frb(i, n) for (int i = n - 1; i >= 0; i--)

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e4;
const int INF = 2 * 1e9 + 1;

int a[N];

int main() {
    //freopen("a.in", "r", stdin);
    ll n, m;
    cin >> n >> m;
    ll x = n / m, y = n % m;
    cout << y * (x + 1) * (x) / 2 + (m - y) * x * (x - 1) / 2 << " ";
    cout << (n - m) * (n - m + 1) / 2;
}