#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string x;
        cin >> x;
        if (x.size()>10) {
            cout << x[0] << x.size()-2 << x[x.size()-1];
        } else {
            cout << x;
        }
        cout << '\n';
    }
}