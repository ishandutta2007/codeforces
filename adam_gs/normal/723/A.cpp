#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    cout << abs(min(a,min(b,c))-max(a, max(b,c)));
}