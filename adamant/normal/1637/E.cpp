#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using ull = unsigned long long;
const ull FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
//
// https://codeforces.com/blog/entry/62393
struct CustomHash {
	static ull splitmix64(ull x) {
		// http://xorshift.di.unimi.it/splitmix64.c
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}

	size_t operator()(ull x) const {
		return splitmix64(x + FIXED_RANDOM);
	}
};

using namespace std;

#define int int64_t
#define all(x) begin(x), end(x)

void solve() {
    int n, m;
    cin >> n >> m;
    int a[n];
    map<int, int> cnt;
    gp_hash_table<int, int, CustomHash> smol;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
        if(smol.find(a[i]) == end(smol)) {
            int nxt = smol.size();
            smol[a[i]] = nxt;
        }
    }
    vector<int> st[n + 1];
    vector<int> idx;
    for(auto it: cnt) {
        st[it.second].push_back(it.first);
        idx.push_back(it.second);
    }
    sort(all(idx));
    idx.erase(unique(all(idx)), end(idx));
    map<int, vector<int>> g;
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int ans = 0;
    int forbid[n + 1];
    memset(forbid, 0, sizeof forbid);
    for(auto it: cnt) {
        int x = it.first;
        int cx = it.second;
        auto &G = g[x];
        G.push_back(x);
        for(auto jt: G) {
            forbid[smol[jt]] = 1;
        }
        for(auto cy: idx) {
            int j = st[cy].size() - 1;
            while(j >= 0 && forbid[smol[st[cy][j]]]) {
                j--;
            }
            if(j >= 0) {
                int y = st[cy][j];
                //cout << cx << ' ' << cy << ' ' << x << ' ' << y << endl;
                ans = max(ans, (cx + cy) * (x + y));
            }
        }
        for(auto jt: G) {
            forbid[smol[jt]] = 0;
        }
    }
    cout << ans << "\n";
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}