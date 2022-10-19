#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int tab[n];
    tab[0]=0;
    for (int i = 1; i < n; ++i) {
        cin >> tab[i];
        tab[i]+=tab[i-1];
    }
    int a, b;
    cin >> a >> b;
    cout << tab[b-1]-tab[a-1];
}