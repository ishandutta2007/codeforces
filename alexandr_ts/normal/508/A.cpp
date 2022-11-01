#include <bits/stdc++.h>
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define SSTR(x) dynamic_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()

using namespace std;

typedef long long ll;
typedef long double ld;

const ll N = 1e3 + 10;
const ld EPS = 1e-8;
const ll INF = 2 * 1e9 + 1;
const ll MAX = 1e9;

bool a[N][N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    srand(time(NULL));
    //freopen("input.txt", "r", stdin);
    int n, m, k, x, y;
    cin >> n >> m >> k;
    fr(i, k) {
        cin >> x >> y;
        a[x][y] = 1;
        if (a[x - 1][y + 1] && a[x][y + 1] && a[x - 1][y] || a[x][y + 1] && a[x + 1][y + 1] && a[x + 1][y] ||
            a[x - 1][y] && a[x - 1][y - 1] && a[x][y - 1] || a[x][y - 1] && a[x + 1][y - 1] && a[x + 1][y]) {
                cout << i + 1;
                return 0;
            }
    }
    cout << 0;

}