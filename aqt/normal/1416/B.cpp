
// Problem : B. Make Them Equal
// Contest : Codeforces - Codeforces Round #673 (Div. 1)
// URL : https://codeforces.com/contest/1416/problem/B
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

struct triple{
	int i, j, x;
	triple(int _i, int _j, int _x){
		i = _i;
		j = _j;
		x = _x;
	}
};

int T, N;
long long arr[10005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--){
		cin >> N;
		for(int i = 1; i<=N; i++){
			cin >> arr[i];
		}
		vector<triple> ans;
		for(int i = 2; i<=N; i++){
			int nxt = (arr[i]+i-1)/i*i;
			ans.emplace_back(1, i, nxt-arr[i]);
			ans.emplace_back(i, 1, nxt/i);
			arr[1] += arr[i];
		}
		long long k = arr[1]/N;
		if(arr[1]%N){
			cout << -1 << "\n";
			continue;
		}
		for(int i = 2; i<=N; i++){
			ans.emplace_back(1, i, k);
		}
		cout << ans.size() << "\n";
		for(auto t : ans){
			cout << t.i << " " << t.j << " " << t.x << "\n";
		}
	}
}