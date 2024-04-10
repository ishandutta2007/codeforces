#include <bits/stdc++.h>

using namespace std;

int main() {
    string x;
    cin >> x;
    int a=0;
    for (int i = 0; i < x.size(); ++i) {
        if (x[i]=='a') {
            ++a;
        }
    }
    if (2*a>x.size()) {
        cout << x.size();
    } else {
        cout << 2*a-1;
    }
}