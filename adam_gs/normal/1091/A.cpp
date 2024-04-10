#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    b-=1;
    c-=2;
    cout << min(a, min(b, c))*3+3;
}