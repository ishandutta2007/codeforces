#include <bits/stdc++.h>
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define frb(i, n) for (int i = n - 1; i >= 0; i--)

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e5;
const int INF = 2 * 1e9 + 1;
const ld EPS = 1e-9;

int a[N], c[N];
vector <int> b;

int main() {
    //freopen("a.in", "r", stdin);
    int n;
    cin >> n;
    fr(i, n)
        cin >> a[i];
    fr(i, n) {
        int ans = INF;
        if (i > 0)
            ans = min(ans, a[i] - a[i - 1]);
        if (i < n - 1)
            ans = min(ans, a[i + 1] - a[i]);
        cout << ans << " ";
        ans = -INF;
        if (i > 0)
            ans = max(ans, a[i] - a[0]);
        if (i < n - 1)
            ans = max(ans, a[n - 1] - a[i]);
        cout << ans << endl;
    }
}