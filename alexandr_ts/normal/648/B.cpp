#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 2e5 + 10;
const ll MOD = 1e9 + 7;
const ll INF = 2e9 + 10;
const ld EPS = 1e-9;

int a[N];
vector <int> b[N];
int cur[N];

vector <pair <int, int> > ans;

int main() {
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    //multiset <pair <int, int> > m;
    ll len = 0;
    fr(i, 2 * n) {
        int x;
        cin >> a[i];
        b[a[i]].pb(i);
        len += a[i];
        //m.insert(mp(x, i));
    }
    len /= n;
    //cout << len << endl;
    fr(i, N) {
        int t1 = cur[i];
        frab(j, t1, b[i].size()) {
            if (cur[i] > j)
                continue;
            if (i == len - i)
                //ans.pb(mp(b[i][j], b[len -i][cur[len - i] + 1]));
                ans.pb(mp(i, len - i));
            else
                ans.pb(mp(i, len - i));
                //ans.pb(mp(b[i][j], b[len -i][cur[len - i]]));
            //cout << b[i][j] << " " << b[len - i][cur[len - i]] << endl;
            cur[len - i]++;
            cur[i]++;
        }
    }
    fr(i, ans.size())
        cout << ans[i].first << " " << ans[i].second << endl;


}