#include <bits/stdc++.h>
using namespace std;

int main() {
    int w, h, u1, h1, u2, h2;
    cin >> w >> h >> u1 >> h1 >> u2 >> h2;
    for (int i = h; i >= 0; i--) {
        w += i;
        if (i == h1) {
            w = max(0, w - u1);
        }
        if (i == h2) {
            w = max(0, w - u2);
        }
    }
    cout << w;
}