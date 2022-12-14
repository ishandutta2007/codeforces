#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

long long tavan2(long long n){
    if (n == 1)
        return 2;
    if (n == 0)
        return 1;
    if (n % 2 == 0){
        long long k = tavan2(n / 2);
        return k * k % MOD;
    }
    else{
        long long k = tavan2(n / 2);
        return k * k * 2 % MOD;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    long long n, k = 1;
    cin >> n;
    k = tavan2(n);
    cout << (k * (k + 1) / 2) % MOD << endl;
}