#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int tab[n];
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        tab[a-1]=i+1;
    }
    for (int i = 0; i < n; ++i) {
        cout << tab[i] << " ";
    }
}