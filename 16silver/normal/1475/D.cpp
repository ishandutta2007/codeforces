#include <bits/stdc++.h>
using namespace std;
void solve(){
	long long n,m;
	cin >> n >> m;
	vector<long long> v(n), w[2];
	for(int i=0;i<n;i++) cin >> v[i];
	for(int i=0;i<n;i++){
		int t;
		cin >> t;
		w[t-1].push_back(v[i]);
	}
	sort(w[0].rbegin(),w[0].rend());
	sort(w[1].begin(),w[1].end());
	int L = w[0].size();
	long long tmp = 0LL;
	int ans = 100000000, cur = 0;
	for(int x : w[1]){
		cur += 2;
		tmp += x;
	}
	int idx = 0;
	while(idx < L && tmp < m){
		tmp += w[0][idx];
		idx++;
		cur++;
	}
	if(tmp < m){
		cout << "-1\n";
		return;
	}
	ans = min(ans, cur);
	for(int x : w[1]){
		tmp -= x;
		cur -= 2;
		while(idx < L && tmp < m){
			tmp += w[0][idx];
			idx++;
			cur++;
		}
		if(tmp < m) break;
		ans = min(ans, cur);
	}
	cout << ans << "\n";
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin >> T;
	for(int i=0;i<T;i++) solve();
}