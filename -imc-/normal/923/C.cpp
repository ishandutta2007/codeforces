#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

using li = long long;
using ld = long double;

const int MOD = 1e9 + 7;

void solve(bool __attribute__((unused)) read) {
    int n;
    cin >> n;
    
    vector<int> a(n), p(n);
    
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    
    for (int i = 0; i < n; ++i)
        cin >> p[i];
    
    multiset<int> ps(p.begin(), p.end());
    
    vector<int> ans;
    for (int x: a) {
        int x_orig = x;
        for (int bit = 30; bit >= 0; --bit) {
            // do we have 
            int x_trunk = x & ~((1 << bit) - 1);
            auto it = ps.lower_bound(x_trunk);
            if (it != ps.end() && (*it ^ x) < (1 << bit)) {
                // can make it
                continue;
            }
            x ^= 1 << bit;
        }
        
        //cout << "lb " << x << endl;
        auto it = ps.lower_bound(x);
        assert(it != ps.end());
        ans.push_back(x_orig ^ *it);
        //cout << "found " << (x_orig ^ *it) << "\n";
        ps.erase(it);
        /*
        vector<int> cands;
        if (it != ps.end()) {
            cands.push_back(*it ^ x);
        }
        
        if (it != ps.begin()) {
            it = prev(it);
            cands.push_back(*it ^ x);
        }
        
        assert(!cands.empty());
        
        int z = *min_element(all(cands));
        ans.push_back(z);
        
        ps.erase(ps.find(z ^ x));*/
    }
    
    for (int x: ans)
        cout << x << " ";
    cout << "\n";
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