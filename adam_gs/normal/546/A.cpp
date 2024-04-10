#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    c*=(c+1);
    c/=2;
    c*=a;
    cout << max(c-b, 0);
}