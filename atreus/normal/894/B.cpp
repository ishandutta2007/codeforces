#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;
long long n, m, k;
long long pok;

long long p(long long k){
    if (k == 1)
        return pok;
    if (k == 0)
        return 1;
    long long l;
    if (k % 2 == 0){
        l = p(k / 2);
        return (l * l) % MOD;
    }
    else{
        l = p(k - 1);
        return (l * pok) % MOD;
    }
}

long long f(long long k){
    if (k == 1)
        return 2;
    if (k == 0)
        return 1;
    long long l;
    if (k % 2 == 0){
        l = f(k / 2);
        return (l * l) % MOD;
    }
    else{
        l = f(k - 1);
        return (l * 2) % MOD;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> k;
    if ((n + m) % 2 == 1 && k == -1)
        return cout << 0, 0;
    m --;
    n --;
    pok = f(m) % MOD;
    cout << 1ll * p(n) % MOD;
}