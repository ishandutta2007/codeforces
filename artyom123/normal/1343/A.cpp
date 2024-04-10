#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        for (long long l = 4; l <= (1LL << 31); l *= 2) {
            if (n % (l - 1) == 0) {
                cout << n / (l - 1) << "\n";
                break;
            }
        }
    }
    return 0;
}