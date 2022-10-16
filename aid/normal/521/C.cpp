#include <iostream>
#include <string>

using namespace std;

const int MAXN = 100 * 1000 + 5, MOD = 1000 * 1000 * 1000 + 7;
int p10[MAXN], c[MAXN];
string s;

pair<int, int> gcd(int a, int b) {
    if(!b)
        return make_pair(1, 0);
    pair<int, int> p = gcd(b, a % b);
    return make_pair(p.second, p.first - (a / b) * p.second);
}

int inv(int x) {
    return gcd(x, MOD).first;
}

int main() {
    ios_base::sync_with_stdio(false);
    p10[0] = 1;
    for(int i = 1; i < MAXN; i++)
        p10[i] = ((long long)p10[i - 1] * 10) % MOD;
    int n, k;
    cin >> n >> k >> s;
    int ans = 0, num = 0;
    if(k == 0) {
        for(int i = 0; i < n; i++)
            num = ((long long)num * 10 + (s[i] - '0')) % MOD;
        ans = (ans + num) % MOD;
        ans = (ans + MOD) % MOD;
        cout << ans << '\n';
        return 0;
    }
    c[k - 1] = 1;
    for(int i = k; i < MAXN; i++)
        c[i] = ((((long long)c[i - 1] * i) % MOD) * inv(i - k + 1)) % MOD;
    num = 0;
    for(int i = 0; i < n - 1; i++) {
        num = ((long long)num * 10 + (s[i] - '0')) % MOD;
        ans = (ans + (long long)num * c[n - i - 2]) % MOD;
    }
    num = 0;
    for(int i = n - 1; i > 0; i--) {
        num = (num + (long long)p10[n - 1 - i] * (s[i] - '0')) % MOD;
        ans = (ans + (long long)num * c[i - 1]) % MOD;
    }
    if(k == 1) {
        ans = (ans + MOD) % MOD;
        cout << ans << '\n';
        return 0;
    }
    for(int i = 0; i < MAXN; i++)
        c[i] = 0;
    k--;
    c[k - 1] = 1;
    for(int i = k; i < MAXN; i++)
        c[i] = ((((long long)c[i - 1] * i) % MOD) * inv(i - k + 1)) % MOD;
    k++;
    int sum = 0, sum0 = 0;
    for(int i = 1; i < n - 1; i++)
        sum += s[i] - '0';
    sum0 = sum;
    ans = (ans + (long long)sum * c[n - 3]) % MOD;
    num = 0;
    for(int i = 1; i < n - 2; i++) {
        sum0 -= s[i] - '0';
        num = (num + (long long)p10[i - 1] * (s[n - i - 1] - '0')) % MOD;
        sum = (sum - num) % MOD;
        sum = ((long long)sum * 10 + sum0) % MOD;
        ans = (ans + (long long)sum * c[n - i - 3]) % MOD;
    }
    ans = (ans + MOD) % MOD;
    cout << ans << '\n';
    return 0;
}