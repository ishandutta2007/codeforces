#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int tab[n];
    for (int i = 0; i < n; ++i) {
        cin >> tab[i];
    }
    int p=0;
    int k=n-1;
    int i=0;
    int s=0;
    int d=0;
    while (p<=k) {
        int pom;
        if (tab[p]>tab[k]) {
            pom=tab[p];
            ++p;
        } else {
            pom=tab[k];
            --k;
        }
        if (i%2==0) {
            s+=pom;
        } else {
            d+=pom;
        }
        ++i;
    }
    cout << s << " " << d;
}