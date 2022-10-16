#include <iostream>

using namespace std;

const int MOD = 1000 * 1000 * 1000 + 7;

pair<int, int> gcd(int a, int b) {
    if(!b)
        return make_pair(1, 0);
    pair<int, int> p = gcd(b, a % b);
    return make_pair(p.second, p.first - (a / b) * p.second);
}

int inv(int x) {
    int res = gcd(x, MOD).first;
    if(res < 0)
        res += MOD;
    return res;
}

int fact(int n) {
    int res = 1;
    for(int i = 1; i <= n; i++)
        res = (long long)res * i % MOD;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    n++;
    int f2n = fact(2 * n), fn = fact(n);
    cout << ((long long)f2n * inv((long long)fn * fn % MOD) % MOD +
             MOD - 1) % MOD << '\n';
    return 0;
}