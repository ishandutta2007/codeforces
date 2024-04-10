#include <bits/stdc++.h>

using namespace std;

const int MAXN = 16;

int m[16];
int r[16];
int lcm = 0;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> m[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> r[i];
    }
    lcm = m[0];
    for (int i = 1; i < n; i++) {
        int p = (lcm * m[i]);
        lcm = p / __gcd(lcm, m[i]);
    }
    int ans = 0;
    for (int d = 1; d <= lcm; d++) {
        for (int i = 0; i < n; i++) {
            if (d % m[i] == r[i]) {
                ans++;
                break;
            }
        }
    }
    cout << ans / (double) lcm << endl;
}