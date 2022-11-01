#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair
using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 2e5 + 10;
const int M = 301;
const int INF = 2e9 + 10;
const int MOD = 1e9 + 7;

bool a[M][M][2][8];
bool used[M][M];
int t[N];

int main() {
    //freopen("a.in", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> t[i];
    t[0]--;
    a[M / 2][M / 2][0][1] = true;
    used[M / 2][M / 2] = true;
    fr(i, n) {
        fr(x, M)
            fr(y, M) {
                if (a[x][y][i % 2][0]) {

                    fr(i1, t[i] + 1)
                        used[x - i1][y - i1] = true;
                    a[x - t[i]][y - t[i]][(i + 1) % 2][1] = a[x - t[i]][y - t[i]][(i + 1) % 2][7] = true;
                }
                if (a[x][y][i % 2][1]) {

                    fr(i1, t[i] + 1)
                        used[x - i1][y] = true;
                    a[x - t[i]][y][(i + 1) % 2][0] = a[x - t[i]][y][(i + 1) % 2][2] = true;
                }
                if (a[x][y][i % 2][2]) {
                    fr(i1, t[i] + 1)
                        used[x - i1][y + i1] = true;
                    a[x - t[i]][y + t[i]][(i + 1) % 2][1] = a[x - t[i]][y + t[i]][(i + 1) % 2][3] = true;
                }
                if (a[x][y][i % 2][3]) {
                    fr(i1, t[i] + 1)
                        used[x][y + i1] = true;
                    a[x][y + t[i]][(i + 1) % 2][2] = a[x][y + t[i]][(i + 1) % 2][4] = true;
                }
                ///4
                if (a[x][y][i % 2][4]) {
                    fr(i1, t[i] + 1)
                        used[x + i1][y + i1] = true;
                    a[x + t[i]][y + t[i]][(i + 1) % 2][3] = a[x + t[i]][y + t[i]][(i + 1) % 2][5] = true;
                }
                if (a[x][y][i % 2][5]) {
                    fr(i1, t[i] + 1)
                        used[x + i1][y] = true;
                    a[x + t[i]][y][(i + 1) % 2][4] = a[x + t[i]][y][(i + 1) % 2][6] = true;
                }
                if (a[x][y][i % 2][6]) {
                    fr(i1, t[i] + 1)
                        used[x + i1][y - i1] = true;
                    a[x + t[i]][y - t[i]][(i + 1) % 2][5] = a[x + t[i]][y - t[i]][(i + 1) % 2][7] = true;
                }
                if (a[x][y][i % 2][7]) {
                    //cout << x << " ! " << y << endl;
                    fr(i1, t[i] + 1)
                        used[x][y - i1] = true;
                    a[x][y - t[i]][(i + 1) % 2][6] = a[x][y - t[i]][(i + 1) % 2][0] = true;
                }
            }
        fr(x, M)
            fr(y, M)
                fr(i1, 8)
                    a[x][y][(i % 2)][i1] = false;
    }
    int ans = 0;
    fr(i, M)
        fr(j, M) {
            if (used[i][j]) {
                //cout << i << " " << j << endl;
                ans++;
            }
        }
    cout << ans;
}