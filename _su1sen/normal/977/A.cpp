#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    while (k --> 0) {
        if (n % 10) {
            --n;
        } else {
            n /= 10;
        }
    }
    cout << n << '\n';
    return 0;
}