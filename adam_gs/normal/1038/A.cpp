#include <bits/stdc++.h>

using namespace std;

int tab[26];

int main() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    for (int i = 0; i < n; ++i) {
        ++tab[s[i]-'A'];
    }
    int m = tab[0];
    for (int i = 1; i < k; ++i) {
        m = min(m, tab[i]);
    }
    cout << m*k;
}