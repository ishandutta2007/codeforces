#include <algorithm>
#include <iostream>
#include <cassert>
#include <string>
#include <set>

using namespace std;


int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int tc;
    for (cin >> tc; tc --> 0; ) {
        int n;
        string s;
        cin >> n >> s;
        assert(s.size() == n);
        if (s.size() == 1 || s[0] <= s[1]) {
            cout << s[0] << s[0] << endl;
            continue;
        }
        for (int k = 0; k < n; ++k) {
            if (k + 1 == n || s[k] < s[k + 1]) {
                s = s.substr(0, k + 1);
                auto w = s;
                reverse(w.begin(), w.end());
                cout << s << w << endl;
                break;
            }
        }
    }
    return 0;
}