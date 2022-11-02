#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)2e5 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
const double pi = acos(-1);
int n, m;
vector< pair<int, string> > g[maxn];
void solve() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        string s;
        int id, cost;
        cin >> s >> id >> cost;
        g[id].emplace_back(make_pair(cost, s));
    }
    for(int i = 1; i <= m; i++) {
        sort(g[i].begin(), g[i].end());
        reverse(g[i].begin(), g[i].end());
        if(g[i].size() < 2) {
            cout << "?" << "\n";
            continue;
        }
        if(g[i].size() > 2 && g[i][1].first == g[i][2].first) {
            cout << "?" << "\n";
            continue;
        }
        cout << g[i][0].second << " " << g[i][1].second << "\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
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