#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e3 + 1;
const int INF = 2e9 + 1;
const ll MOD = 1e9 + 7;
const ld EPS = 1e-8;
const int MAX = 1e6 + 1;

char a[N][N];
int d[N][N], cnt[N][N];
int pr1[N][N], pr2[N][N];

int Cnt(int x1, int y1, int x2, int y2) {
    return d[x2][y2] - d[x1 - 1][y2] - d[x2][y1 - 1] + d[x1 - 1][y1 - 1];
}

int main() {
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    fr(i, n)
        fr(j, m)
            cin >> a[i + 1][j + 1];
    frab(i, 1, 1 + n)
        frab(j, 1, 1 + m)
            if (a[i][j] == '.') {
                if (i > 1 && a[i - 1][j] == '.')
                    cnt[i][j]++;
                if (j > 1 && a[i][j - 1] == '.')
                    cnt[i][j]++;
            }
    frab(i, 1, 1 + n)
        frab(j, 1, 1 + m) {
            if (i == 1 && j == 1) continue;
            if (i == 1)
                d[i][j] = d[i][j - 1] + cnt[i][j];
            if (j == 1)
                d[i][j] = d[i - 1][j] + cnt[i][j];
            if (i != 1 && j != 1)
                d[i][j] = d[i - 1][j] + d[i][j - 1] - d[i - 1][j - 1] + cnt[i][j];
        }

    frab(i, 1, 1 + n)
        frab(j, 1, 1 + m) {
            //if (j != 1)
            pr1[i][j] = pr1[i][j - 1];
            if (a[i][j] == '.' && a[i][j - 1] == '.')
                pr1[i][j]++;
        }

    frab(j, 1, 1 + m)
        frab(i, 1, 1 + n) {
            if (i != 1)
                pr2[i][j] = pr2[i - 1][j];
            if (a[i][j] == '.' && a[i - 1][j] == '.')
                pr2[i][j]++;
        }
    int qua;
    cin >> qua;
    fr(i, qua) {
        int x1, y1, x2, y2;
        int ans = 0;
        cin >> x1 >> y1 >> x2 >> y2;
        //x1--, y1--, x2--, y2--;
        ans = Cnt(x1 + 1, y1 + 1, x2, y2);
        //cout << ans << " ";
        ans += max(0, pr1[x1][y2] - pr1[x1][y1]);
        //cout << ans << " ";
        ans += max(0, pr2[x2][y1] - pr2[x1][y1]);
        cout << ans << endl;
    }




}