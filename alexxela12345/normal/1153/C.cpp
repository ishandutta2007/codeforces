#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int balance = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '?') {
            cnt++;
        } else if (s[i] == '(') {
            balance++;
        } else {
            balance--;
        }
    }
    int maxx = -1;
    for (int i = 0; i <= cnt; i++) {
        if (i - (cnt - i) == -balance) {
            maxx = i;
        }
    }
    if (maxx == -1) {
        cout << ":(" << endl;
        return 0;
    }
    string ans;
    for (int i = 0; i < n; i++) {
        if (s[i] == '?') {
            if (maxx) {
                ans.push_back('(');
                maxx--;
            } else {
                ans.push_back(')');
            }
        } else {
            ans.push_back(s[i]);
        }
    }
     balance = 0;
    for (int i = 0; i < n; i++) {
        if (ans[i] == '(') {
            balance++;
        } else {
            balance--;
        }
        if (balance <= 0 && i != n - 1) {
            cout << ":(" << endl;
            return 0;
        }
    }
    if (balance != 0) {
        cout << ":(" << endl;
        return 0;
    }
    cout << ans << endl;
        


    return 0;
}