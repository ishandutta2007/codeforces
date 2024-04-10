
// Problem : D. Game of Pairs
// Contest : Codeforces - Codeforces Round #668 (Div. 1)
// URL : https://codeforces.com/contest/1404/problem/D
// Memory Limit : 256 MB
// Time Limit : 4000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;
pair<int, int> pairs[500005];
int who[1000005];
bool vis[500005];
vector<int> ans;

void dfs(int n){
	if(vis[who[n]]){
		return;
	}
	ans.push_back(n);
	vis[who[n]] = 1;
	int k = pairs[who[n]].first;
	if(k == n){
		k = pairs[who[n]].second;
	}
	if(k > N){
		k -= N;
	}
	else{
		k += N;
	}
	dfs(k);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	if(N%2 == 0){
		cout << "First" << endl;
		for(int i = 1; i <= 2 * N; i++){
			cout << (i % N + 1) << " ";
		}
		cout << endl;
	}
	else{
		cout << "Second" << endl;
		for(int i = 1; i <= 2 * N; i++){
			cin >> who[i];
			if(pairs[who[i]].first){
				pairs[who[i]].second = i;
			}
			else{
				pairs[who[i]].first = i;
			}
		}
		for(int i = 1; i <= 2 * N; i++){
			dfs(i);
		}
		long long s = 0;
		for(int n : ans){
			s += n;
		}
		if(s % (2 * N)){
			sort(ans.begin(), ans.end());
			vector<int> tmp;
			for(int n = 1; n <= 2 * N; n++){
				if(lower_bound(ans.begin(), ans.end(), n) == upper_bound(ans.begin(), ans.end(), n)){
					tmp.emplace_back(n);
				}
			}
			ans = tmp;
		}
		for(int n : ans){
			cout << n << " ";
		}
		cout << endl;
	}
}