#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        long long tab[3];
        cin >> tab[0] >> tab[1] >> tab[2];
        sort(tab, tab+3);
        tab[2]-=tab[1]-tab[0];
        tab[1]+=tab[2]/2;
        cout << tab[1] << '\n';
    }
}