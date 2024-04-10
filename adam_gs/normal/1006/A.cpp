#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int tab[n];
    for (int i = 0; i < n; ++i) {
        cin >> tab[i];
        if (tab[i]%2==0) {
            --tab[i];
        }
        cout << tab[i] << " ";
    }
}