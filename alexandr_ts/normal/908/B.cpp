#include <bits/stdc++.h>
#define fr(i, n) for (ll i = 0; i < n; i++)
#define frab(i, a, b) for (ll i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 2e9 + 10;
const ll MOD = 1e9 + 7;
const ld EPS = 1e-9;
const ll N = 1e3 + 10;

pair <int, int> d[] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

string s[N];

int dx[4], dy[4];

int main() {
    //freopen("a.in", "r", stdin);
    int n, m;
    pair <int, int> st, en;
    cin >> n >> m;
    for (int i = 0; i< n; i++) {
        cin >> s[i];
        fr(j, m)
            if (s[i][j] == 'S') st = mp(i, j);
            else if (s[i][j] == 'E') en = mp(i, j);
    }
    string t;
    cin >> t;

    int ans = 0;

    for (int i = 0; i < 24; i++) {
        next_permutation(d, d + 4);
        int x = st.first, y = st.second;
        bool er = false;
        bool fnd = false;
        for (int j = 0; j < t.size(); j++) {
            int x1 = x + d[t[j] - '0'].first;
            int y1 = y + d[t[j] - '0'].second;
            if (x1 < 0 || x1 >= n || y1 < 0 || y1 >= m || s[x1][y1] == '#') {
                er = true;
                break;
            }
            else if (s[x1][y1] == 'E') {
                fnd = true;
                break;
            }
            x = x1, y = y1;
        }
        if (!er && fnd)
            ans++;
    }
    cout << ans;
}