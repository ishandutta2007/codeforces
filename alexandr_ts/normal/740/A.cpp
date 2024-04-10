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

int a[N];

int main() {
    //freopen("a.in", "r", stdin);
    ll n, a, b, c;
    cin >> n >> a >> b >> c;
    if (n % 4 == 0)
        cout << 0;
    if (n % 4 == 3)
        cout << min(3 * c, min(a, b + c));
    if (n % 4 == 2)
        cout << min(2 * c, min(b, 2 * a));
    if (n % 4 == 1)
        cout << min(min(3 * a, a + b), c);
}