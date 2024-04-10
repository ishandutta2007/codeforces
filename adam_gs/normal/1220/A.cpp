#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    string x;
    cin >> x;
    int one=0;
    int zero=0;
    for (int i = 0; i < n; ++i) {
        if (x[i]=='n') {
            ++one;
        }
        if (x[i]=='z') {
            ++zero;
        }
    }
    while (one--) {
        cout << 1 << " ";
    }
    while (zero--) {
        cout << 0 << " ";
    }
}