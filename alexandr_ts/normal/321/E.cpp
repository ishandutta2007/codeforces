#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < (int)n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;
const ld EPS = 1e-6;
const ll INF = 1e9 + 10;
const int M = 810;
const int N = 4010;

int a[N][N];
int d[M][N];
int calc[N][N];
int l[N][N];

void prec(int n) {
    fr(i, n + 1)
        fill(calc[i], calc[i] + n + 1, INF);
    fr(i, n)
        fr(j, n)
            l[i][j] = (j ? l[i][j - 1] : 0) + a[i][j];
    fr(i, n) {
        calc[i][i] = 0;
        int cur = 0;
        frab(j, i + 1, n) {
            cur += l[j][j - 1] - (i ? l[j][i - 1] : 0);
            calc[i][j] = cur;
        }
    }
}

void solve(int m, int kleft, int kright, int jleft, int jright) {
    if (jleft > jright) return;
    int j = (jleft + jright) / 2;
    int ansk = kleft;
    frab(k, kleft, min(kright + 1, j)) {
        int c = calc[k][j - 1];
        if (d[m - 1][k] + c < d[m][j])
            d[m][j] = d[m - 1][k] + c, ansk = k;
    }
    solve(m, kleft, ansk, jleft, j - 1);
    solve(m, ansk, kright, j + 1, jright);
}

char s[2 * N];

int main() {
    //srand(time(NULL));
    //ios_base::sync_with_stdio(false);
    //freopen("a.in", "r", stdin);
    int n, m1;
    //cin >> n >> m1;
    scanf("%d %d", &n, &m1);
    gets(s);
    fr(i, n) {
        gets(s);
        fr(j, n)
            a[i][j] = s[j * 2] - '0';
    }

    prec(n);
//    fr(i, n) {
//        fr(j, n)
//            cout << calc[i][j] << " ";cout << endl;}
    //cout << calc[2][6];

    frab(i, 0, m1 + 1)
        frab(j, 0, n + 1)
            d[i][j] = INF;
    d[0][0] = 0;

    frab(m, 1, m1 + 1)
        solve(m, 0, n, 1, n);
    cout << d[m1][n];
}