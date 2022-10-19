#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    if (d>=a) {
        d-=a;
        a+=b;
        d+=e;
        if (d>=b) {
            d-=b;
            d+=f;
            if (d>=c) {
                cout << "YES";
            } else {
                cout << "NO";
            }
        }else {
            cout << "NO";
        }
    } else {
        cout << "NO";
    }
}