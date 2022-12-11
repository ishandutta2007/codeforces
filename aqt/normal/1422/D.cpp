
// Problem : D. Returning Home
// Contest : Codeforces - Codeforces Round #675 (Div. 2)
// URL : https://codeforces.com/contest/1422/problem/D
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int M, N;
vector<pair<int, int>> graph[1000000];
pair<int, int> arr[100005];
long long dist[1000000];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> M >> N;
	pair<int, int> s, t;
	cin >> s.first >> s.second >> t.first >> t.second;
	vector<int> x, y;
	for(int i = 0; i<N; i++){
		cin >> arr[i].first >> arr[i].second;
		x.push_back(arr[i].first);
		y.push_back(arr[i].second);
	}
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	x.erase(unique(x.begin(), x.end()), x.end());
	y.erase(unique(y.begin(), y.end()), y.end());
	for(int k = 1; k<x.size(); k++){
		graph[k].emplace_back(k-1, x[k] - x[k-1]);
		graph[k-1].emplace_back(k, x[k] - x[k-1]);
	}
	for(int k = 1; k<y.size(); k++){
		//cout << y[k] - y[k-1] << "\n";
		graph[k+x.size()].emplace_back(k+x.size()-1, y[k] - y[k-1]);
		graph[k+x.size()-1].emplace_back(k+x.size(), y[k] - y[k-1]);
	}
	for(int n = 0; n<N; n++){
		int xidx = lower_bound(x.begin(), x.end(), arr[n].first) - x.begin();
		int yidx = lower_bound(y.begin(), y.end(), arr[n].second) - y.begin();
		graph[x.size()+y.size()+n].emplace_back(xidx, 0);
		graph[xidx].emplace_back(x.size()+y.size()+n, 0);
		graph[x.size()+y.size()+n].emplace_back(yidx+x.size(), 0);
		graph[yidx+x.size()].emplace_back(x.size()+y.size()+n, 0);
	}
	for(int k = 0; k<x.size(); k++){
		graph[x.size()+y.size()+N].emplace_back(k, abs(s.first - x[k]));
	}
	for(int k = 0; k<y.size(); k++){
		graph[x.size()+y.size()+N].emplace_back(x.size()+k, abs(s.second-y[k]));
	}
	for(int i = 0; i<N; i++){
		int n = i;
		graph[x.size()+y.size()+N].emplace_back(x.size()+y.size()+n, abs(arr[i].first-s.first) + abs(arr[i].second - s.second));
		graph[x.size()+y.size()+n].emplace_back(x.size()+y.size()+N+1, abs(arr[i].first-t.first) + abs(arr[i].second-t.second));
	}
	graph[x.size()+y.size()+N].emplace_back(x.size()+y.size()+N+1, abs(s.first-t.first)+abs(s.second-t.second));
	fill(dist, dist+1000000, LLONG_MAX/2);
	priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
	pq.push(make_pair(0, x.size()+y.size()+N));
	dist[x.size()+y.size()+N] = 0;
	while(pq.size()){
		auto p = pq.top();
		pq.pop();
		if(dist[p.second] < p.first){
			continue;
		}
		int n = p.second;
		//cout << n << " " << dist[n] << "\n";
		for(auto e : graph[n]){
			if(e.second < 0){
				//cout << n << " " << e.first << " " << e.second << "\n";
				return 0;
			}
			if(dist[e.first] > dist[n] + e.second){
				dist[e.first] = dist[n] + e.second;
				pq.push(make_pair(dist[e.first], e.first));
			}
		}
	}
	cout << dist[x.size()+y.size()+N+1] << "\n";
}