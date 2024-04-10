#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m;
        cin >> n >> m;
        if (n==1 || m==1) {
            cout << "YES";
        } else if (n<3 && m<3) {
            cout << "YES";
        } else {
            cout << "NO";
        }
        cout << '\n';
    }
}