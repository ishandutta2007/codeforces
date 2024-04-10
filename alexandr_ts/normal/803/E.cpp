#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 1e9 + 10;
const ll MOD = 1e9 + 7;
const ll P = 29;
const ld EPS = 1e-9;

const int N = 2e3 + 10;

int a[N][N];

int main() {
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    fr(i, n + 1)
        frab(j, 0, 2 * k + 1)
            a[i][j] = false;
    a[0][k] = true;
    frab(i, 1, n + 1)
        fr(j, 2 * k + 1) {
            if (j == 0 || j == 2 * k)
                if (i != n)
                    continue;
            if (s[i - 1] == 'W') {
                if (j >= 1 && a[i - 1][j - 1])
                    a[i][j] = true;
            }
            if (s[i - 1] == 'D') {
                if (a[i - 1][j])
                    a[i][j] = true;
            }
            if (s[i - 1] == 'L') {
                if (j < 2 * k && a[i - 1][j + 1])
                    a[i][j] = true;
            }
            if (s[i - 1] == '?') {
                frab(i1, -1, 2)
                    if (j + i1 >= 0 && j + i1 <= 2 * k && a[i - 1][j + i1])
                        a[i][j] = true;
            }
        }
    if (a[n][0] || a[n][2 * k]) {
        int cur;
        if (a[n][0])
            cur = 0;
        else
            cur = 2 * k;
        for (int i = n; i >= 1; i--) {

            if (a[i - 1][cur] && (s[i - 1] == '?' || s[i - 1] == 'D'))
                s[i - 1] = 'D';
            else if (cur >= 1 && a[i - 1][cur - 1] && (s[i - 1] == '?' || s[i - 1] == 'W')) {
                s[i - 1] = 'W', cur--;
            }
            else if (cur < 2 * k && a[i - 1][cur + 1] && (s[i - 1] == '?' || s[i - 1] == 'L')) {
                s[i - 1] = 'L', cur++;
            }
        }
        cout << s;
    }
    else {
        cout << "NO";
        return 0;
    }
}