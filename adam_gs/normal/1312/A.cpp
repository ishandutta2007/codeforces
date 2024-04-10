#include <bits/stdc++.h>

using namespace std;

#define nl cout << '\n'

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >>a >> b;
        if (a%b==0) {
            cout << "YES";
        } else {
            cout << "NO";
        }
        nl;
    }
}