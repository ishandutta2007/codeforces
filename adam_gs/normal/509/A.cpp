#include <bits/stdc++.h>

using namespace std;

int tab[11][11];

int main() {
    int n;
    cin >> n;
    tab[0][1]=1;
    for (int i = 1; i <= n; ++i) {
         for (int j = 1; j <= n; ++j) {
            tab[i][j]=tab[i-1][j]+tab[i][j-1];
         }
    }
    cout << tab[n][n];
}