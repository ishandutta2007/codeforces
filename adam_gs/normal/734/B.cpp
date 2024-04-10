#include <bits/stdc++.h>

using namespace std;

int main() {
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    long long r=min(a, min(c,d));
    a-=r;
    c-=r;
    d-=r;
    r*=256;
    r+=32*min(a, b);
    cout << r;
}