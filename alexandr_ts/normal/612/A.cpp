#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (ll i = 0; i < n; ++i)
#define frab(i, a, b) for (ll i = a; i < b; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 2e5 + 1;
const int INF = 2e9;
const ld EPS = 1e-16;

int a[N], pos[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ld start = clock() / CLOCKS_PER_SEC;
    srand(time(NULL));
    //freopen("spacepin.in", "r", stdin);
    //freopen("spacepin.out", "w", stdout);
    int n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    vector <string> ans;
    fr(x, n + 1) {
        if ((n - a * x) >= 0 && (n - a * x) % b == 0) {
            int y = (n - a * x) / b;
            fr(i, x) {
                ans.pb(s.substr(i * a, a));
            }
            fr(i, y) {
                ans.pb(s.substr(x * a + i * b, b));
            }
            cout << ans.size() << endl;
            fr(j, ans.size())
                cout << ans[j] << endl;
            return 0;
        }
    }
    cout << -1;

}