#include <bits/stdc++.h>

using namespace std;

int main() {
    long long a, b, c;
    cin >> a >> b >> c;
    long long w = 2*c;
    if (a==b) {
        w+=2*a;
    } else {
        w+=2*min(a,b)+1;
    }
    cout << w;
}