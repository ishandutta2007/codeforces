#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    a-=b;
    if (a==0) {
        if (c==0) {
            cout << 0;
        } else {
            cout << "?";
        }
    }
    if (a<0) {
        if (c>=abs(a)) {
            cout << "?";
        } else {
            cout << "-";
        }
    }
    if (a>0) {
        if (c>=a) {
            cout << "?";
        } else {
            cout << "+";
        }
    }
}