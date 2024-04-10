#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(), x.end()

const int INF = 1e9;

long long gcd(long long a, long long b) {
    if (a < b) {
        swap(a, b);
    }
    while (b != 0) {
        long long c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int main() {
    int n;
    cin >> n;
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i;
    }
    for (int i = 2; i <= n; i++) {
        if (gcd(i, sum - i) > 1) {
            cout << "Yes" << "\n";
            cout << 1 << " " << i << "\n";
            cout << n - 1 << " ";
            for (int j = 1; j <= n; j++) {
                if (j != i) {
                    cout << j << " ";
                }
            }
            return 0;
        }
    }
    cout << "No";
    return 0;
}