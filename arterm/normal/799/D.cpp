#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;

const int M = 100100;
const int N = 50;

int a, b, h, w, n;
int c[M];
int d[N][M];

void read() {
    cin >> a >> b >> h >> w;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> c[i];
}

int mul(ll x, ll y) {
    return min<ll>(x * y, M - 10);
}

int uax(int &x, int y) {
    return x = max(x, y);
}

void kill() {
    sort(c, c + n, greater<int>());
    n = min(n, 40);

    for (int i = 0; i < N; ++i)
        for (int s = 0; s < M; ++s)
            d[i][s] = -1;

    d[0][h] = w;
    for (int i = 0; i < n; ++i) {
        for (int x = 1; x < M; ++x) {
            if (d[i][x] != -1) {
                uax(d[i + 1][x], mul(c[i], d[i][x]));
                uax(d[i + 1][mul(x, c[i])], d[i][x]);
            }
        }
    }

    int ans = N;
    for (int i = 0; i <= n; ++i)
        for (int x = 1; x < M; ++x) {
            if (x >= a && d[i][x] >= b) {
                ans = min(ans, i);
            }
            if (x >= b && d[i][x] >= a) {
                ans = min(ans, i);
            }
        }

    if (ans == N)
        ans = -1;

    cout << ans << "\n";
}

int main() {
#ifdef LOCAL
  assert(freopen("d.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  read();
  kill();

}