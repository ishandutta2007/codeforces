#include <bits/stdc++.h>
#define fr(i, n) for (ll i = 0; i < n; i++)
#define frab(i, a, b) for (ll i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef pair <long long, long long> pr;
typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;
const ll INF = 2e9;
const ll N = 1e6 + 2;
const ll MAX = 2e5 + 2;
const ld EPS = 1e-8;

int a[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    map <int, vector <int> > m;
    int n;
    cin >> n;
    fr(i, n)
        cin >> a[i];
    fr(i, n)
        m[a[i]].pb(i);
    vector <pr> ans;
    for (auto it = m.begin(); it != m.end(); it++) {
        if (it->second.size() == 1) {
            ans.pb(mp(it->first, 0));
            continue;
        }
        int dx = it->second[1] - it->second[0];
        bool er = false;
        frab(i, 1, it->second.size())
            if (it->second[i] - it->second[i - 1] != dx)
                er = true;
        if (!er)
            ans.pb(mp(it->first, dx));
    }
    cout << ans.size() << endl;
    fr(i, ans.size())
        cout << ans[i].first << " " << ans[i].second << endl;

}