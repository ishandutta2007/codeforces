#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 998244353;
const ll INF = 2e9 + 10;
const ll MAX = 1e14 + 10;
const ld EPS = 1e-9;
const int N = 3e5 + 10;

char ch[N];

string CH = "AGCT";
int NUM(char c) {
    return CH.find(c);
}

vector<vector<int> > ans;

int d[2][N][5];

int tmp[N];

int solve1(int n, int m, int ansDif, vector<vector<int> >& a) {
    vector<int> perm = {0, 1, 2, 3};
    vector<vector<int> > temp(n, vector<int>(m, 0));

    do {
        int curDif = 0;
        fr(i, n) {

            int firstN = perm[0];
            int secondN = perm[1];

            if (i % 2) {
                firstN = perm[2];
                secondN = perm[3];
            }

            for (int j = 0; j < m; j += 2) {
                tmp[j] = firstN;
                tmp[j + 1] = secondN;
            }
            int cntNorm = 0;
            fr(j, m)
                if (a[i][j] != tmp[j])
                    cntNorm++;

            for (int j = 0; j <= m; j += 2) {
                tmp[j] = secondN;
                tmp[j + 1] = firstN;
            }
            int cntSw = 0;
            fr(j, m)
                if (a[i][j] != tmp[j])
                    cntSw++;

            if (cntNorm < cntSw) {
                for (int j = 0; j < m; j += 2) {
                    tmp[j] = firstN;
                    tmp[j + 1] = secondN;
                }
                curDif += cntNorm;
            }
            else {
                curDif += cntSw;
            }

            fr(j, m)
                temp[i][j] = tmp[j];
        }

        if (curDif < ansDif) {
            ansDif = curDif;
            ans = temp;

        }
    } while (next_permutation(perm.begin(), perm.end()));
    return ansDif;
}

int solve2(int n, int m, int ansDif, vector<vector<int> >& a) {
    vector<int> perm = {0, 1, 2, 3};
    vector<vector<int> > temp(n, vector<int>(m, 0));

    do {
        int curDif = 0;
        temp[0][0] = perm[0];
        temp[0][1] = perm[1];
        temp[1][0] = perm[2];
        temp[1][1] = perm[3];
        frab(j, 2, m) {
            if (j % 2 == 0) {
                if (d[0][j][temp[0][0]] + d[1][j][temp[1][0]] < d[1][j][temp[0][0]] + d[0][j][temp[1][0]]) {
                    temp[0][j] = temp[1][0];
                    temp[1][j] = temp[0][0];
                } else {
                    temp[0][j] = temp[0][0];
                    temp[1][j] = temp[1][0];
                }
            } else {
                if (d[0][j][temp[0][1]] + d[1][j][temp[1][1]] < d[1][j][temp[0][1]] + d[0][j][temp[1][1]]) {
                    temp[0][j] = temp[1][1];
                    temp[1][j] = temp[0][1];
                } else {
                    temp[0][j] = temp[0][1];
                    temp[1][j] = temp[1][1];
                }
            }
        }

        frab(i, 2, n)
            fr(j, m)
                temp[i][j] = temp[i % 2][j];
        fr(i, n)
            fr(j, m)
                if (a[i][j] != temp[i][j])
                    curDif++;
        if (curDif < ansDif) {
            ansDif = curDif;
            ans = temp;
        }
    } while (next_permutation(perm.begin(), perm.end()));
    return ansDif;
}

void solve() {
    int n, m;
    scanf("%d %d", &n, &m);
    vector<vector<int> > a(n, vector<int>(m));
    fr(i, n) {
        scanf("%s", &ch);
        fr(j, m) {
            a[i][j] = NUM(ch[j]);
        }
    }

    fr(i, n)
        fr(j, m)
            d[i % 2][j][a[i][j]]++;



    int dif = n * m + 1;

    int dif1 = solve1(n, m, dif, a);

    int tmp = solve2(n, m, dif1, a);

    //cout << dif1 << " " << tmp << endl;

    fr(i, n) {
        fr(j, m)
            cout << CH[ans[i][j]];
        cout << endl;
    }

}



int main() {
    //freopen("a.in", "r", stdin);
    //ios_base::sync_with_stdio(false);
    solve();

}