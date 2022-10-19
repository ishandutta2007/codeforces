#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, c;
    cin >> n >> c;
    int tab[n];
    cin >> tab[0];
    int l = 1;
    for (int i = 1; i < n; ++i) {
        cin >> tab[i];
        if (tab[i]-tab[i-1]>c) {
            l=1;
        } else {
            ++l;
        }
    }
    cout << l;
}