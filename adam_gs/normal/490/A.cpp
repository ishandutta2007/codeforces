#include <bits/stdc++.h>

using namespace std;

vector <int> s[3];

int main() {
    int n;
    cin >> n;
    int tab[n];
    for (int i = 0; i < n; ++i) {
        cin >> tab[i];
        s[tab[i]-1].push_back(i+1);
    }
    int w = min(s[0].size(), min(s[1].size(), s[2].size()));
    cout << w << '\n';
    for (int i = 0; i < w; ++i) {
        cout << s[0][i] << " " << s[1][i] << " " << s[2][i] << '\n';
    }
}