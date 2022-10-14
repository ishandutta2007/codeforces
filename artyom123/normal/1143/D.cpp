#include<bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

long long ans1 = INF, ans2 = -INF;
long long n, k;

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

long long lcm(long long a, long long b) {
    return a / gcd(a, b);
}

void solve(long long d) {
    if (d == 0) {
        d = k;
    }
    for (long long i = 0; i < n + 5; i++) {
        ans1 = min(ans1, lcm(n * k, i * k + d));
        ans2 = max(ans2, lcm(n * k, i * k + d));
    }
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n >> k;
    long long a, b;
    cin >> a >> b;
    solve(a + b);
    solve(a + k - b);
    solve(k - a + b);
    solve(k - a + k - b);
    cout << ans1 << " " << ans2;
    return 0;
}