#include <bits/stdc++.h>

using namespace std;

#define nl cout << '\n'

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long x;
        cin >> x;
        int m=0;
        while (x%5==0) {
            x/=5;
            x*=4;
            ++m;
        }
        while (x%3==0) {
            x/=3;
            x*=2;
            ++m;
        }
        while (x%2==0) {
            x/=2;
            ++m;
        }
        if (x==1) {
            cout << m;
        } else {
            cout << -1;
        }
        nl;
    }
}