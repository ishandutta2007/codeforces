#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int mod = 1e9 + 7;
        int n, k;
        cin >> n >> k;
        int z = 1;
        for (int i = 0; i < k; i++) {
            z = (z * (long long)n) % mod;
        }
        cout << z << '\n';
    }
}