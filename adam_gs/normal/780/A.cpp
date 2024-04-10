#include <bits/stdc++.h>

using namespace std;

int tab[100007];

int main() {
    ios_base::sync_with_stdio(0);
    int n, l=0, m=0;
    cin >> n;
    for (int i = 0; i <2*n; ++i) {
        int a;
        cin >> a;
        ++tab[a];
        if (tab[a]==2) {
            --l;
        } else {
            ++l;
        }
        m=max(m, l);
    }
    cout << m;
}