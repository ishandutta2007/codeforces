#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
//#include<atcoder/segtree>
using namespace std;
//using namespace atcoder;

void solve(){
    int n, K;
    cin >> n >> K;
    map<long long, int> imos;
    long long l, r;
    for(int i = 0; i < n; i++){
        cin >> l >> r;
        imos[2 * l]++;
        imos[2 * r + 1]--;
    }
    int tot = 0;
    vector<pair<long long, long long>> ans;
    long long bef;
    for(auto k:imos){
        int nex = tot + k.second;
        if(tot < K && nex >= K){
            bef = k.first;
        }
        else if(tot >= K && nex < K){
            long long l = bef / 2;
            long long r = (k.first - 1) / 2;
            ans.push_back({l, r});
        }
        tot = nex;
    }
    cout << ans.size() << "\n";
    for(auto tmp:ans){
        cout << tmp.first << " " << tmp.second << "\n";
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    t = 1;
    // cin >> t;
    while(t--) solve();
}