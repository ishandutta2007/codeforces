#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int r=n;
    while (n--) {
        int a;
        cin >> a;
        if (a>k) {
            ++r;
        }
    }
    cout << r;
}