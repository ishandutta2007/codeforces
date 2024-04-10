#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        int a, b1, c1, b2, c2;
        cin >> a >> b1 >> c1 >> b2 >> c2;
        int r = 0;
        a/=2;
        if (b2>c2) {
            r+=min(a, b1)*b2;
            a-=min(a, b1);
            r+=min(a, c1)*c2;
        } else {
            r+=min(a, c1)*c2;
            a-=min(a, c1);
            r+=min(a, b1)*b2;
        }
        cout << r << '\n';
    }
}