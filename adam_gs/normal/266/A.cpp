#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    string x;
    cin >> x;
    int r = 0;
    for (int i = 1; i < n; ++i) {
        if (x[i]==x[i-1]) {
            ++r;
        }
    }
    cout << r;
}