
// Problem : E. Rectangle Painting 2
// Contest : Codeforces - Codeforces Round #576 (Div. 1)
// URL : https://codeforces.com/problemset/problem/1198/E
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int K, N, M, X, Y;
int mnx[55], mny[55], mxx[55], mxy[55];
vector<int> graph[100000];
int u[100000];
int v[100000];
int f[100000];
int lvl[100000];
int ptr[100000];
vector<int> cmpx, cmpy;

void addedge(int _u, int _v, int _f){
	u[M] = _u;
	v[M] = _v;
	f[M] = _f;
	graph[_u].push_back(M);
	M++;
	u[M] = _v;
	v[M] = _u;
	graph[_v].push_back(M);
	M++;
}

bool bfs(){
	fill(lvl, lvl+X+Y+2, INT_MAX/2);
	fill(ptr, ptr+X+Y+2, 0);
	queue<int> qu;
	lvl[0] = 0;
	qu.push(0);
	while(qu.size()){
		int n = qu.front();
		//cout << n << endl;
		qu.pop();
		for(int e : graph[n]){
			//cout << f[e] << " " << v[e] << " " << lvl[v[e]] << endl;
			if(f[e] && lvl[v[e]] > lvl[n] + 1){
				lvl[v[e]] = lvl[n] + 1;
				qu.push(v[e]);
				//cout << v[e] << endl;
			}
		}
	}
	//cout << lvl[X+Y+1] << endl;
	return lvl[X+Y+1] != INT_MAX/2;
}

int dfs(int n, int flw){
	//cout << n << endl;
	if(n == X+Y+1){
		return flw;
	}
	for(int &i = ptr[n]; i<graph[n].size(); i++){
		int e = graph[n][i];
		if(f[e] && lvl[v[e]] == lvl[n] + 1){
			int k = dfs(v[e], min(f[e], flw));
			if(k){
				f[e] -= k;
				f[e^1] += k;
				return k;
			}
		}
	}
	return 0;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> K >> N;
	if(!N){
		cout << 0 << "\n";
		return 0;
	}
	cmpx.push_back(0);
	cmpy.push_back(0);
	for(int i = 1; i<=N; i++){
		cin >> mnx[i] >> mny[i] >> mxx[i] >> mxy[i];
		mnx[i]--;
		mny[i]--;
		cmpx.push_back(mnx[i]);
		cmpy.push_back(mny[i]);
		cmpx.push_back(mxx[i]);
		cmpy.push_back(mxy[i]);
	}
	sort(cmpx.begin(), cmpx.end());
	cmpx.erase(unique(cmpx.begin(), cmpx.end()), cmpx.end());
	sort(cmpy.begin(), cmpy.end());
	cmpy.erase(unique(cmpy.begin(), cmpy.end()), cmpy.end());
	X = cmpx.size();
	Y = cmpy.size();
	for(int i = 1; i<cmpx.size(); i++){
		for(int j = 1; j<cmpy.size(); j++){
			for(int k = 1; k<=N; k++){
				if(cmpx[i-1] >= mnx[k] && cmpx[i] <= mxx[k] && cmpy[j-1] >= mny[k] && cmpy[j] <= mxy[k]){
					addedge(i, X+j, INT_MAX/2);
					break;
				}
			}
		}
	}
	for(int i = 1; i<cmpx.size(); i++){
		addedge(0, i, cmpx[i] - cmpx[i-1]);
	}
	for(int j = 1; j<cmpy.size(); j++){
		addedge(j+X, X+Y+1, cmpy[j] - cmpy[j-1]);
	}
	int flw = 0;
	while(bfs()){
		while(1){
			int k = dfs(0, INT_MAX/2);
			//cout << k << endl;
			if(!k){
				break;
			}	
			flw += k;
		}
	}
	cout << flw << "\n";
}