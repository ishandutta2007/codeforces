#include<bits/stdc++.h>
 
using namespace std;

//#define int int64_t
#define all(x) begin(x),end(x)

void solve() {
	int n, m;
	cin >> n >> m;
	int a[m], b[m];
	vector<int> cnt_l(n), cnt_g(n);
	vector<int> gr[n];
	for(int i = 0; i < m; i++) {
		cin >> a[i] >> b[i];
		a[i]--, b[i]--;
		if(a[i] > b[i]) {
			swap(a[i], b[i]);
		}
		
		gr[a[i]].push_back(b[i]);
		cnt_g[a[i]]++;
		cnt_l[b[i]]++;
	}
	int64_t ans = 0;
	for(int i = 0; i < n; i++) {
		ans += 1LL * cnt_l[i] * cnt_g[i];
	}
	cout << ans << "\n";
	int q;
	cin >> q;
	while(q--) {
		int vi;
		cin >> vi;
		vi--;
		ans -= 1LL * cnt_l[vi] * cnt_g[vi];
		for(auto it: gr[vi]) {
			gr[it].push_back(vi);
			ans += cnt_l[it] - cnt_g[it] - 1;
			cnt_g[it]++;
			cnt_l[it]--;
		}
		cnt_g[vi] -= gr[vi].size();
		cnt_l[vi] += gr[vi].size();
		gr[vi].clear();
		cout << ans << "\n";
	}
}

signed main() {
	//freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0); 
    cin.tie(0);
    int t;
    t = 1;//cin >> t;
    while(t--) {
		solve();
	}
}