#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b, c, n;
        cin >> a >> b >> c >> n;
        int ma=max(a, max(b, c));
        n-=3*ma-a-b-c;
        if (n>=0 && n%3==0) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}