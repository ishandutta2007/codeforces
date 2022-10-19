#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int tab[n];
        for (int i = 0; i< n; ++i) {
            cin >> tab[i];
        }
        sort(tab, tab+n);
        int r = 1;
        for (int i = 1; i < n; ++i) {
            if (tab[i]!=tab[i-1]) {
                ++r;
            }
        }
        cout << r << '\n';
    }
}