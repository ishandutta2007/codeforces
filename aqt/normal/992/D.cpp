
// Problem : D. Nastya and a Game
// Contest : Codeforces - Codeforces Round #489 (Div. 2)
// URL : https://codeforces.com/contest/992/problem/D
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

long long N, K;
long long arr[200005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> K;
	for(int i = 1; i<=N; i++){
		cin >> arr[i];
	}
	long long ans = 0;
	vector<int> v;
	v.push_back(0);
	for(int i =1 ; i<=N; i++){
		long long p = arr[i], s = arr[i];
		int lst = i;
		for(int j = v.size()-1; j>=0; j--){
			if(p%K == 0 && p/K >= s && p/K <= s+lst-v[j]-1){
				ans++;
			}
			s += arr[v[j]];
			s += lst-v[j]-1;
			lst = v[j];
			if((long long) (3e18) / p < arr[v[j]]){
				break;
			}
			p *= arr[v[j]];
		}
		if(arr[i] != 1){
			v.push_back(i);
		}
	}
	cout << ans;
}