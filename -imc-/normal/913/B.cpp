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

void solve(bool read) {
    int n;
    cin >> n;
    
    vector<int> p(n);
    p[0] = -1;
    vector<int> deg(n), nleafs(n);
    for (int i = 1; i < n; i++) {
        cin >> p[i];
        p[i]--;
        deg[p[i]]++;
    }
    
    for (int i = 0; i < n; i++)
        if (deg[i] == 0)
            nleafs[p[i]]++;
        
    for (int i = 0; i < n; i++)
        if (deg[i] != 0 && nleafs[i] < 3) {
            cout << "No\n";
            return;
        }
        
    cout << "Yes\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int nt = 1;
    //cin >> nt;
    for (int i = 0; i < nt; i++)
        solve(true);
    
    //solve(false);
    
    return 0;
}