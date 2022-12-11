
// Problem : E. Competition
// Contest : Codeforces - Codeforces Round #103 (Div. 2)
// URL : https://codeforces.com/contest/144/problem/E
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
vector<pair<int, int>> add[100005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, M;
	cin >> N >> M;
	for(int i = 1; i<=M; i++){
		int x, y;
		cin >> x >> y;
		add[x-(x+y-N-1)].emplace_back(x, i);
	}
	vector<int> ans;
	for(int i = 1; i<=N; i++){
		for(auto p : add[i]){
			pq.push(p);
		}
		while(pq.size() && pq.top().first < i){
			pq.pop();
		}
		if(pq.size()){
			ans.push_back(pq.top().second);
			pq.pop();
		}
	}
	cout << ans.size() << "\n";
	for(int n : ans){
		cout << n << " ";
	}
}