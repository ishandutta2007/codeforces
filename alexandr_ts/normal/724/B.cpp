#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair
#define s second
#define f first

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e3 + 10;
const ll INF = 2e5 + 1;
const int MOD = 1e9 + 7;
const ld EPS = 1e-9;

int a[N][N], b[N][N];

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    fr(i, n)
        fr(j, m) {
            cin >> a[i][j];
            b[i][j] = a[i][j];
        }
    fr(i1, m)
        frab(i2, i1, m) {
            fr(i, n)
                swap(b[i][i1], b[i][i2]);
            bool er = false;
            fr(i, n) {
                int cnt = 0;
                fr(j, m)
                    if (b[i][j] != j + 1)
                        cnt++;
                if (cnt > 2)
                    er = true;
            }
            if (!er) {
                cout << "YES";
                return 0;
            }
            fr(i, n)
                swap(b[i][i1], b[i][i2]);
        }

    fr(i1, m)
        frab(i2, i1 + 1, m) {
            bool er = false;
            fr(i, n) {
                int cnt = 0;
                fr(j, m) {
                    if (j == i1)
                        if (b[i][j] != i2 + 1)
                            cnt++;
                    if (j == i2)
                        if (b[i][j] != i1 + 1)
                            cnt++;
                    if (j != i1 && j != i2)
                        if (b[i][j] != j + 1)
                            cnt++;
                }
                if (cnt > 2)
                    er = true;
            }
            if (!er) {
                cout << "YES";
                return 0;
            }
        }
    cout << "NO";
}