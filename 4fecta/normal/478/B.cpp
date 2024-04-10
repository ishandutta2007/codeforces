#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
int ch(int n) {
    return n * (n - 1) / 2;
}
int32_t main() {
    cin >> n >> m;
    int num = n / m;
    int rem = n % m;
    int mn = ch(num) * (m - rem) + ch(num + 1) * rem;
    int mx = ch(n - m + 1);
    printf("%lld %lld\n", mn, mx);
}