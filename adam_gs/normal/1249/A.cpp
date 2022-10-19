#include <bits/stdc++.h>

using namespace std;

int main() {
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        int tab[n];
        for (int i = 0 ; i < n; ++i) {
            cin >> tab[i];
        }
        sort(tab, tab+n);
        bool t = true;
        for (int i = 0; i < n-1; ++i) {
            if (tab[i]+1==tab[i+1]) t=false;
        }
        if (t==true) {
            cout << 1;
        } else {
            cout << 2;
        }
        cout << '\n';
    }
}