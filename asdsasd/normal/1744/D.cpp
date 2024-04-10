#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
// #include<atcoder/fenwicktree>
using namespace std;
// using namespace atcoder;

void solve(){
    int n;
    cin >> n;
    vector<int> A(n);
    for(auto &a: A) cin >> a;
    int tot = 0;
    for(auto a:A){
        while(a % 2 == 0){
            a /= 2;
            tot++;
        }
    }
    if(tot >= n){
        cout << 0 << "\n";
        return;
    }
    vector<int> add;
    for(int i = 1; i <= n; i++){
        int c = 0;
        int ii = i;
        while(ii % 2 == 0){
            ii /= 2;
            c++;
        }
        if(c != 0) add.push_back(c);
    }
    sort(add.begin(), add.end(), greater<int>());
    int p = 0;
    for(auto a: add){
        tot += a;
        p++;
        if(tot >= n){
            cout << p << "\n";
            return;
        }
    }
    cout << -1 << "\n";

    
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    t = 1;
    cin >> t;
    while(t--) solve();
}