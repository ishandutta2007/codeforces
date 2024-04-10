#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
//#include<atcoder/lazysegtree>
using namespace std;
//using namespace atcoder;

void solve(){
    int n, m, k;
    long long s;
    cin >> n >> m >> k >> s;
    vector<long long> A(n), B(n);
    vector<int> Aind(n), Bind(n);
    for(int i = 0; i < n; i++){
        cin >> A[i];
        Aind[i] = i;
        if(i >= 1 && A[i - 1] < A[i]){
            A[i] = A[i - 1];
            Aind[i] = Aind[i - 1];
        }
    }
    for(int i = 0; i < n; i++){
        cin >> B[i];
        Bind[i] = i;
        if(i >= 1 && B[i - 1] < B[i]){
            B[i] = B[i - 1];
            Bind[i] = Bind[i - 1];
        }
    }
    vector<pair<long long, int>> D, P;
    int t;
    long long c;
    for(int i = 1; i <= m; i++){
        cin >> t >> c;
        if(t == 1) D.push_back({c, i});
        else P.push_back({c, i});
    }
    D.push_back({0, -1});
    P.push_back({0, -1});
    sort(D.begin(), D.end());
    sort(P.begin(), P.end());
    while(D.size() <= k) D.push_back({1LL << 30, -1});
    while(P.size() <= k) P.push_back({1LL << 30, -1});
    for(int i = 1; i <= k; i++){
        D[i].first += D[i - 1].first;
        P[i].first += P[i - 1].first;
    }

    auto ok = [&](int x) -> int{
        for(int i = 0; i <= k; i++){
            long long tmp = D[i].first * A[x] + P[k - i].first * B[x];            
            if(tmp <= s) return i;
        }
        return -1;
    };

    int l = -1;
    int r = n;
    while(r - l > 1){
        int mid = (l + r) / 2;
        if(ok(mid) != -1) r = mid;
        else l = mid;
    }
    if(r == n) cout << "-1\n";
    else{
        cout << r + 1 << "\n";
        int i = ok(r);
        for(int j = 1; j <= i; j++) cout << D[j].second << " " << Aind[r] + 1 << "\n";
        for(int j = 1; j <= k - i; j++) cout << P[j].second << " " << Bind[r] + 1 << "\n";

    }
    


}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    t = 1;
    //cin >> t;
    while(t--) solve();
}