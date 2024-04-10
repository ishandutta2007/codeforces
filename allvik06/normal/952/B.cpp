#include <bits/stdc++.h>

using namespace std;

signed main() {
    vector <string> a = {"great", "don't think so", "don't touch me", "cool", "not bad"};
    for (int i = 0; i < 10; ++i) {
        cout << i << endl;
        string s;
        getline(cin, s);
        if (s == "no") {
            continue;
        }
        for (string j : a) {
            if (j == s) {
                cout << "normal" << endl;
                return 0;
            }
        }
        cout << "grumpy" << endl;
        return 0;
    }
    return 0;
}