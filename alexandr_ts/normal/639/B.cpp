#include <bits/stdc++.h>
#define fr(i, n) for (ll i = 0; i < n; ++i)
#define frab(i, a, b) for (ll i = a; i < b; ++i)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const ll N = 2e5 + 10;
const ll M = 1e6 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 2e9 + 10;
const ld EPS = 1e-9;

int a[N];

vector <pair <int, int> > ans;

int main() {
    //freopen("a.in", "r", stdin);
    //srand(time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, d, h;
    cin >> n >> d  >> h;
    if (d > 2 * h || d < h || n - 1 < d || n - 1 < h) {
        cout << -1;
        return 0;
    }
    if (d == 1) {
        if (n == 2) {
            cout << "1 2" << endl;
        }
        else
            cout << -1;
        return 0;
    }
    fr(i, h)
        ans.pb(mp(i + 1, i + 2));
        //cout << i + 1 << " " << i + 2 << endl;
    if (d > h)
        ans.pb(mp(1, h + 2));
        //cout << 1 << " " << h + 2 << endl;
    frab(i, h + 2, d + 1)
        ans.pb(mp(i, i + 1));
    frab(i, d + 2, n + 1)
        ans.pb(mp(1 + (d == h), i));
    if (ans.size() != n - 1) {
        cout << -1;
        return 0;
    }
    fr(i, ans.size())
        if (ans[i].first > n || ans[i].second > n) {
            cout << -1;
            return 0;
        }
    fr(i, ans.size())
        cout << ans[i].first << " " << ans[i].second << endl;


}