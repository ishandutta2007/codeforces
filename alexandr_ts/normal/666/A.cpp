#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e5 + 1;
const ld EPS = 1e-9;
const ll INF = 2e9 + 10;
const ll MOD = 1e9 + 7;

int d[5][N];

int main() {
    srand(time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("a.in", "r", stdin);
    string s;
    cin >> s;
    set <string> suf;
    int n = s.size();
    d[2][n - 2] = 1;
    d[3][n - 3] = 1;
    if (n >= 7)
        suf.insert(s.substr(n - 2, 2));
    if (n >= 8)
        suf.insert(s.substr(n - 3, 3));

    for (int i = n - 4; i >= 5; i--) {
        if (d[2][i + 2]) {
            if (s[i] != s[i + 2] || s[i + 1] != s[i + 3]) {
                d[2][i] = 1;
                suf.insert(s.substr(i, 2));
            }
        }
        if (d[3][i + 2]) {
            d[2][i] = 1;
            suf.insert(s.substr(i, 2));
        }

        if (d[3][i + 3]) {
            if (s[i] != s[i + 3] || s[i + 1] != s[i + 4] || s[i + 2] != s[i + 5]) {
                d[3][i] = 1;
                suf.insert(s.substr(i, 3));
            }
        }
        if (d[2][i + 3]) {
            d[3][i] = 1;
            suf.insert(s.substr(i, 3));
        }
    }
    cout << suf.size() << endl;
    for (auto it: suf)
        cout << it << endl;
}