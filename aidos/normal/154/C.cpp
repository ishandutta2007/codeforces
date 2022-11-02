#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)1e6 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
int n, m;
vector<int> g[maxn];
map< pair<ll, ll>, int> M[maxn];
pair<ll, ll> Hash(vector<int> &d) {
    ll val = 0;
    for(int i = 0; i < d.size(); i++) {
        val = val * 2011 + d[i];
    }
    ll val2 = 0;
    ll pr = (int)1e6 + 7;
    for(int i = 0; i < d.size(); i++) {
        val2 = (val2 * pr + d[i]) % mod;
    }
    return make_pair(val, val2);
}
void solve(){
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].emplace_back(y);
        g[y].emplace_back(x);
    }
    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        sort(g[i].begin(), g[i].end());
        pair<ll, ll> d = Hash(g[i]);
        ans += M[g[i].size()][d];
        M[g[i].size()][d]++;
    }
    for(int i = 0; i <= n; i++) M[i].clear();

    for(int i = 1; i <= n; i++) {
        g[i].emplace_back(i);
        sort(g[i].begin(), g[i].end());
        pair<ll, ll> d = Hash(g[i]);
        ans += M[g[i].size()][d];
        M[g[i].size()][d]++;
    }

    cout << ans << "\n";
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //srand(time(0));
    int t = 1;
    //scanf("%d", &t);
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}