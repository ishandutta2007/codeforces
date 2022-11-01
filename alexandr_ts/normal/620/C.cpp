#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (ll i = 0; i < n; ++i)
#define frab(i, a, b) for (ll i = a; i < b; ++i)

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 4e5 + 1;
const int INF = 2e9;
const ld EPS = 1e-5;
const int MOD = 1e9 + 7;
const ld PI = acos(-1);

int lft[N], d[N], a[N];
bool fin[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ld start = clock() / CLOCKS_PER_SEC;
    srand(time(NULL));
    //freopen("spacepin.in", "r", stdin);
    int n;
    cin >> n;
    fill(lft, lft + n + 2, -1);
    map <int, int> m;
    fr(i, n)
        cin >> a[i + 1];
    fr(i, n) {
        if (m.count(a[i + 1]))
            lft[i + 1] = m[a[i + 1]];
        m[a[i + 1]] = i + 1;
    }
    //frab(i, 1, n + 1)
      //  cout <<lft[i] << " ";cout << endl;
    vector <pair <int, int> > ans;
    frab(i, 1, 1 + n) {
        if (lft[i] != -1) {
            if (d[i - 1] < d[lft[i] - 1] + 1) {
                d[i] = d[lft[i] - 1] + 1;
            }
            else d[i] = d[i - 1];
        }
        else
            d[i] = d[i - 1];
    }
    int cur = n, curr = n;
    while (cur > 0) {
        if (d[cur] == d[cur - 1])
            cur--;
        else {
            ans.pb(mp(lft[cur], curr));
            cur = lft[cur] - 1;
            curr = cur;
        }
    }
    reverse(ans.begin(), ans.end());
    if (!ans.size()) {
        cout << -1;
        return 0;
    }
    ans[0].first = 1;
    cout << ans.size() << endl;
    fr(i, ans.size()) {
        cout << ans[i].first << " " << ans[i].second << endl;
    }
}