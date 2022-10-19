#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int tab[n];
    int t;
    for (int i = 0; i < n; ++i) {
        cin >> t;
        cin >> tab[i];
    }
    int k;
    cin >> k;
    int p=0;
    while (tab[p]<k) {
        ++p;
    }
    cout << n-p;
}