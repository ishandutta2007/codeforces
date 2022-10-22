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
    string s;
    cin >> s;
    
    int n = s.length();
    
    vector<vector<int>> pos(26);
    
    for (int i = 0; i < n; ++i) {
        pos[s[i] - 'a'].push_back(i);
    }
    
    ld answer = 0;
    
    vector<int> cnt(26);
    for (int c = 0; c < 26; ++c) {
        int maxUnique = 0;
        for (int delta = 1; delta < n; ++delta) {
            cnt.assign(26, 0);
            int nUnique = 0;
            for (int i: pos[c]) {
                int& to = cnt[s[(i + delta) % n] - 'a'];
                ++to;
                if (to == 1) ++nUnique;
                if (to == 2) --nUnique;
            }
            //assert(nUnique >= 0);
            
            //if (c == 0)
            //    cout << "symbol " << (char)('a' + (char)c) << " delta " << delta << " -> " << nUnique << endl;
            
            maxUnique = max(maxUnique, nUnique);
        }
        
        //maxUnique / pos[c].size();
        answer += maxUnique;
    }
    
    answer /= n;
    cout << fixed << setprecision(12) << answer << endl;
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