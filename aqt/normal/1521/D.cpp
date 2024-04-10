
// Problem : D. Nastia Plays with a Tree
// Contest : Codeforces - Codeforces Round #720 (Div. 2)
// URL : https://codeforces.com/contest/1521/problem/D
// Memory Limit : 256 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int T;
int N;
vector<int> graph[100005];
vector<int> ngraph[100005];
pair<int, int> good[100005];
pair<int, int> leaf[100005];
int dsu[100005];
vector<pair<pair<int, int>, pair<int, int>>> out;
int par[100005];
bool vis[100005];
vector<pair<int, int>> bad;

int getrt(int n){
	//cout << n << endl;
	return dsu[n] = (dsu[n] == n ? n : getrt(dsu[n]));
}

void dfs2(int n, int p){
	vis[n] = 1;
	for(int e : ngraph[n]){
		if(e != p){
			dsu[getrt(e)] = getrt(n);
			dfs2(e, n);
		}
	}
	if(ngraph[n].size() <= 1){
		leaf[getrt(n)].second = leaf[getrt(n)].first;
		leaf[getrt(n)].first = n;
	}
}

bool dfs1(int n){
	for(int e : graph[n]){
		if(e != par[n]){
			par[e] =n;
			int k = dfs1(e);
			if(k == 1){
				bad.emplace_back(n ,e);
			}
			else if(good[n].second){
				bad.emplace_back(n, e);
			}
			else{
				good[n].second = good[n].first;
				good[n].first = e;
			}
		}
	}	
	return good[n].second;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--){
		cin >> N;
		for(int i = 1; i <= N; i++){
			graph[i].clear();
			ngraph[i].clear();
			good[i] = make_pair(0, 0);
			leaf[i] = make_pair(i, 0);
			vis[i] = 0;
			dsu[i] = i;
		}
		for(int i = 1; i < N; i++){
			int a, b;
			cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		dfs1(1);
		for(int n =1 ; n <=N; n++){
			if(good[n].first != n && good[n].first){
				ngraph[n].push_back(good[n].first);
				ngraph[good[n].first].push_back(n);
			}
			if(good[n].second != n && good[n].second){
				ngraph[n].push_back(good[n].second);
				ngraph[good[n].second].push_back(n);
			}
		}
		for(int i = 1; i <= N; i++){
			if(!vis[i]){
				dfs2(i, 0);
			}
		}
		for(auto e : bad){
			int c1 = getrt(e.first), c2 = getrt(e.second);
			out.emplace_back(e, make_pair(leaf[c1].first, leaf[c2].second));
			leaf[c1].first = leaf[c2].first;
			dsu[c2] = c1;
		}
		cout << out.size() << "\n";
		for(auto o : out){
			cout << o.first.first << " " << o.first.second << " " << o.second.first << " " << o.second.second << "\n";
		}
		out.clear();
		bad.clear();
	}
}