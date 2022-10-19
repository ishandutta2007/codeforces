#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int r = 2*n;
    int g = 5*n;
    int b = 8*n;
    r=(r+k-1)/k;
    g=(g+k-1)/k;
    b=(b+k-1)/k;
    cout << r+g+b;
}