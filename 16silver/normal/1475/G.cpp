#include <bits/stdc++.h>
using namespace std;
void solve(){
	int n;
	cin >> n;
	vector<int> v(200001), w(200001);
	for(int i=0;i<n;i++){
		int t;
		cin >> t;
		v[t]++;
	}
	int ans = 0;
	for(int i=200000;i>0;i--){
		if(v[i]){
			for(int j=i*2;j<200001;j+=i) w[i] = max(w[i], w[j]);
			w[i] += v[i];
			ans = max(ans, w[i]);
		}
	}
	cout << n - ans << "\n";
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin >> T;
	for(int i=0;i<T;i++) solve();
}