#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    string t;
    cin >> s;
    cin >> t;
    string s2 = s;
    string t2 = t;
    sort(s2.begin(), s2.end());
    sort(t2.begin(), t2.end());
    if (s2 != t2) {
        cout << -1 << endl;
        return 0;
    }
    vector<int> m(2);
    for (int i = 0; i < n; i++) {
        if (s[i] == t[i]) {
            continue;
        }
        int x = s[i] - '0';
        if (m[1 - x] != 0) {
            m[1 - x]--;
            m[x]++;
        } else {
            m[x]++;
        }
    }
    cout << m[0] + m[1] << endl;
}