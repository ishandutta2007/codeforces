#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    string x;
    cin >> x;
    int l=0;
    int r=0;
    for (int i = 0; i < n; ++i) {
        if (x[i]=='L') {
            ++l;
        } else {
            ++r;
        }
    }
    cout << r+l+1;
}