#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define vi vector<int>
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        string s, t;
        cin >> s >> t;
        sort(all(s));
        bool flag = 0;
        for (int i = 0; i <= (int) t.size() - (int) s.size(); i++) {
            string res = "";
            for (int j = 0; j < (int) s.size(); j++) {
                res += t[i + j];
            }
            sort(all(res));
            if (res == s) flag = 1;
        }
        if (flag) cout << "YES" << '\n';
        else cout << "NO\n";
    }
    return 0;
}