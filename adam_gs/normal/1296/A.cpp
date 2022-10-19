#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a;
        cin >> a;
        int sum=a;
        bool t = false;
        while (--n) {
            int b;
            cin >> b;
            if (b%2!=a%2) {
                t=true;
            }
            sum+=b;
        }
        if (sum%2==1 || t==true) {
            cout << "YES";
        } else {
            cout << "NO";
        }
        cout << '\n';
    }
}