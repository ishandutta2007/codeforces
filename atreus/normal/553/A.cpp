#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;
int a[2000];

long long ent(long long l, long long r){
    int b[r + 100], c[l + 100];
    for (int i = 1; i <= l; i++)
        b[i] = 1;
    for (int i = l + 1; i <= r; i++)
        b[i] = i;
    for (int i = 1; i <= r - l; i++){
        c[i] = i;
    }
    for (int i = 1; i <= r - l; i++){
        for (int j = 1; j <= r; j++){
            if (__gcd(c[i], b[j]) > 1){
                int x = __gcd(c[i], b[j]);
                c[i] /= x;
                b[j] /= x;
            }
        }
    }
    long long k = 1;
    for (int i = 1; i <= r; i++){
        k *= b[i];
        k %= MOD;
    }
    return k;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    long long ans = 1, sum = a[0];
    for (int i = 1; i < n; i++){
        ans *= ent(sum, sum + a[i] - 1) % MOD;
        ans = ans % MOD;
        sum += a[i];
    }
    cout << ans % MOD << endl;
}