#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int r = 0;
    if (n%5!=0) {
        ++r;
    }
    r+=n/5;
    cout << r;
}