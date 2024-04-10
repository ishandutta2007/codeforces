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

const int N = 1e5 + 10;
const ll INF = 2e9 + 1;
const int MOD = 1e9 + 7;
const ld EPS = 1e-9;

string s[N];

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    fr(i, n)
        cin >> s[i];
    int ans = INF;
    for (int i1 = 0; i1 < n; i1++) {
        int curt = INF;
        for (int j = 0; j < m; j++)
            if (isdigit(s[i1][j]))
                curt = min(curt, min(j, m - j));
        if (curt == INF) continue;

        for (int i2 = 0; i2 < n; i2++) {
            if (i2 == i1) continue;
            int curt2 = INF;
            for (int j = 0; j < m; j++)
                if (isalpha(s[i2][j]))
                    curt2 = min(curt2, min(j, m - j));
            if (curt2 == INF) continue;

            for (int i3 = 0; i3 < n; i3++) {
                if (i3 == i1 || i3 == i2) continue;
                int curt3 = INF;
                for (int j = 0; j < m; j++)
                    if (s[i3][j] == '#' || s[i3][j] == '*' || s[i3][j] == '&')
                        curt3 = min(curt3, min(j, m - j));
                ans = min(ans, curt + curt2 + curt3);
            }

        }
    }
    cout << ans;
}