#include <bits/stdc++.h>

using namespace std;

int main() {
    int tab[3], d;
    cin >> tab[0] >> tab[1] >> tab[2] >> d;
    sort(tab, tab+3);
    cout <<  max(d-(tab[2]-tab[1]), 0)+max(d-(tab[1]-tab[0]), 0);
}