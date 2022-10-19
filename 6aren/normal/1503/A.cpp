#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        string s;
        cin >> n >> s;
        vector<int> a;
        vector<int> b;
        for (int i = 0; i < n; i++) {
            char ch = s[i];
            if (ch == '1') {
                a.push_back(i);
            } else b.push_back(i);
        }
        if (a.size() % 2 || b.size() % 2) {
            cout << "NO\n";
            continue;
        }
        string res(n, ' '), res2(n, ' ');
        for (int i = 0; i < a.size() / 2; i++) {
            res[a[i]] = '(';
            res2[a[i]] = '(';
        }
        for (int i = a.size() / 2; i < a.size(); i++) {
            res[a[i]] = ')';
            res2[a[i]] = ')';
        }
        for (int i = 0; i < b.size(); i++) {
            res[b[i]] = (i % 2 ? ')' : '(');
            res2[b[i]] = (i % 2 ? '(' : ')');
        }
        bool ok = 1;
        int cur = 0;
        for (char ch : res2) {
            if (ch == '(') cur++;
            else cur--;
            if (cur < 0) ok = 0;
        }
        if (ok == 0) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            cout << res << '\n';
            cout << res2 << '\n';
        }
    }

    return 0;
}