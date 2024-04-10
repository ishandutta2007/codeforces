#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
// #include<atcoder/mincostflow>
using namespace std;
// using namespace atcoder;
const int N = 200020;
long long A[N];

void solve(){
    int n, q;
    cin >> n >> q;
    for(int i = 0; i < n; i++) cin >> A[i];
    vector<int> div;
    for(int i = 1; i * i <= n; i++){
        if(n % i == 0){
            div.push_back(i);
            if(i * i != n) div.push_back(n / i);
        }
    }
    sort(div.begin(), div.end());
    div.pop_back();
    vector<int> div2;
    for(int i = 0; i < div.size(); i++){
        bool ok = true;
        for(int j = i + 1; j < div.size(); j++){
            if(div[j] % div[i] == 0){
                ok = false;
                break;
            }
        }
        if(ok) div2.push_back(div[i]);
    }
    div = div2;
    
    vector<vector<long long>> dp(div.size(), vector<long long>());
    multiset<long long> ms;
    for(int i = 0; i < div.size(); i++){
        long long d = div[i];
        dp[i].resize(d);
        int t = 0;
        for(int j = 0; j < n; j++){
            dp[i][t] += A[j] * d;
            t++;
            if(t == d) t = 0;
        }
        for(auto p: dp[i]){
            ms.insert(p);
        }
    }
    auto it = ms.end();
    it--;
    cout << *it << "\n";
    int p;
    long long x;
    while(q--){
        cin >> p >> x;
        p--;
        long long plus = x - A[p];
        A[p] = x;
        for(int i = 0; i < div.size(); i++){
            long long d = div[i];
            int t = p % d;
            auto it = ms.find(dp[i][t]);
            ms.erase(it);
            dp[i][t] += plus * d;
            ms.insert(dp[i][t]);
        }
        auto it = ms.end();
        it--;
        cout << *it << "\n";
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    t = 1;
    cin >> t;
    while(t--) solve();
}