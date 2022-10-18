#include <bits/stdc++.h>
 
using namespace std;

#define all(x) begin(x), end(x)
#define int int64_t

vector<int> try_build(int n, int s, int m) {
    vector<int> p(n);
    vector<int> cnt(n, 1);
    cnt[n - 1] = 0;
    iota(all(p), 0);
    vector<int> on_h[n + 1];
    for(int i = 1; i <= n; i++) {
        on_h[i] = {i};
    }
    
    int ns = n * (n + 1) / 2;
    int idl = 1, idr = n - 1;
    while(ns > s && idl < idr) {
        if(on_h[idl].empty()) {
            idl++;
            continue;
        }
        int t = min(ns - s, idr - idl);
        int npar = on_h[idr - t].back();
        cnt[p[idr] - 1]--;
        cnt[npar - 1]++;
        if(cnt[npar - 1] == m) {
            on_h[idr - t].pop_back();
        }
        p[idr] = npar;
        on_h[idr - t + 1].push_back(idr + 1);
        ns -= t;
        idr--;
        
    }
    return ns == s ? p : vector<int>{-1};
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, s;
    for(int i = 0; i < 1; i++) {
        cin >> n >> s;
        int l = 1, r = n;
        while(r - l > 1) {
            int m = (l + r) / 2;
            auto res = try_build(n, s, m);
            if(res == vector<int>{-1}) {
                l = m;
            } else {
                r = m;
            }
        }
        auto res = try_build(n, s, r);
        if(res == vector<int>{-1}) {
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
            for(int i = 1; i < n; i++) {
                cout << res[i] << ' ';
            }
        }
    }
    return 0;
}