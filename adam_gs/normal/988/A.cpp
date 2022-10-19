#include <bits/stdc++.h>

using namespace std;

int T[100];

int main() {
    int n, k;
    cin >> n >> k;
    int tab[n];
    int r = 0;
    for (int i = 0; i < n; ++i) {
        cin >> tab[i];
        if (T[tab[i]-1]==0) {
            ++r;
        }
        T[tab[i]-1]=1;
    }
    if (r<k) {
        cout << "NO";
    } else {
        cout << "YES\n";
        int i = 0;
        while (k>0) {
            if (T[tab[i]-1]==1) {
                cout << i+1 << " ";
                --k;
            }
            T[tab[i]-1]=0;
            ++i;
        }
    }
}