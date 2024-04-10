#include <bits/stdc++.h>

using namespace std;

int main() {
    int t = 0;
    int l, r, n, x;
    cin >> n >> x;
    int counter;
    int tmp = 0;
    for (int i = 1; i <= n; i++) {
        cin >> l >> r;
        counter = 0;
        while (1) {
            t = t + x;
            if (t >= l) {
                t = (t - x);
                counter = counter + (r - t);
                t = t + counter;
                break;
            }
        }
        tmp = tmp + counter;
    }
    cout << tmp;
}