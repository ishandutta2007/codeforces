#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
// #include<atcoder/fenwicktree>
using namespace std;
// using namespace atcoder;

long long gcd(long long a, long long b){
    if(a > b) swap(a, b);
    if(a == 0) return b;
    return gcd(b % a, a);
}

void solve(){
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    long long ans = 0;
    for(int i = a + 1; i <= c; i++){
        long long g = gcd(i, a * b);
        long long x = a * b / g;
        if(d / x * x > b){
            cout << i << " " << d / x * x << "\n";
            return;
        }
    }
    cout << "-1 -1" << "\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    t = 1;
    cin >> t;
    while(t--) solve();
}