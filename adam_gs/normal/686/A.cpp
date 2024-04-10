#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n, x;
    cin >> n >> x;
    int r=0;
    while (n--) {
        char q;
        cin >> q;
        int a;
        cin >> a;
        if (q=='+') {
            x+=a;
        } else {
            if (x-a<0) {
                ++r;
            } else {
                x-=a;
            }
        }
    }
    cout << x << " " << r;
}