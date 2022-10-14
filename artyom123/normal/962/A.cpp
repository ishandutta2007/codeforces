#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;
    vector <int> a(n);
    for ( int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector <int> b(n);
    b[0] = a[0];
    for ( int i = 1; i < n; i++) {
        b[i] = b[i - 1] + a[i];
    }

    for ( int i = 0; i < n; i++) {
        if ( b[i] >= b[n - 1] - b[i]) {
            cout << i + 1;
            return 0;
        }
    }

}