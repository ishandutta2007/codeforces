#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (ll i = 0; i < n; ++i)
#define frab(i, a, b) for (ll i = a; i < b; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 2e5 + 1;
const int INF = 2e9;
const ld EPS = 1e-16;

int a[N][3];
int col[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ld start = clock() / CLOCKS_PER_SEC;
    srand(time(NULL));
    //freopen("spacepin.in", "r", stdin);
    //freopen("spacepin.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    fr(i, m)
        fr(j, 3) {
            cin >> a[i][j];
        }
    fr(i, m) {
        sort(a[i], a[i] + 3);
        bool f1 = false, f2 = false, f3 = false;
        fr(j, 3)
            if (col[a[i][j]] == 1)
                f1 = true;
            else if (col[a[i][j]] == 2)
                f2 = true;
            else if (col[a[i][j]] == 3)
                f3 = true;
        fr(j, 3) {
            if (!col[a[i][j]]) {
                if (!f1) {
                    col[a[i][j]] = 1;
                    f1 = true;
                }
                else if (!f2) {
                    col[a[i][j]] = 2;
                    f2 = true;
                }
                else if (!f3) {
                    col[a[i][j]] = 3;
                    f3 = true;
                }
            }
        }
    }
    frab(i, 1, n + 1)
        cout << col[i] << " ";
}