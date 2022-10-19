#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    if (n%3==0) {
        cout << 6 << " " << n-6;
    } else if (n%3==1) {
        cout << 4 << " " << n-4;
    } else {
        cout << 8 << " " << n-8;
    }
}