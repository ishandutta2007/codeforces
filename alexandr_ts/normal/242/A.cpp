#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef pair <long long, long long> pr;
typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;
const ll INF = 2e9;
const ll N = 5e3 + 2;
const ld EPS = 1e-8;

ll d[N][N], a[N];
ll pref[N];

ll sum(ll l, ll r) {
    return pref[r] - pref[l - 1];
    //return accumulate(a + l, a + r + 1, 0ll);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    int x, a, b, y;
    cin >> x >> y >> a >> b;
    vector <pr> ans;
    frab(i, a, x + 1)
        frab(j, b, y + 1)
            if (i > j)
                ans.pb(mp(i,j));
    cout << ans.size() << endl;
    fr(i, ans.size())
        cout << ans[i].first << " " << ans[i].second << endl;
}