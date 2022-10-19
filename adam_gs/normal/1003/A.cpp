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
    int r=1;
    int m=1;
    for (int i = 1; i < n; ++i) {
        if (tab[i]==tab[i-1]) {
            ++r;
            m=max(m, r);
        } else {
            r=1;
        }
    }
    cout << m;
}