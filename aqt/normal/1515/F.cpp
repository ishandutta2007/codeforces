#include <bits/stdc++.h>

using namespace std;

int N, M, X;
vector<pair<int, int>> graph[300005];
long long val[300005];
int dsu[300005];

int getrt(int n){
	return dsu[n] = (dsu[n] == n ? n : getrt(dsu[n]));
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M >> X;
	priority_queue<pair<long long, int>> pq;
	for(int i = 1; i <= N; i++){
		cin >> val[i];
		dsu[i] = i;
		pq.push(make_pair(val[i], i));
	}
	for(int i = 1; i <= M; i++){
		int a, b;
		cin >> a >> b;
		graph[a].emplace_back(b, i);
		graph[b].emplace_back(a, i);
	}
	vector<int> ans;
	while(pq.size()){
		auto p = pq.top();
		pq.pop();
		if(p.first != val[getrt(p.second)]){
			continue;
		}
		int n = p.second;
		while(graph[n].size()){
			auto e = graph[n].back();
			graph[n].pop_back();
			if(getrt(e.first) != getrt(n) && val[getrt(e.first)] + val[getrt(n)] >= X){
				int p = getrt(e.first);
				val[getrt(n)] += val[getrt(e.first)] - X;
				dsu[getrt(e.first)] = getrt(n);
				if(graph[p].size() > graph[getrt(n)].size()){
					swap(graph[p], graph[getrt(n)]);
				}
				for(auto f : graph[p]){
					graph[getrt(n)].push_back(f);
				}
				pq.push(make_pair(val[getrt(n)], getrt(n)));
				ans.emplace_back(e.second);
				break;
			}
		}
	}
	if(ans.size() != N-1){
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";
	for(int n : ans){
		cout << n << "\n";
	}
}