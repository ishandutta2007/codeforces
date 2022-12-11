#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

// Problem : B. Graph Subset Problem
// Contest : Codeforces - Codeforces Round #684 (Div. 1)
// URL : https://codeforces.com/contest/1439/problem/B
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int T;
int N, M, K;
unordered_set<int> graph[100005];
vector<int> srch[100005];
int dgr[100005];
int qu[200005];
bool here[100005];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--){
		cin >> N >> M >> K;
		while(pq.size()){
			pq.pop();
		}
		for(int i = 1; i<=N; i++){
			graph[i].clear();
			srch[i].clear();
			dgr[i] = 0;
			here[i] = 1;
		}
		for(int i = 1; i<=M; i++){
			int a, b;
			cin >> a >> b;
			graph[a].insert(b);
			graph[b].insert(a);
			dgr[a]++;
			dgr[b]++;
			srch[a].emplace_back(b);
			srch[b].emplace_back(a);
		}
		int tot = M;
		if(2*M < 1LL*K*(K-1)){
			cout << -1 << "\n";
			continue;
		}
		int l = 1+99999, r = 99999;
		for(int i = 1; i<=N; i++){
			sort(srch[i].begin(), srch[i].end());
			if(dgr[i] < K-1){
				//qu[--l] = i;
				pq.push(make_pair(dgr[i], i));
			}
			else if(dgr[i] == K-1){
				//qu[++r] = i;
				pq.push(make_pair(dgr[i], i));
			}
		}
		bool complete = 0;
		while(pq.size()){
			//int n = qu[l++];
			int n = pq.top().second;
			pq.pop();
			if(!here[n]){
				continue;
			}
			//cout << n << endl;
			if(dgr[n] == K-1 && 2*tot >= 1LL*K*(K-1)){
				bool good= 1;
				for(int e : graph[n]){
					if(dgr[e] < K-1){
						good = 0;
						break;
					}
				}
				if(good){
					for(int e : graph[n]){
						if(!good){
							break;
						}
						for(int t : graph[n]){
							if(t != e && !binary_search(srch[e].begin(), srch[e].end(), t)){
								good = 0;
								break;
							}
						}
					}
				}
				if(good){
					vector<int> ans = {n};
					for(int e : graph[n]){
						ans.push_back(e);
					}
					cout << "2\n";
					for(int e : ans){
						cout << e << " ";
					}
					cout << "\n";
					complete = 1;
					break;
				}
			}
			for(int e : graph[n]){
				graph[e].erase(n);
				dgr[e]--;
				tot--;
				if(dgr[e] == K-1){
					//qu[--l] = e;
					pq.push(make_pair(dgr[e], e));
				}
				else if(dgr[e] == K-2){
					pq.push(make_pair(dgr[e], e));
				}
			}
			here[n] = 0;
			dgr[n] = 0;
		}
		if(complete){
			continue;
		}
		vector<int> ans;
		for(int i = 1; i<=N; i++){
			if(here[i] && dgr[i] >= K){
				ans.push_back(i);
			}
		}
		if(ans.empty()){
			cout << -1 << "\n";
			continue;
		}
		cout << "1 " << ans.size() << "\n";
		for(int n : ans){
			cout << n << " ";
		}
		cout << "\n";
	}
}