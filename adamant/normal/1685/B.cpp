#include <bits/stdc++.h>

using namespace std;

#define int int64_t

const int maxn = 1e5 + 42;

void solve() {
    int a, b, ab, ba;
    cin >> a >> b >> ab >> ba;
    string s;
    cin >> s;
    int n = s.size();
    vector<string> split = {string(1, s[0])};
    for(int i = 1; i < n; i++) {
        if(s[i] == s[i - 1]) {
            split.emplace_back(1, s[i]);
        } else {
            split.back() += s[i];
        }
    }
    int checka = count(begin(s), end(s), 'A');
    int checkb = count(begin(s), end(s), 'B');
    if(checka != a + ab + ba || checkb != b + ab + ba) {
        cout << "NO\n";
        return;
    }
    int free = 0;
    vector<int> evenab, evenba;
    int totalab = 0;
    int totalba = 0;
    for(auto it: split) {
        //cerr << it << "\n";
        if(it.size() % 2 == 1) {
            free += it.size() / 2;
        } else {
            if(it[0] == 'A') {
                totalab += (it.size() - 1) / 2;
                evenab.push_back((it.size() - 1) / 2);
            } else {
                totalba += (it.size() - 1) / 2;
                evenba.push_back((it.size() - 1) / 2);
            }
        }
    }
    sort(begin(evenab), end(evenab));
    sort(begin(evenba), end(evenba));
    
    int sab = 0, sba = 0;
    size_t j = 0;
    for(size_t i = 0; i <= evenab.size(); i++) {
        int tfree = free + (totalab - sab) + (totalba - sba);
        //cout << i << ' ' << j << ' ' << tfree << endl;
        
        int tab = ab - i - sab;
        int tba = ba - j - sba;
        
        while(j < evenba.size() && (tfree < max<int>(0, tba) || tba >= evenba[j] + 1)) {
            sba += evenba[j];
            tfree = free + (totalab - sab) + (totalba - sba);
            j++;
            tba = ba - j - sba;
        }
        //cout << max<int>(0, tba) << ' ' << tfree << endl;
        //cout << i << ' ' << j << ' ' << tfree << endl;
        
        if(tfree >= max<int>(0, tab) + max<int>(0, tba)) {
            cout << "YES\n";
            return;
        }
        
        if(i < evenab.size()) {
            sab += evenab[i];
        }
    }
    
    cout << "NO\n";
    
    
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}