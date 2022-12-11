
// Problem : F. Koala and Notebook
// Contest : Codeforces - Codeforces Round #584 - Dasha Code Championship - Elimination Round (rated, open for everyone, Div. 1 + Div. 2)
// URL : https://codeforces.com/contest/1209/problem/F
// Memory Limit : 512 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<pair<int, int>> graph[15 * 100005];
int dist[15 * 100005];
long long val[15 * 100005];
int rnk[15 * 100005];
int par[15 * 100005]; 
int d[15 * 100005];
const long long MOD = 1e9+7;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	int oN = N;
	for(int i = 1; i <= M; i++){
		int a, b;
		cin >> a >> b;
		int t = i;
		vector<int> dig;
		while(t){
			dig.push_back(t%10);
			t /= 10;
		}
		reverse(dig.begin(), dig.end());
		for(int it = 0; it < 2; it++){
			int lst = a;
			for(int k = 0; k < dig.size() - 1; k++){
				graph[lst].emplace_back(++N, dig[k]);
				lst = N;
			}
			graph[lst].emplace_back(b, dig.back());
			swap(a, b);
		}
	}
	fill(dist+2, dist+1+N, INT_MAX/2);
	vector<int> qu = {1};
	while(qu.size()){
		vector<int> nqu;
		for(int n : qu){
			for(auto e : graph[n]){
				if(dist[e.first] == INT_MAX/2 || (dist[e.first] == dist[n] + 1 && make_pair(rnk[n], e.second) < make_pair(rnk[par[e.first]], d[e.first]))){
					dist[e.first] = dist[n] + 1;
					par[e.first] = n;
					d[e.first] = e.second;
					val[e.first] = (val[n] * 10 + e.second) % MOD;
					nqu.emplace_back(e.first);
				}
			}
		}
		sort(nqu.begin(), nqu.end());
		nqu.erase(unique(nqu.begin(), nqu.end()), nqu.end());
		sort(nqu.begin(), nqu.end(), [](int n, int m){
			if(rnk[par[n]] == rnk[par[m]]){
				return d[n] < d[m];
			}
			return rnk[par[n]] < rnk[par[m]];
		});
		for(int k = 1; k < nqu.size(); k++){
			if(rnk[par[nqu[k-1]]] == rnk[par[nqu[k]]]){
				rnk[nqu[k]] = rnk[nqu[k-1]] + (d[nqu[k-1]] < d[nqu[k]]);
			}
			else{
				rnk[nqu[k]] = rnk[nqu[k-1]] + (rnk[par[nqu[k-1]]] < rnk[par[nqu[k]]]);
			}
		}
		swap(qu, nqu);
	}
	for(int i = 2; i<=oN; i++){
		cout << val[i] << "\n";
	}
}