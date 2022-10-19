#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    int l = 1, r = n;
    while (r - l > k) {
        cout << l << " ";
        ++l;
    }
    bool one = true;
    while (l <= r) {
        if (one) {
            cout << l;
            ++l;
        } else {
            cout << r;
            --r;
        }
        cout << " ";
        one = !one;
    }

    cout << "\n";

    return 0;
}