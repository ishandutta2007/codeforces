#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define pb push_back
#define mp make_pair
#define frab(i, a, b) for (int i = a; i < b; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;
const ld PI = acos(-1);
const ll MAX = 2e7 + 10;
const ll INF = 1e9;
const ld EPS = 1e-9;
const int M = 1e2 + 12;
const int N = 1e6 + 10;

string s[M];
string t[M];

int dx[] = {0, 1, 1, 1};
int dy[] = {1, 0, 1, -1};

bool check() {
    fr(i, 10)
        fr(j, 10)
            fr(k, 4) {
                int x1 = i + dx[k] * 4;
                int y1 = j + dy[k] * 4;
                if (x1 >= 0 && x1 <= 9 && y1 >= 0 && y1 <= 9) {
                    bool ok = true;
                    frab(i1, 0, 5)
                        if (t[i + i1 * dx[k]][j + i1 * dy[k]] != 'X')
                            ok = false;
                    if (ok)
                        return true;
                }
            }
    return false;
}

int main() {
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    fr(i, 10) {
        cin >> s[i];
        t[i] = s[i];
    }

    fr(i, 10)
        fr(j, 10) {
            if (s[i][j] == '.')
                t[i][j] = 'X';
            if (check()) {
                cout << "YES";
                return 0;
            }
            t[i][j] = s[i][j];
        }
    cout << "NO";


}