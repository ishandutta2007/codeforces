
// Problem : C. Fetch the Treasure
// Contest : Codeforces - Codeforces Round #185 (Div. 1)
// URL : https://codeforces.com/contest/311/problem/C
// Memory Limit : 256 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

long long H;
int N, M, K;
long long dist[10005];
priority_queue<pair<long long, int>> lst[10005];
long long val[100005];
vector<long long> moves;
set<pair<long long, int>> st;
priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> H >> N >> M >> K;
	for(int i = 1; i <= N; i++){
		long long p;
		cin >> p >> val[i];
		p--;
		lst[p%K].push(make_pair(p/K, i));
	}	
	moves.push_back(K);
	fill(dist+1, dist+K, LLONG_MAX/2);
	while(lst[0].size()){
		int n = lst[0].top().second;
		st.insert(make_pair(val[n], -n));
		lst[0].pop();
	}
	while(M--){
		int cmd;
		cin >> cmd;
		//cout << cmd << endl;
		if(cmd == 1){
			long long mm;
			cin >> mm;
			moves.push_back(mm);
			fill(dist+1, dist+K, LLONG_MAX/2);
			pq.push(make_pair(0LL, 0));
			while(pq.size()){
				auto p = pq.top();
				pq.pop();
				int n = p.second;
				if(p.first > dist[n]){
					continue;
				}
				for(long long m : moves){
					if(dist[(m + n)%K] > dist[n] + m/K + ((n + m%K) >= K)){
						dist[(m + n)%K] = dist[n] + m/K + ((n + m%K) >= K);
						pq.push(make_pair(dist[(m + n)%K], (m + n)%K));
					}
				}
			}
			for(int k = 0; k < K; k++){
				//cout << dist[k] << "\n";
				while(lst[k].size() && lst[k].top().first >= dist[k]){
					int n = lst[k].top().second;
					st.insert(make_pair(val[n], -n));
					lst[k].pop();
				}
			}
		}
		else if(cmd == 2){
			int n, v;
			cin >> n >> v;
			//n = clmb(n);
			//cout << "n: " << n << endl;
			bool wasin = 0;
			if(st.count(make_pair(val[n], -n))){
				st.erase(make_pair(val[n], -n));
				wasin = 1;
			}
			val[n] -= v;
			if(wasin){
				st.insert(make_pair(val[n], -n));
			}
		}
		else{
			if(st.empty()){
				cout << 0 << "\n";
				continue;
			}
			cout << (*st.rbegin()).first << "\n";
			st.erase(--st.end());
		}
	}
}