#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int tab[n];
    for (int i = 0; i < n; ++i) {
        cin >> tab[i];
    }
    int w = 0, mi=tab[0], ma=tab[0];
    for (int i = 1; i < n; ++i) {
        if (tab[i]<mi || tab[i]>ma) ++w;
        mi=min(mi, tab[i]);
        ma=max(ma, tab[i]);
    }
    cout << w;
}