#include <bits/stdc++.h>

using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    if (a.length() == b.length()) {
        map <int, int> f, s;
        for (int i = 0; i < (int) a.size(); i++) {
            f[a[i]]++;
        }
        for (int i = 0; i < (int) b.size(); i++) {
            s[b[i]]++;
        }
        if (f == s) {
            cout << "array" << endl;
        } else {
            cout << "need tree" << endl;
        }
    } else {
        if (a.length() < b.length()) {
            cout << "need tree" << endl;
        } else {
            map <int, int> f, s;
            for (int i = 0; i < (int) a.size(); i++) {
                f[a[i]]++;
            }
            for (int i = 0; i < (int) b.size(); i++) {
                s[b[i]]++;
            }
            for (int c = 'a'; c <= 'z'; c++) {
                if (f[c] < s[c]) {
                    cout << "need tree" << endl;
                    return 0;
                }
            }
            int j = 0;
            for (int i = 0; i < (int) a.size() && j < (int) b.size(); i++) {
                if (a[i] == b[j])  {
                    j++;
                }
            }
            if (j == (int) b.size()) {
                cout << "automaton" << endl;
            } else {
                cout << "both" << endl;
            }
        }
    }
}