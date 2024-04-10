#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (ll i = 0; i < n; ++i)
#define frab(i, a, b) for (ll i = a; i < b; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 2e5 + 1;
const int INF = 2e9;
const ld EPS = 1e-16;

int main() {
    ld start = clock() / CLOCKS_PER_SEC;
    srand(time(NULL));
    //freopen("spacepin.in", "r", stdin);
    //freopen("spacepin.out", "w", stdout);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << max(abs(a - c), abs(b - d));
}