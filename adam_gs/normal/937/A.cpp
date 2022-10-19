#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int tab[n];
    for (int i = 0; i < n; ++i) {
        cin >> tab[i];
    }
    sort(tab, tab+n);
    int w=0;
    int p=0;
    for (int i = 0; i < n; ++i) {
        if (tab[i]!=p) {
            ++w;
            p=tab[i];
        }
    }
    cout << w;
}