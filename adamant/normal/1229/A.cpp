#include<bits/stdc++.h>
 
using namespace std;

#define int int64_t
#define all(x) begin(x),end(x)

void solve() {
	int n;
	cin >> n;
	int a[n], b[n];
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for(int i = 0; i < n; i++) {
		cin >> b[i];
	}
	map<int, int, greater<int>> cnt, sum;
	for(int i = 0; i < n; i++) {
		cnt[a[i]] += 1;
		sum[a[i]] += b[i];
	}
	vector<int> took;
	int ans = 0;
	for(auto it: cnt) {
		if(it.second > 1) {
			took.push_back(it.first);
			ans += sum[it.first];
		} else {
			for(auto jt: took) {
				if((it.first & jt) == it.first) {
					took.push_back(it.first);
					ans += sum[it.first];
					break;
				}
			}
		}
	}
	cout << ans << "\n";
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