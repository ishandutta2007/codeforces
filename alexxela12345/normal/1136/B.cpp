#include <bits/stdc++.h>
#define _ << " " <<

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    long long ans = min(k - 1, n - k);
    ans += 3 * n;
    cout << ans << endl;
    return 0;
}