#include <bits/stdc++.h>
using namespace std;

int main () {
    int n, m;
    cin >> n >> m;
    vector <int> a(n);
    for ( int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector <int> b(m);
    for ( int j = 0; j < m; j++) {
        cin >> b[j];
    }
    vector <int> ans;
    for ( int i = 0; i < n; i++) {
        for ( int j = 0; j < m; j++) {
            if (a[i] == b[j]) {
                ans.push_back(a[i]);
            }
        }
    }
    for ( auto c : ans) {
        cout << c << " ";
    }

    return 0;
}