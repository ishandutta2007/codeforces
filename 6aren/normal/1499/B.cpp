#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt;
    cin >> tt;

    while (tt--) {
        string s;
        cin >> s;
        int n = s.size();
        bool ok = false;
        for (int i = -1; i < n; i++) {
            vector<int> a;
            for (int j = 0; j <= i; j++) {
                if (s[j] == '1') a.push_back(j);
            }
            for (int j = i + 1; j < n; j++) {
                if (s[j] == '0') a.push_back(j);
            }
            bool check = true;
            for (int j = 1; j < a.size(); j++) {
                if (a[j] - a[j - 1] == 1) check = false;
            }
            ok |= check;
        }
        cout << (ok ? "YES\n" : "NO\n");
    }   

    return 0;
}