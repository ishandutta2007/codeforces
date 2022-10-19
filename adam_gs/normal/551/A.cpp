#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int tab[n];
    for (int i = 0; i < n; ++i) {
        cin >> tab[i];
    }
    for (int i = 0; i < n; ++i) {
        int w=1;
        for (int j = 0; j < n; ++j) {
            if (tab[j]>tab[i])++w;
        }
        cout << w << " ";
    }
}