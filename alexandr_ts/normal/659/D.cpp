#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e6 + 3;
const ll MOD = 10000*10000;
const ll INF = 2e9 + 10;

int x[N], y[N];

int main() {
    ios_base::sync_with_stdio(false);
    //freopen("a.in", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n + 1; i++)
        cin >> x[i] >> y[i];
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int x1 = x[i] - x[(n + i - 1) % n];
        int y1 = y[i] - y[(n + i - 1) % n];
        int x2 = x[(i + 1)] - x[i];
        int y2 = y[i + 1] - y[i];
        if (x1 == 0)
            if (y1 > 0 && x2 < 0 || y1 < 0 && x2 > 0)
                ans++;
        if (y1 == 0)
            if (x1 > 0 && y2 > 0 || x1 < 0 && y2 < 0)
                ans++;
    }
    cout << ans;
}