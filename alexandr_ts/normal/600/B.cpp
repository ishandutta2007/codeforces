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

int a[N], b[N], c[N], d[N];

int main() {
    //freopen("a.in", "r", stdin);
    int n, m;
    cin >> n >> m;
    fr(i, n)
        cin >> a[i];
    fr(i, m)
        cin >> b[i];
    sort(a, a + n);
    fr(i, m) {
        auto it = upper_bound(a, a + n, b[i]) - a;
        cout << it << " ";
    }
}