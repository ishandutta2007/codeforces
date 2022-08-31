#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.length();
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            string f = "";
            for (int z = 0; z < n; z++) {
                if (z < i || z > j)
                    f += s[z];
            }
            if (f == "CODEFORCES") {
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
}