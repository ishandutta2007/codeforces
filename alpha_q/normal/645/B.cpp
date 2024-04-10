#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n, k; cin >> n >> k;
    k = min(k, n/2);
    cout << k * (n + n - k - k - 1) << endl;
    return 0;
}