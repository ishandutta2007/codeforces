#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int tab[n];
    int one=0;
    int zero=0;
    for (int i = 0; i < n; ++i) {
        cin >> tab[i];
        if (tab[i]==0) {
            ++zero;
        } else {
            ++one;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (tab[i]==0) {
            --zero;
            if (zero==0) {
                cout << i+1;
                break;
            }
        }
        if (tab[i]==1) {
            --one;
            if (one==0) {
                cout << i+1;
                break;
            }
        }
    }
}