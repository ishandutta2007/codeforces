#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t --> 0) {
        long long n, k;
        cin >> n >> k;
        long long p = k / (n - 1);
        long long r = k % (n - 1);
        long long ans = n * p + r - (r == 0);
        cout << ans << '\n';
    }
    return 0;
}