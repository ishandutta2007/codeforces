#include <bits/stdc++.h>

using namespace std;

int tab[110];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        while (a<=b) {
            tab[a]=1;
            ++a;
        }
    }
    int r = 0;
    for (int i = 0; i < m; ++i) {
        if (tab[i+1]==0) {
            ++r;
        }
    }
    cout << r << '\n';
    for (int i = 0; i < m; ++i) {
        if (tab[i+1]==0) {
            cout << i+1 << " ";
        }
    }
}