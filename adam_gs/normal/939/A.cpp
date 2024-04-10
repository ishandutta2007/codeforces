#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int tab[n];
    for (int i = 0; i < n; ++i) {
        cin >> tab[i];
    }
    int r =0;
    for (int i = 0; i < n; ++i) {
        if (tab[tab[tab[i]-1]-1]==i+1) {
            ++r;
        }
    }
    if (r>0) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}