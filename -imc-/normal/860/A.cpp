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
    string s;
    cin >> s;
    
    int n = s.length();
    
    set<char> v({'a', 'e', 'i', 'o', 'u'});
    
    string ans = "";
    string cur = "";
    for (char c: s) {
        if (v.count(c)) {
            ans += fmt(cur);
            ans += c;
            cur = "";
            continue;
        }
        cur += c;
    }
    ans += fmt(cur);
    
    cout << ans << "\n";
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