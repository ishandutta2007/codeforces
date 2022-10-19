#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
// #include<atcoder/lazysegtree>
using namespace std;
// using namespace atcoder;



void solve(){
    int n;
    long long k;
    cin >> n >> k;
    vector<vector<int>> edges(n, vector<int>());
    int p;
    for(int i = 1; i < n; i++){
        cin >> p;
        p--;
        edges[p].push_back(i);
    }
    vector<long long> S(n);
    for(int i = 0; i < n; i++) cin >> S[i];

    map<pair<int, long long>, long long> memo;
    auto dfs=[&](auto&& self, int pos, long long cnt) -> long long {
        if(memo.count({pos, cnt})) return memo[{pos, cnt}];
        int s = edges[pos].size();
        if(s == 0) return cnt * S[pos];
        vector<long long> mi(s), ma(s);
        long long l = cnt / s;
        long long r = l + 1;
        for(int i = 0; i < s; i++){
            int npos = edges[pos][i];
            mi[i] = self(self, npos, l);
            ma[i] = self(self, npos, r);
        }
        long long ret = S[pos] * l * s;
        for(auto m:mi) ret += m;
        vector<long long> d(s);
        for(int i = 0; i < s; i++) d[i] = ma[i] - mi[i];
        sort(d.begin(), d.end(), greater<long long>());
        long long x = s * l;
        memo[{pos, x}] = ret;
        for(int i = 0; i < s; i++){
            x++;
            ret += d[i] + S[pos];
            memo[{pos, x}] = ret;
        }
        return memo[{pos, cnt}];
    };

    long long ans = dfs(dfs, 0, k);
    cout << ans << "\n";
}


int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    t = 1;
    cin >> t;
    while(t--) solve();
}