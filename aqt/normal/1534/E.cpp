
// Problem : E. Lost Array
// Contest : Codeforces - Codeforces LATOKEN Round 1 (Div. 1 + Div. 2)
// URL : https://codeforces.com/contest/1534/problem/E
// Memory Limit : 256 MB
// Time Limit : 1500 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, K;
int dist[505];
int par[505];

int query(vector<int> v){
	cout << "? ";
	for(int n : v){
		cout << n << " ";
	}
	cout << endl;
	int x;
	cin >> x;
	return x;
}
set<int> st;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> K;
	vector<vector<int>> lst;
	/*
	int cnt = 0;
	for(int i = 0; 1; i = (i + K) % N){
		vector<int> tmp;
		for(int j = 0; j < K; j++){
			tmp.emplace_back((i + j)%N);
			cnt += !((i + j)%N);
		}
		lst.push_back(tmp);
		if((i + K - 1)%N == N - 1){
			break;
		}
	}
	if(cnt % 2 == 0){
		cout << -1 << endl;
		return 0;
	}
	*/
	queue<int> qu;
	qu.push(0);
	fill(dist + 1, dist + 1 + N, INT_MAX / 2);
	while(qu.size()){
		int n = qu.front();
		//cout << "bfs: " << n << endl;
		qu.pop();
		for(int k = 0; k <= K; k++){
			if(n >= k && n - 2 * k + K <= N && N - n >= K - k){
				//cout << " " << k << " " << n-2 * k+K << endl;
				if(dist[n - 2 * k + K] > dist[n] + 1){
					dist[n - 2 * k + K] = dist[n] + 1;
					par[n - 2 * k + K] = n;
					qu.push(n - 2 * k + K);
				}
			}
		}
	}
	//cout << dist[N] << endl;
 	if(dist[N] == INT_MAX / 2){
		cout << -1 << endl;
		return 0;
	}
	vector<int> path;
	int cur = N;
	while(cur){
		path.push_back(cur);
		//cout << cur << " " << par[cur] << endl;
		cur = par[cur];
	}
	reverse(path.begin(), path.end());
	for(int x : path){
		int k = (cur - x + K)/2;
		vector<int> tmp;
		for(int n = 1; (int) (tmp.size()) < K - k; n++){
			if(!st.count(n)){
				tmp.push_back(n);
			}			
		}
		for(int n = 1; n <= k; n++){
			tmp.push_back(*st.begin());
			st.erase(st.begin());
		}
		for(int t = 0; t < K - k; t++){
			st.insert(tmp[t]);
		}
		cur = x;
		lst.push_back(tmp);
	}
	long long ans = 0;
	for(auto v : lst){
		ans ^= query(v);
	}
	cout << "! " << ans << endl;
}