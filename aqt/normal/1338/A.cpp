
// Problem : A. Powered Addition
// Contest : Codeforces Round #633 (Div. 1)
// URL : https://codeforces.com/contest/1338/problem/A
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		int N;
		cin >> N;
		vector<long long> v;
		v.push_back(-1000000000);
		int ans = 0;
		for(int i = 1; i<=N; i++){
			int n;
			cin >> n;
			v.push_back(n);
			if(v.back() < v[i-1]){
				//cout << v[i-1] << " " << v[i] << " " << __builtin_clz(v[i-1]-v[i]) << "\n";
				ans = max(ans, 32-__builtin_clz(v[i-1]-v[i]));
				v[i] = v[i-1];
			}
		}
		cout << ans << "\n";
	}
}