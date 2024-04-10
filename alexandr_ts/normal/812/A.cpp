#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define pb push_back
#define mp make_pair
#define frab(i, a, b) for (int i = a; i < b; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;
const int INF = 2e9 + 10;
const ld EPS = 1e-9;
const int M = 1e2 + 2;
const int N = 1e6 + 10;

int a[M][M];

int main() {
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);

    fr(i, 4)
        fr(j, 4)
            cin >> a[i][j];

    fr(i, 4)
        if (a[i][3]) {
            if (a[i][0] || a[i][1] || a[i][2]) {
                cout << "YES";
                return 0;
            }
            if (a[(i + 1) % 4][0] || a[(i + 3) % 4][2] || a[(i + 2)%4][1]) {
                cout << "YES";
                return 0;
            }
        }
    cout << "NO";
}