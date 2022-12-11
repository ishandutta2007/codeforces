
// Problem : F2. The Hidden Pair (Hard Version)
// Contest : Codeforces - Codeforces Round #651 (Div. 2)
// URL : https://codeforces.com/contest/1370/problem/F2
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)
#include <bits/stdc++.h>

using namespace std;

pair<int, int> query(vector<int> v){
	cout << "? " << v.size() << " ";
	for(int n : v){
		cout << n << " ";
	}
	cout << endl;
	int a, b;
	cin >> a >> b;
	return make_pair(a, b);
}

/*
vector<int> graph[1005];
int ord[1005], dep[1005], sz[1005], hvy[1005], hvysz[1005], t;

void dfs(int n, bool b = 0, int p = 0){
	sz[n] = 1;
	for(int e : graph[n]){
		if(e != p){
			if(b && e == hvy[n]){
				continue;
			}
			dep[e] = dep[n] + 1;
			dfs(e, 0, n);
			sz[n] += sz[e];
		}
	}
	ord[++t] = n;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		int N;
		cin >> N;
		vector<int> qu;
		int centroidcnt = 0;
		for(int i = 1; i<=1000; i++){
			graph[i].clear();
			hvy[i] = 0, sz[i] = 0, hvysz[i] = 0, ord[i] = 0;
		}
		for(int i = 1; i<N; i++){
			int a, b;
			cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		if(N == 2){
			cout << "! " << 1 << " " << 2 << endl;
			return 0;
		}
		t = 0;
		dfs(1);
		int C = 0;
		for(int i =1 ; i<=N; i++){
			hvysz[i] = hvy[i] = 0;
			for(int e : graph[i]){
				if(sz[e] > sz[i]){
					if(hvysz[i] < N-sz[i]){
						hvysz[i] = N-sz[i];
						hvy[i] = e;
					}
				}
				else{
					if(hvysz[i] < sz[e]){
						hvysz[i] = sz[e];
						hvy[i] = e;
					}
				}
			}
			if(2*hvysz[i] >= N){
				qu.push_back(i);
			}
			else{
				C = i;
			}
			qu.push_back(i);
		}
		auto p = query(qu);
		int d = p.second;
		t = 0;
		dfs(p.first, 1);
		//cout << p.first << endl;
		int l = 1, r = t, u = p.first;
		qu.clear();
		while(l <= r){
			int mid = l+r>>1;
			for(int i = l; i<=mid; i++){
				qu.push_back(ord[i]);
			}
			auto q = query(qu);
			if(q.second == d){
				u = q.first;
				r = mid - 1;
			}
			else{
				l = mid + 1;
			}
			qu.clear();
		}
		dep[u] = 0;
		t = 0;
		dfs(u);
		qu.clear();
		if(C){
			qu.push_back(C);
		}
		for(int i = 1; i<=N; i++){
			if(dep[i] == d){
				qu.push_back(i);
			}
		}
		sort(qu.begin(), qu.end());
		qu.erase(unique(qu.begin(), qu.end()), qu.end());
		auto k = query(qu);
		if(k.second != d){
			assert(0);
			int out1 = 0, out2 = 0;
			for(int i = 1; i<=N; i++){
				if(hvysz[i]*2 <= N){
					if(out1){
						out2 = i;
					}
					else{
						out1 = i;
					}
				}
			}
			cout << "! " << out1 << " " << out2 << endl;
		}
		else{
			cout << "! " << u << " " << k.first << endl;
		}
		string s;
		cin >> s;
		assert(s == "Correct");
	}	
}
*/

int T, N;
vector<int> graph[1005];
int dep[1005], par[1005];
bool bad[1005];

void dfs(int n){
	for(int e : graph[n]){
		if(e != par[n]){
			par[e] = n;
			dep[e] = dep[n] + 1;
			dfs(e);
		}
	}
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--){
		cin >> N;
		vector<int> qu;
		for(int i = 1; i<=N; i++){
			graph[i].clear();
			qu.push_back(i);
			dep[i] = 0;
			par[i] = 0;
			bad[i] = 0;
		}
		for(int i = 1; i<N; i++){
			int a, b;
			cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		auto p = query(qu);
		dfs(p.first);
		int k = p.second;
		int l = (p.second+1)/2, r = p.second, u = 0, d = 0;
		r = min(r, *max_element(dep+1, dep+1+N));
		while(l <= r){
			qu.clear();
			int mid = l+r>>1;
			//cout << l << " " << r << endl;
			for(int i = 1; i <=N; i++){
				if(dep[i] == mid){
					qu.push_back(i);
				}
			}
			auto q = query(qu);
			if(q.second == k){
				u = q.first;
				d = mid;
				l = mid + 1;
			}
			else{
				r = mid - 1;
			}
		}
		qu.clear();
		int x = u;
		while(x != p.first){
			bad[x] = 1;
			x = par[x];
		}
		if(k == 0){
			cout << "! " << u << " " << u << endl;
		}
		else{
			for(int i = 1; i<=N; i++){
				if(dep[i] == k-d && !bad[i]){
					qu.push_back(i);
				}
			}
			int v = query(qu).first;
			cout << "! " << u << " " << v << endl;
		}
		string s;
		cin >> s;
		assert(s == "Correct");
	}
}