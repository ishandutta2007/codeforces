#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, t;
    cin >> n >> t;
    char tab[n];
    for (int i = 0 ; i < n; ++i) {
        cin >> tab[i];
    }
    for (int i = 0; i < t; ++i) {
        char t[n];
        for (int j = 0; j < n-1; ++j) {
            if (tab[j]=='B' && tab[j+1]=='G') {
                tab[j]='G';
                tab[j+1]='B';
                ++j;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << tab[i];
    }
}