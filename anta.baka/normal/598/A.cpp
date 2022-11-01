#include <bits/stdc++.h>

using namespace std;

int main() {
    int _;
    cin >> _;
    while(_--) {
        long long n;
        cin >> n;
        long long p2 = 1;
        while(p2 * 2 <= n)
            p2 *= 2;
        cout << n*(n+1)/2 - 2*(2*p2-1) << "\n";
    }
}