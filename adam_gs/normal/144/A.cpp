#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int tab[n];
    for (int i = 0; i < n; ++i) {
        cin >> tab[i];
    }
    int ma=tab[0], l=0;
    for (int i = 1; i < n; ++i){
        if (tab[i]>ma) {
            ma=tab[i];
            l=i;
        }
    }
    int w = l;
    while (l>0) {
        tab[l]=tab[l-1];
        --l;
    }
    tab[0]=ma;
    int mi=tab[0];
    l=0;
    for (int i = 1; i < n; ++i) {
        if (tab[i]<=mi) {
            mi=tab[i];
            l=i;
        }
    }
    cout << w+n-l-1;
}