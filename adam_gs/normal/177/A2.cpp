#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int tab[n][n];
    int r = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> tab[i][j];
            if (i==j || i+j==n-1 || i==n/2 || j==n/2) {
                r+=tab[i][j];
            }
        }
    }
    cout << r;
}