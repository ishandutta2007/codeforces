#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int tab[n];
    for (int i = 0; i < n; ++i) {
        cin >> tab[i];
    }
    vector <int>T;
    for (int i = 1; i < n; ++i) {
        if (tab[i]==1) {
            T.push_back(tab[i-1]);
        }
    }
    T.push_back(tab[n-1]);
    cout << T.size() << '\n';
    for (int i = 0; i < T.size(); ++i) {
        cout << T[i] << " ";
    }
}