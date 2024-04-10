#include <bits/stdc++.h>

using namespace std;


int main () {
    int n, m;
    cin >> n >> m;
    vector <long long> a(n);
    for ( int i = 0; i < n; i++){
        cin >> a[i];
    }

    vector <long long> b(m);
    for ( int i = 0; i < m; i++) {
        cin >> b[i];
    }

    long long sum = 0;
    int j = 0;
    for ( int i = 0; i < n; i++) {
        sum += a[i];
        for ( ; j < m && b[j] <= sum; j++) {

            cout << i + 1 << " " << b[j] - (sum - a[i]) << "\n";
        }

        if ( j == m) {
            break;
        }
    }







    return 0;
}