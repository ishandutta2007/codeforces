#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 1e9 + 10;
const ll MOD = 1e9 + 7;
const ll P = 29;
const ld EPS = 1e-9;

const int N = 2e5 + 10;

int a[N], l[N], r[N];

int main() {
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    fr(i, n)
        cin >> a[i];
    int l1 = -INF;
    fr(i, n) {
        if (a[i] == 0)
            l1 = i;
        l[i] = i - l1;
    }
    int r1 = INF;
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] == 0)
            r1 = i;
        r[i] = r1 - i;
    }
    fr(i, n)
        cout << min(l[i], r[i]) << " ";
}