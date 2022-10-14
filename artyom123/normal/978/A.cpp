#include <bits/stdc++.h>

using namespace std;


int main () {
    int n;
    cin >> n;
    vector <int> a(n);
    for ( int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for ( int i = a.size() - 1; i >= 0; i--) {
        i = min(i, (int) a.size() - 1);
        for ( int j = i - 1; j >= 0; j-- ){
            if ( a[j] == a[i]) {
                a.erase(a.begin() + j);
            }
        }
    }

    cout << a.size() << endl;
    for ( auto &c : a) {
        cout << c << " ";
    }







    return 0;
}