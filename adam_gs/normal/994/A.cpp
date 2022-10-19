#include <bits/stdc++.h>

using namespace std;

int fing[10];

int main() {
    int n, m;
    cin >> n >> m;
    int tab[n];
    for (int i = 0; i < n; ++i) {
        cin >> tab[i];
    }
    for (int i = 0; i < m; ++i) {
        int a;
        cin >> a;
        fing[a-1]=1;
    }
    for (int i = 0; i < n; ++i) {
        if (fing[tab[i]-1]==1) {
            cout << tab[i] << " ";
        }
    }
}