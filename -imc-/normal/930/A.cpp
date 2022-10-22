#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

using li = long long;
using ld = long double;

const int MOD = 1e9 + 7;

int modpow(int x, int p) {
    int ans = 1;
    while (p) {
        if (p % 2)
            ans = ans * (li)x % MOD;
        p /= 2;
        x = x * (li)x % MOD;
    }
    return ans;
}

    
vector<vector<int>> e;
vector<int> level;

void dfs(int v, int l = 0) {
    level[v] = l;
    for (int u: e[v])
        dfs(u, l + 1);
}

void solve(bool __attribute__((unused)) read) {
    int n;
    cin >> n;
    
    e.resize(n);
    level.resize(n);
    
    for (int i = 0; i + 1 < n; ++i) {
        int p;
        cin >> p;
        --p;
        
        e[p].push_back(i + 1);
    }
    
    dfs(0);
    
    vector<int> sum(n);
    for (int i = 0; i < n; ++i)
        ++sum[level[i]];
    
    int answer = 0;
    
    for (int i = 0; i < n; ++i)
        answer += sum[i] % 2;
    
    cout << answer << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int nt = 1;
    //cin >> nt;
    for (int i = 0; i < nt; i++)
        solve(true);
    
    //while (true) solve(false);
    
    return 0;
}