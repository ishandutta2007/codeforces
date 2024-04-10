/// Alexandr Tsaplin 18.08.16

#include "bits/stdc++.h"
#define fr(i, n) for (ll i = 0; i < n; i++)
#define frab(i, a, b) for (ll i = a; i < b; i++)
#define pb push_back
#define mp make_pair
#define TASK_NAME "salesman"

using namespace std;

typedef long long ll;
typedef long double ld;

const ll N = 1e5;
const ll INF = 2e9 + 1;
const ll MOD = 1e9 + 7;

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);
    int x, y;
    cin >> x >> y;
    int n;
    cin >> n;
    ld ans = INF;
    fr(i, n) {
        int x1, y1, v1;
        cin >> x1 >> y1 >> v1;
        ans = min(ans, (ld)sqrt((x1 - x) * (x1 - x) + (y1 - y) * (y1 - y)) / v1);
    }
    cout << fixed << setprecision(12) << ans;
}