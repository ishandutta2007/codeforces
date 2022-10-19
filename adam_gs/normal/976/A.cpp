#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int l = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i]=='0') {
            ++l;
        }
    }
    if (s[0]!='0')
    cout << 1;
    for (int i = 0; i < l; ++i) {
        cout << 0;
    }
}