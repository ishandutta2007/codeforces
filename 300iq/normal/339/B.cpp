#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;
    vector <long long> w((size_t)m);
    for (long long i = 0; i < m; i++) {
        cin >> w[i];
    }
    long long h = 1;
    long long ans = 0;
    for (long long i = 0; i < m; i++) {
        if (w[i] != h) {
            if (w[i] > h) {
                ans += w[i] - h;
            }
            if (w[i] < h) {
                ans += n - h + w[i];
            }
            h = w[i];

        }
    }
    cout << ans << endl;
}