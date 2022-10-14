#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    string t;
    cin >> t;
    string s = t;
    int now = 1;
    for (int i = 1; now < k; i++) {
        if (s.size() - i >= n && s.substr(i, n) == t) {
            now++;
            continue;
        }
        if (s.size() - i >= n) {
            continue;
        }
        if (i == s.size()) {
            s += t;
            now++;
            continue;
        }
        if (s.substr(i, s.size() - i) == t.substr(0, s.size() - i)) {
            s += t.substr(s.size() - i, n - (s.size() - i));
            now++;
        }
    }
    cout << s;
    return 0;
}