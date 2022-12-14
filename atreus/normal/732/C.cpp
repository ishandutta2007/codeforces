#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    long long a[3];
    cin >> a[0] >> a[1] >> a[2];
    sort (a, a + 3);
    long long sum1 = max(a[2] - a[1] - 1, 0ll);
    long long sum2 = max(a[2] - a[0] - 1, 0ll);
    cout << sum1 + sum2 << endl;
}