#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
//#include<atcoder/segtree>
using namespace std;
//using namespace atcoder;

void solve(){
    int n, k;
    cin >> n >> k;
    set<int> se;
    vector<int> A;
    int a;
    for(int i = 0; i < n; i++){
        cin >> a;
        if(se.count(a)) continue;
        se.insert(a);
        A.push_back(a);
    }
    se.clear();
    for(int p = 1; p <= k; p++){
        se.insert(A[0] / p);
    }
    n = A.size();
    if(n == 1){
        cout << 0 << "\n";
        return;
    }
    int ans = 1 << 30;
    for(auto s:se){
        if(s == 0){
            ans = A[n - 1] / k;
            continue;
        }
        vector<pair<int, int>> B;
        int ma = s;
        for(int i = 1; i < n; i++){
            int p = A[i] / s;
            p = min(p, k);
            int ma_ = A[i] / p;
            p = (A[i] + s - 1) / s;
            p = min(p, k);
            int mi_ = A[i] / p;
            B.push_back({mi_, ma_});
            if(mi_ > ma) ma = mi_;
        }
        sort(B.begin(), B.end(), [](pair<int, int> l, pair<int, int> r){
            if(l.first < r.first) return true;
            else if(l.first > r.first) return false;
            return l.second < r.second;
        });
        int mi = B[0].first;
        if(mi > s) mi = s;
        if(ma - mi < ans) ans = ma - mi;
        B.push_back({s, s});
        for(int i = 0; i < n - 1; i++){
            if(B[i].second > ma) ma = B[i].second;
            if(B[i + 1].first > mi) mi = B[i + 1].first;
            if(mi > s) mi = s;
            if(ma - mi < ans) ans = ma - mi;
        }
    }
    cout << ans << endl;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    t = 1;
    cin >> t;
    while(t--) solve();
}