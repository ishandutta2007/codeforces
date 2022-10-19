#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string x;
        cin >> x;
        bool t = false;
        for (int i = 0; i < n; ++i) {
            if (x[i]=='8' && n-i>10) {
                t=true;
            }
        }
        if (t==true) {
            cout << "YES";
        } else {
            cout << "NO";
        }
        cout << '\n';
    }
}