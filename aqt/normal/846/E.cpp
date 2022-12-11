
// Problem : E. Chemistry in Berland
// Contest : Codeforces - Educational Codeforces Round 28
// URL : https://codeforces.com/contest/846/problem/E
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
long long arr[100005], brr[100005];
vector<pair<int, long long>> graph[100005];
bool ans = 1;

long long dfs(int n){
	long long tot = arr[n] - brr[n];
	for(auto e : graph[n]){
		long long k = dfs(e.first);
		if(k < 0){
			if(1000000000000000000LL/e.second < -k){
				ans = 0;
			}
			tot += k*e.second;
		}
		else{
			tot += k;
		}
		if(tot < -1000000000000000000LL){
			ans = 0;
		}
	}
	//cout << n << " " << tot << "\n";
	return tot;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for(int i = 1; i<=N; i++){
		cin >> arr[i];
	}
	for(int i = 1; i<=N; i++){
		cin >> brr[i];
	}
	for(int i = 2; i<=N; i++){
		int p;
		long long x;
		cin >> p >> x;
		graph[p].emplace_back(i, x);
	}
	long long a = dfs(1);
	//cout << a << "\n";
	if(a < 0){
		ans = 0;
	}
	cout << (ans ? "YES" : "NO");
}