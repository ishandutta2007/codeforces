#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int r = 0;
    if (a==b || a==c || a==d) {
        ++r;
    }
    if (b==c || b==d) {
        ++r;
    }
    if (c==d) {
        ++r;
    }
    cout << r;
}