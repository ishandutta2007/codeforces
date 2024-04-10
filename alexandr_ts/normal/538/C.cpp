#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef pair <long long, long long> pr;
typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;
const ll INF = 2e9;
const ll N = 1e6 + 1;
const ld EPS = 1e-8;

int b[N], a[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    fr(i, m)
        cin >> a[i] >> b[i];
    fr(i, m - 1)
        if (abs(a[i] - a[i + 1]) < abs(b[i] - b[i + 1])) {
            cout << "IMPOSSIBLE";
            return 0;
        }
    int ans = -INF;
    fr(i, m - 1) {
        if (b[i] <= b[i + 1]) {
            int tmp = a[i + 1] - a[i] - b[i + 1] + b[i];
            ans = max(ans, tmp / 2 + b[i + 1]);
        }
        else {
            int tmp = a[i + 1] - a[i] - b[i] + b[i + 1];
            ans = max(ans, tmp / 2 + b[i]);
        }
    }
    ans = max(ans, b[0] + a[0] - 1);
    ans = max(ans, b[m - 1] + n - a[m - 1]);
    cout << ans;
}