#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int r=1;
    string tab[n];
    for (int i = 0; i < n; ++i) {
        cin >> tab[i];
    }
    for (int i = 1; i < n; ++i) {
        if (tab[i][0]=='0' && tab[i-1][0]=='1') {
            ++r;
        }
        if (tab[i][0]=='1' && tab[i-1][0]=='0') {
            ++r;
        }
    }
    cout << r;
}