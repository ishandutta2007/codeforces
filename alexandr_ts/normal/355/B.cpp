#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (ll i = 0; i < n; i++)
#define frab(i, a, b) for (ll i = a; i < b; i++)

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 3e5 + 10;
const int INF = 2e9 + 1;
const ll MOD = 1e9 + 7;
const ld EPS = 1e-8;
const int MAX = 5e6 + 1;
const int MAX2 = 1e4;

int a[N], b[N];

int main() {
    //freopen("input.txt", "r", stdin);
    int c1, c2, c3, c4;
    cin >> c1 >> c2 >> c3 >> c4;
    int n, m;
    cin >> n >> m;
    fr(i, n)
        cin >> a[i];
    fr(i, m)
        cin >> b[i];

    int x1 = 0;
    fr(i, n)
        x1 += min(c1 * a[i], c2);
    x1 = min(x1, c3);

    int x2 = 0;
    fr(i, m)
        x2 += min(c1 * b[i], c2);
    x2 = min(x2, c3);

    cout << min(c4, x1 + x2);

}