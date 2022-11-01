#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; ++i)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e6 + 10;
const int M = 1e7 + 1;;
const ll INF = 2e9 + 10;
const ll MOD = 1000*1000*1000 + 7;
const ld EPS = 1e-9;

char a[5][5];

bool norm(int x, int y) {
    return x >= 0 && x < 4 && y >= 0 && y < 4;
}

bool check() {
    fr(i, 4)
        fr(j, 4)
            frab(i1, -1, 2)
                frab(j1, -1, 2)
                    if ((i1 || j1) && norm(i + 2 * i1, j + 2 * j1))
                        if (a[i][j] == 'x' && a[i + i1][j + j1] == 'x' &&
                            a[i + 2 * i1][j + 2 * j1] == 'x')
                        return true;
    return false;
}

int main() {
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    fr(i, 4)
        fr(j, 4)
            cin >> a[i][j];
    fr(i, 4)
        fr(j, 4) {
            if (a[i][j] != '.')
                continue;
            a[i][j] = 'x';
            if (check()) {
                cout << "YES";
                return 0;
            }
            a[i][j] = '.';
        }
    cout << "NO";
}