#include <bits/stdc++.h>

using namespace std;

int main() {
    int tab[4];
    cin >> tab[0] >> tab[1] >> tab[2] >> tab[3];
    string x;
    cin >> x;
    int r = 0;
    for (int i = 0; i < x.size(); ++i) {
        r+=tab[x[i]-'1'];
    }
    cout << r;
}