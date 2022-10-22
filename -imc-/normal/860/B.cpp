#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

using li = long long;

string fmt(string s) {
    if (s.length() <= 2) return s;
    
    // at least 3
    // split out 2 or 
    
    string ans = "";
    while (s.length() >= 3) {
        int i = 0;
        while (i < s.length() && s[i] == s[0]) i++;
        i--;
        
        i = max(i, 1);
        i = min(i, (int)s.length() - 1);
        if (!ans.empty()) ans += " ";
        ans += s.substr(0, i + 1);
        s = s.substr(i + 1);
    }
    if (!s.empty()) {
        if (!ans.empty()) ans += " ";
        ans += s;
    }
    
    return ans;
}

void solve(bool read) {
    int n;
    cin >> n;
    
    vector<string> s(n);
    for (int i = 0; i < n; i++)
        cin >> s[i];
    
    unordered_map<string, pair<int, int>> occ;
    occ.max_load_factor(0.5);
    occ.reserve(n * 72);
    
    for (int t = 0; t < 2; t++) {
        for (int i = 0; i < n; i++) {
            for (int len = 1; len <= 9; len++)
                for (int j = 0; j + len - 1 < 9; j++) {
                    string can = s[i].substr(j, len);
                    
                    auto it = occ.find(can);
                    if (t == 0) {
                        if (it == occ.end()) {
                            occ[can] = make_pair(i, i);
                        }
                        else {
                            it->second.first = min(it->second.first, i);
                            it->second.second = max(it->second.second, i);
                        }
                    }
                    else {
                        assert(it != occ.end());
                        if (it->second.first == it->second.second) {
                            cout << it->first << "\n";
                            goto breakAll;
                        }
                    }
                }
                
            breakAll:;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int nt = 1;
    //cin >> nt;
    for (int i = 0; i < nt; i++)
        solve(true);
    
    return 0;
}