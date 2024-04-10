#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long gcd(long long x, long long y) {
    return y? gcd(y, x % y) : x;
}

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<long long> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    long long ans = 0, sum = 0;
    for(int i = 0; i < n; i++) {
        ans += a[i] * (2 * i + 1) - 2 * sum;
        sum += a[i];
    }
    long long g = gcd(ans, n);
    cout << ans / g << ' ' << n / g << '\n';
}