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

ll a[N], b[N];
bool used[N];

int main() {
    //freopen("a.in", "r", stdin);
    int n, a, b, c;
    int ans = -INF;
    cin >> n >> a >> b >> c;
    for (int i = 0; i * a <= n; i++)
        for (int j = 0; j * b + i * a <= n; j++) {
            int k = (n - j * b - a * i) / c;
            if (n == a * i + b * j + c * k) {
                ans = max(ans, i + j + k);
            }
        }
    cout << ans;
}