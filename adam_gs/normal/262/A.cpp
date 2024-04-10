#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int w = 0;
    while (n--) {
        string s;
        cin >> s;
        int l = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i]=='7' || s[i]=='4') {
                ++l;
            }
        }
        if (l<=k) {
            ++w;
        }
    }
    cout << w;
}