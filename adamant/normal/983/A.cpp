#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
#define int int64_t

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

long long mul( long long a, long long b, long long m ) {
  long long q = (long long)((long double)a * (long double)b / (long double)m);
  long long r = a * b - q * m;
  return (r + 5 * m) % m;
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<string> ans(n);
    for(int i = 0; i < n; i++) {
        int p, q, b;
        cin >> p >> q >> b;
        int t = gcd(p, q);
        p /= t;
        q /= t;
        t = 1;
        for(int i = 0; i < 66; i++) {
            t = mul(t, b, q);
        }
        if(t == 0) {
            ans.push_back("Finite\n");
        } else {
            ans.push_back("Infinite\n");
        }
    }
    for(auto it: ans) {
        cout << it;
    }
    return 0;
}