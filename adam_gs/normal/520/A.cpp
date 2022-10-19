#include <bits/stdc++.h>

using namespace std;

int tab[26];

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < n; ++i) {
        ++tab[tolower(s[i])-'a'];
    }
    for (int i = 0; i < 26; ++i) {
        if (tab[i]==0) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}