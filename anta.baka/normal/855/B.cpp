#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n, p, q, r, a[100000], b[100000], c[100000], d[100000];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> p >> q >> r;
    for(int i = 0; i < n; i++) cin >> a[i];
    b[n - 1] = r * a[n - 1];
    for(int i = n - 2; i >= 0; i--) b[i] = max(b[i + 1], r * a[i]);
    c[n - 1] = b[n - 1] + q * a[n - 1];
    for(int i = n - 2; i >= 0; i--) c[i] = max(c[i + 1], q * a[i] + b[i]);
    d[n - 1] = c[n - 1] + p * a[n - 1];
    for(int i = n - 2; i >= 0; i--) d[i] = max(d[i + 1], p * a[i] + c[i]);
    cout << d[0];
}