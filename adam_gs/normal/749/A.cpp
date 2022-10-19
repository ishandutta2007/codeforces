#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    cout << n/2 << '\n';
    if (n%2==1) {
        cout << 3 << " ";
        n-=3;
    }
    while (n>0) {
        cout << 2 << " ";
        n-=2;
    }
}