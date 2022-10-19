#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    char tab[n][m];
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j) {
            cin >> tab[i][j];
        }
    }
    int w=0;
    for (int i = 0; i < n; ++i) {
        bool t = true;
        for (int j = 0; j < m; ++j) {
            if (tab[i][j]=='S') t=false;
        }
        if (t==true) {
            for (int j = 0; j < m; ++j) {
                if (tab[i][j]=='.') {
                    tab[i][j]='x';
                    ++w;
                }
            }
        }
    }
    for (int j = 0; j < m; ++j) {
        bool t = true;
        for (int i = 0; i < n; ++i) {
            if (tab[i][j]=='S') t=false;
        }
        if (t==true) {
            for (int i = 0; i < n; ++i) {
                if (tab[i][j]=='.') {
                    tab[i][j]='x';
                    ++w;
                }
            }
        }
    }
    cout << w;
}