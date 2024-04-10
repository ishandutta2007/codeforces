#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    if (n==1) {
        cout << 1;
    } else {
        long long s=1;
        for (int i = 2; i <= n; ++i) {
            s+=4*i-4;
        }
        cout << s;
    }
}