#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    string x;
    cin >> x;
    int r = 0;
    for (int i = 2; i < n; ++i) {
        if (x[i]=='x' && x[i-1]=='x' && x[i-2]=='x') {
            ++r;
        }
    }
    cout << r;
}