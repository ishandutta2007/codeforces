#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn = (int)1e6 + 10;
const int mod = 998244353;
int n, m;
int a[maxn];
int u[maxn];
int p[maxn];
void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        u[i] = 0;
    }
    for(int i = 1; i <= n; i++) {
        int j = i;
        vector<int> p;
        while(u[j] == 0) {
            p.push_back(j);
            u[j] = 1;
            j -= a[j];
        }
        vector<int> ans;
        for(int x=p.size()-1; x >= 0; x--) {
            ans.push_back(p[x]);
            if(p[x] == j) break;
        }
        cout << ans.size() << "\n";
        for(int x: ans) {
            cout << x << " ";
        }
        cout << "\n";
        return;
    }
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin >> t;
    for(int i=1; i <= t; i++) {
        solve();
    }
    return 0;
}