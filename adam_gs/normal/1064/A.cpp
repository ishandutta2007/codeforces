#include <bits/stdc++.h>

using namespace std;

int main() {
    int tab[3];
    cin >> tab[0] >> tab[1] >> tab[2];
    sort(tab, tab+3);
    cout << max(tab[2]-tab[1]-tab[0]+1, 0);
}