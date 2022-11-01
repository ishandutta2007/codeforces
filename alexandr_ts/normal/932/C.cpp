#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 2e9 + 10;
const ll MOD = 1e9 + 7;
const ld EPS = 1e-9;
const ld PI = acos(-1);
const int M = 1e3 + 10;
const int P = 29;
const int N = 1e6 + 10;

int ans[N];

int main() {
    //ios_base::sync_with_stdio(false);
    //freopen("a.in", "r", stdin);
    int n, a, b;
    cin >> n >> a >> b;

    for (int i = 0; i < n; i++)
        ans[i] = i + 1;
    for (int x = 0; x <= n / a; x++) {
        if ((n - x * a) % b == 0) {
            int y = (n - x * a) / b;
            int cur = 1;
            for (int i = 0; i < x; i++) {
                rotate(ans + i * a, ans + i * a + 1, ans + i * a + a);
            }
            int t = x * a;
            for (int i = 0; i < y; i++)
                rotate(ans + t + i * b, ans + t + 1 + i * b, ans + t + b + i * b);
            for (int i = 0; i < n; i++)
                cout << ans[i] << " ";
            return 0;
        }
    }
    cout << -1;
}