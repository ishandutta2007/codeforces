#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn = (int)2e5 + 10;
int n;
string s, t;
vector<int> g[2];
void solve() {
    cin >> n;
    for(int i = 0; i < 2; i++) g[i].clear();
    for(int i = 0; i < 2*n;i++) {
        int x;
        cin >> x;
        g[x%2].emplace_back(i+1);
    }
    vector<int> ans;
    for(int i = 0; i < 2; i++) {
        if(g[i].size() % 2 == 1) g[i].pop_back();
        for(int x: g[i]) ans.emplace_back(x);
    }
    while(ans.size() > 2 * n - 2) ans.pop_back();
    for(int i = 0; i < ans.size(); i+=2) cout << ans[i] << " " << ans[i + 1] << "\n";

}
int main() {
    int t=1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
}