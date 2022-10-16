#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    long long sum = 0, maxa = -1;
    for(int i = 0; i < n; i++) {
        long long a;
        cin >> a;
        sum += a;
        maxa = max(maxa, a);
    }
    long long ans = (sum - 1) / (n - 1) + 1;
    cout << max(ans, maxa) << '\n';
}