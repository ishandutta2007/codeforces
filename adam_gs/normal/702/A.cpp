#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int tab[n];
    for (int i = 0; i < n; ++i) {
        cin >> tab[i];
    }
    int m=1, l=1;
    for (int i = 1; i < n; ++i) {
        if (tab[i]>tab[i-1]) {++l;}else{l=1;}
        m=max(m, l);
    }
    cout << m;
}