#include <bits/stdc++.h>
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define frb(i, n) for (int i = n - 1; i >= 0; i--)

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e3;
const int INF = 2 * 1e9 + 1;

int a[N];

int main() {
    //freopen("a.in", "r", stdin);
    int n;
    cin >> n;
    fr(i, n)
        cin >> a[i];
    int ans = INF;
    frab(i, 1, n - 1) {
        int curans = -INF;
        fr(j, i - 1)
            curans = max(curans, a[j + 1] - a[j]);
        frab(j, i + 1, n - 1)
            curans = max(curans, a[j + 1] - a[j]);
        curans = max(a[i + 1] - a[i - 1], curans);
        ans = min(ans, curans);
    }
    cout << ans;
}