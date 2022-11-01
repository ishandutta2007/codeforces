#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair
#define s second
#define f first

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e5 + 10;
const ll INF = 2e9 + 1;
const int MOD = 1e9 + 7;
const ld EPS = 1e-9;

int a[N], p[N], pos[N];
int b[N];

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    int n, l, r;
    cin >> n >> l >> r;
    fr(i, n)
        cin >> a[i];
    fr(i, n) {
        cin >> p[i];
        pos[p[i]] = i;
    }

    int lastc = -INF;
    frab(i, 1, 1 + n) {
        b[pos[i]] = max(l, lastc + 1 + a[pos[i]]);
        if (b[pos[i]] > r) {
            cout << -1;
            return 0;
        }
        lastc = b[pos[i]] - a[pos[i]];
    }

    fr(i, n)
        cout << b[i] << " ";
}