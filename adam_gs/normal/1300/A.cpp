#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int tab[n];
        int r = 0;
        int s = 0;
        for (int i = 0; i < n; ++i) {
            cin >> tab[i];
            if (tab[i]==0) {
                ++tab[i];
                ++r;
            }
            s+=tab[i];
        }
        if (s==0) {
            ++r;
        }
        cout << r << '\n';
    }
}