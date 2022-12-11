#include <bits/stdc++.h>

using namespace std;

int N;
long long MOD;
long long fact[250005];

long long add(long long a, long long b){
    return (a+b)%MOD;
}

long long mult(long long a, long long b){
    return (a*b)%MOD;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> MOD;
    fact[0] = 1;
    for(int i = 1; i<=N; i++){
        fact[i] = mult(fact[i-1], i);
    }
    long long ans = 0;
    for(int i = 1; i<=N; i++){
        ans = add(ans, mult(N-i+1, mult(mult(N-i+1, fact[i]), fact[N-i])));
    }
    cout << ans << endl;
}