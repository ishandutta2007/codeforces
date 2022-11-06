#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

const int MxN = (int)2e5 + 9;
vector<int> adj[MxN + 9];
int dp[MxN + 9];

void f() {

    int n, m;
    cin >> n >>m ;
    for(int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        assert(x < y);
        adj[x].push_back(y);
    }


    vector<int> res;
    for(int i = 1; i <= n; ++i) {
        assert(adj[i].size() <= 2);

        if(dp[i] <= 1) {
            for (int x : adj[i])
                dp[x] = max(dp[x], dp[i] + 1);
        } else {
            assert(dp[i] == 2);
            res.push_back(i);
        }
    }


    cout << res.size() << '\n';
    for(int x : res)cout << x << ' ' ;
    cout << '\n';

    fill(dp, dp + n + 1, 0);
    for(int i = 0; i <= n; ++i)
        adj[i].clear();
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int t;
    cin >> t;
    while(t--)
        f();

    return 0;
}