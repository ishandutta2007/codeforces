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
    string S;
    cin >> S;
    map<int, char> mp;
    for(int i = 0; i < n; i++){
        if(!mp.count(A[i])) mp[A[i]] = S[i];
        if(mp[A[i]] != S[i]){
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    t = 1;
    cin >> t;
    while(t--) solve();
}