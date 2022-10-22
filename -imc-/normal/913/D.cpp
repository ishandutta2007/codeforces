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
    li T;
    cin >> n >> T;
    
    vector<int> a(n), t(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> t[i];
    }
    
    vector<int> can_set;
    can_set.reserve(n);
    vector<pair<int, int>> cands;
    cands.reserve(n);
    
    auto can = [&](int k) {
        can_set.clear();
        cands.clear();
        
        for (int i = 0; i < n; i++) {
            if (a[i] >= k) {
                cands.emplace_back(t[i], i);
            }
        }
        
        sort(all(cands));
        
        li have = 0;
        for (int i = 0; i < cands.size(); i++)
            if (have + cands[i].first <= T) {
                can_set.push_back(cands[i].second);
                have += cands[i].first;
            }
            
        return can_set.size() >= k;
    };
    
    // low can, high can't
    int low = 0, high = n + 1;
    while (low + 1 != high) {
        int m = (low + high) / 2;
        
        if (can(m)) {
            low = m;
        }
        else {
            high = m;
        }
    }
    
    cout << low << "\n" << low << "\n";
    can(low);
    for (int i = 0; i < low; i++)
        cout << can_set[i] + 1 << " ";
    cout << "\n";
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