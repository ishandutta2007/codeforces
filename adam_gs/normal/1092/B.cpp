#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int tab[n];
    for (int i = 0;i < n; ++i) {
        cin >> tab[i];
    }
    sort(tab, tab+n);
    int r = 0;
    for (int i = 1; i < n; i+=2){
        r+=tab[i]-tab[i-1];
    }
    cout << r;
}