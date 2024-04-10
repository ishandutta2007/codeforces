#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int tab[n];
    for (int i = 0; i < n; ++i) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        tab[i]=a+b+c+d;
    }
    int r = 1;
    for (int i = 1; i < n; ++i) {
        if (tab[i]>tab[0]) {
            ++r;
        }
    }
    cout << r;
}