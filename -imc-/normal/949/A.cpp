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

void solve(bool __attribute__((unused)) read) {
    set<int> pos[2];
    string s;
    cin >> s;
    
    int n = s.length();
    for (int i = 0; i < n; ++i)
        pos[s[i] - '0'].insert(i);
    
    vector<vector<int>> ans;
    while (true) {
        int curPos = 0;
        int cur = 0;
        
        vector<int> subseq;
        
        while (true) {
            auto it = pos[cur].lower_bound(curPos);
            if (it != pos[cur].end()) {
                curPos = *it;
                pos[cur].erase(it);
                subseq.push_back(curPos + 1);
                cur = 1 - cur;
            }
            else {
                break;
            }
        }
        
        if (subseq.empty() && pos[0].empty() && pos[1].empty()) {
            cout << ans.size() << "\n";
            for (auto it: ans) {
                cout << it.size() << " ";
                for (int x: it)
                    cout << x << " ";
                cout << "\n";
            }
            return;
        }
        else if (subseq.size() % 2 == 1) {
            ans.push_back(subseq);
        }
        else {
            cout << "-1\n";
            return;
        }
    }
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