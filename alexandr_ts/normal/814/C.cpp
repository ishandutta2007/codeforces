#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; ++i)
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 2e9 + 7;
const int M = 1501;
const int POW = 20;
const ll MOD = 1e9 + 7;
const ld EPS = 1e-9;

const int N = 1e6 + 10;

short int d[26][M][M];
short int ans[26][M];

int main() {
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    string s;
    cin >> s;

    fr(al, 26)
        fr(l, n) {
            int cur = 0;
            while (s[l + cur] == al + 'a') cur++;
            d[al][l][0] = cur;
            for (int i = 1; i <= n; i++) {
                cur++;
                if (cur + l >= n) cur = n - l;
                while (l + cur < n && s[l + cur] == al + 'a')
                    cur++;
                d[al][l][i] = cur;
                ans[al][i] = max((int)ans[al][i], cur);
            }
        }

    int q;
    cin >> q;
    fr(i, q) {
        int m;
        cin >> m;
        char ch;
        cin >> ch;
        cout << ans[ch - 'a'][m] << "\n";
    }
}