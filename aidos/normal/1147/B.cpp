#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long long ull;
const int maxn = (int)5e5 + 100;
const ll inf = (1ll<<60);
const int mod2 = (int)998244353;
const int mod = (int)1e9 + 7;
string s;
int n;
pair<int, int> a[maxn];
pair<int, int> b[maxn];
int m;
int cnt[maxn];
vector<int> g[maxn];
vector<int> gr[maxn];
void solve(){
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> a[i].first >> a[i].second;
        a[i].first--;
        a[i].second--;
    }
    sort(a, a + m);
    for(int i = 0; i < m; i++) {
        g[a[i].first].push_back(a[i].second);
        g[a[i].second].push_back(a[i].first);
    }
    for(int i = 0; i < n; i++) sort(g[i].begin(), g[i].end());
    for(int i = 1; i < n; i++) {
        if(n % i == 0) {
            for(int j = 0; j < n; j++) {
                gr[j].clear();
            }
            for(int j = 0; j < m; j++) {
                b[j].first = (a[j].first + i) % n;
                b[j].second = (a[j].second + i) % n;
                gr[b[j].first].push_back(b[j].second);
                gr[b[j].second].push_back(b[j].first);
            }
            int ok = 1;
            for(int j = 0; ok && j < n; j++) {
                if(gr[j].size() != g[j].size()) {
                    ok = 0;
                } else {
                    stable_sort(gr[j].begin(), gr[j].end());
                    ok &= gr[j] == g[j];
                }
            }
            if(ok) {
                cout << "Yes\n";
                return;
            }
        }
    }
    cout << "No\n";
}
int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    int t = 1;
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}