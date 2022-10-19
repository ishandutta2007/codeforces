#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int tab[n];
    for (int i = 0; i < n; ++i) {
        cin >> tab[i];
    }
    int wyn=0;
    for (int i = 0; i < k; ++i) {
        if (tab[i]==0)break;
        ++wyn;
    }
    for (int i = k; i < n; ++i) {
        if (tab[i]==tab[i-1]&&tab[i]!=0) {
            ++wyn;
        } else {
            break;
        }
    }
    cout << wyn;
}