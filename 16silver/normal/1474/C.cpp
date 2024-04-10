#include <bits/stdc++.h>
using namespace std;
void solve(){
	int n;
	cin >> n;
	vector<int> a(2*n);
	for(int i=0;i<2*n;i++) cin >> a[i];
	sort(a.begin(),a.end());
	for(int i=0;i<2*n-1;i++){
		vector<int> chkd(2*n);
		vector<pair<int,int>> ans;
		map<int,int> mp;
		int cur = a[2*n-1] + a[i], idx = 2*n-1;
		for(int j=0;j<n;j++){
			if(mp.count(cur-a[idx])) mp[cur-a[idx]]++;
			else mp[cur-a[idx]] = 1;
			ans.emplace_back(a[idx],cur-a[idx]);
			cur = a[idx];
			for(idx--;idx>=0 && mp.count(a[idx]);idx--){
				mp[a[idx]]--;
				if(mp[a[idx]] == 0) mp.erase(a[idx]);
			}
		}
		if(idx == -1){
			cout << "YES\n";
			cout << a[2*n-1] + a[i] << "\n";
			for(auto p : ans){
				cout << p.first << " " << p.second << "\n";
			}
			return;
		}
	}
	cout << "NO\n";
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin >> T;
	for(int i=0;i<T;i++) solve();
}