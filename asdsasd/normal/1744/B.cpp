#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
// #include<atcoder/fenwicktree>
using namespace std;
// using namespace atcoder;

void solve(){
    int n, Q;
    cin >> n >> Q;
    long long odd = 0;
    long long even = 0;
    long long tot = 0;
    long long a;
    for(int i = 0; i < n; i++){
        cin >> a;
        if(a & 1) odd++;
        else even++;
        tot += a;
    }
    int t;
    long long x;
    while(Q--){
        cin >> t >> x;
        if(t == 0){
            tot += x * even;
            if(x & 1){
                odd += even;
                even = 0;
            }
        }
        else{
            tot += x * odd;
            if(x & 1){
                even += odd;
                odd = 0;
            }
        }
        cout << tot << "\n";
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    t = 1;
    cin >> t;
    while(t--) solve();
}