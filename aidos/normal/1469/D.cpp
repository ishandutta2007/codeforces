#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = (int)2e5 + 100;
int n, m;
int u[maxn];
void rec(int n) {
    if(n <= 3) return;
    int x = sqrt(n);
    while(x * x < n) x++;
    u[n] = 1;
    rec(x);
}
void solve() {
    cin >> n;
    for(int i = 2; i <= n; i++) {
        u[i] = (i <= 3);
    }
    rec(n);
    vector<int> cur;
    vector < pair<int, int> > ans;
    for(int i = 2; i <= n; i++) {
        if(!u[i]) {
            ans.push_back({i, n});
        } else {
            cur.push_back(i);
        }
    }
    for(int i = cur.size()-1; i >= 1; i--) {
        int x = cur[i];
        int y = cur[i-1];
        ans.push_back(make_pair(x, y));
        int d = (x+y-1)/y;
        ans.push_back(make_pair(x, y));
    }
    cout << ans.size() << "\n";
    for(auto x: ans) {
        cout << x.first << " "<<x.second << "\n";
    }
}
int main() {
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}