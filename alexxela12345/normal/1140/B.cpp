#include <bits/stdc++.h>
#define _ << " " <<

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        if (s[0] == '>') {
            cout << 0 << endl;
        } else if (s.back() == '<') {
            cout << 0 << endl;
        } else {
            int ans1 = 0;
            while (s[ans1] == '<') {
                ans1++;
            }
            int ans2 = 0;
            while (s[s.size() - 1 - ans2] == '>') {
                ans2++;
            }
            cout << min(ans1, ans2) << endl;
        }
    }

    return 0;
}