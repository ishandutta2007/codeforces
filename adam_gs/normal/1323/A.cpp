#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int tab[n];
        for (int i = 0; i < n; ++i) {
            cin >> tab[i];
        }
        bool t = true;
        for (int i = 0; i < n; ++i) {
            if (tab[i]%2==0) {
                cout << 1 << '\n' << i+1 << '\n';
                t=false;
                break;
            }
        }
        if (t==true) {
            if (n>1) {
                cout << 2 << '\n' << 1 << " " << 2 << '\n';
            } else {
                cout << -1 << '\n';
            }
        }
    }
}