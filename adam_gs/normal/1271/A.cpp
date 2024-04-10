#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, c, d, e, f, w=0;
    cin >> a >> b >> c >> d >> e >> f;
    if (e>f) {
        w+=min(a, d)*e;
        d-=min(a, d);
        w+=min(b, min(c, d))*f;
    } else {
        w+=min(b, min(c, d))*f;
        d-=min(b, min(c, d));
        w+=min(a, d)*e;
    }
    cout << w;
}