
// Problem : C. RationalLee
// Contest : Codeforces - Codeforces Round #652 (Div. 2)
// URL : https://codeforces.com/contest/1369/problem/C
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		int N, K;
		cin >> N >> K;
		vector<int> v;
		for(int i = 0; i<N; i++){
			int k;
			cin >> k;
			v.push_back(k);
		}
		sort(v.begin(), v.end(), greater<int>());
		vector<int> w;
		for(int i = 0; i<K; i++){
			int n;
			cin >> n;
			w.push_back(n);
		}
		sort(w.begin(), w.end());
		long long ans = 0;
		int idx = 0;
		for(int i = 0; i<K; i++){
			ans += v[i];
			if(idx < w.size() && w[idx] == 1){
				idx++;
				ans += v[i];
			}
		}
		int lst = K-1;
		for(int i = idx; i<K; i++){
			ans += v[lst+w[i]-1];
			lst += w[i]-1;
		}
		cout << ans << "\n";
	}
}