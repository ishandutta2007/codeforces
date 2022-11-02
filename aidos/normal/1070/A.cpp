#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn = (int)2e5 + 10;
const int mod = (int)1e9 + 7;
int n, m;
int u[505][5050];
int p[505][5050];
int d[505][5050];
void solve() {
    cin >> n >> m;
    u[0][0] = 1;
    queue< pair<int, int> > q;
    q.push({0, 0});
    while(q.size() > 0) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i < 10; i++) {
            int e = (x * 10 + i) % n;
            int f = y + i;
            if(f <= m && u[e][f] == 0) {
                u[e][f] = 1;
                p[e][f] = x;
                d[e][f] = i;
                q.push({e,f});
            }
        }
    }
    if(u[0][m] == 0) {
        cout << -1 << "\n";
    } else {
        int x = 0;
        int y = m;
        vector<int> ans;
        while(y > 0) {
            int c = d[x][y];
            ans.push_back(c);
            x = p[x][y];
            y -= c;
        }
        reverse(ans.begin(), ans.end());
        for(auto t: ans) cout<<t;
        cout<<"\n";
    }
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //srand(0);
    int t=1;
    //cin >> t;
    for(int i=1; i <= t; i++) {
        //cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}