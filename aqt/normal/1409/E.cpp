
// Problem : E. Two Platforms
// Contest : Codeforces - Codeforces Round #667 (Div. 3)
// URL : https://codeforces.com/contest/1409/problem/E
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int T;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--){
		int N, K;
		cin >> N >> K;
		vector<int> x;
		for(int i = 0; i<N; i++){
			int n;
			cin >> n;
			x.push_back(n);
		}
		for(int i = 0; i<N; i++){
			int n;
			cin >> n;
		}
		sort(x.begin(), x.end());
		vector<int> k;
		int mx = 0, ans = 0;
		for(int l = 0, r = 1; r<=N; r++){
			int idx = lower_bound(x.begin(), x.end(), x[r-1] - K) - x.begin();
			k.push_back(r-idx);
			while(l < N && x[l] < x[r-1]-K){
				mx = max(mx, k[l]);
				l++;
			}
			ans = max(ans, mx + r - idx);
		}
		cout << ans << "\n";
	}
}