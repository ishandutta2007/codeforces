#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int tab[n];
    int w = 0;
    for (int i = 0; i < n; ++i) {
        cin >> tab[i];
        if (tab[i]<=5-k) ++w;
    }
    cout << w/3;
}