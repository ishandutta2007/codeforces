
// Problem : F. Almost Permutation
// Contest : Codeforces - Educational Codeforces Round 29
// URL : https://codeforces.com/problemset/problem/863/F
// Memory Limit : 512 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, M;
int u[100005], v[100005], f[100005], c[100005];
int idx;
vector<int> graph[10005];
int par[10005];
int dist[10005];
int flw[10005];
bool inq[10005];
int mx[55], mn[55];
const int oo = INT_MAX/2;

void addedge(int a, int b, int _f, int _c){
	u[idx] = a, v[idx] = b;
	f[idx] = _f;
	c[idx] = _c;
	graph[a].push_back(idx);
	idx++;
	u[idx] = b, v[idx] = a;
	c[idx] = -_c;
	graph[b].push_back(idx);
	idx++;
}

bool spfa(){
	fill(dist, dist+2*N+2, oo);
	fill(par, par+2*N+2, -1);
	fill(inq, inq+2*N+2, 0);
	flw[0] = oo;
	dist[0] = 0;
	queue<int> qu;
	qu.push(0);
	while(qu.size()){
		int n = qu.front();
		qu.pop();
		inq[n] = 0;
		for(int e : graph[n]){
			if(f[e] && dist[v[e]] > dist[n] + c[e]){
				dist[v[e]] = dist[n] + c[e];
				flw[v[e]] = min(flw[n], f[e]);
				par[v[e]] = e;
				if(!inq[v[e]]){
					inq[v[e]] = 1;
					qu.push(v[e]);
				}
			}
		}
	}
	return par[2*N+1] != -1;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	fill(mx, mx+N+1, N);
	while(M--){
		int c, l, r, v;
		cin >> c >> l >> r >> v;
		for(int i = l; i<=r; i++){
			if(c == 1){
				mn[i] = max(mn[i], v);
			}
			else{
				mx[i] = min(mx[i], v);
			}
		}
	}
	for(int i = 1; i<=N; i++){
		for(int j = 1; j<=N; j++){
			addedge(0, i, 1, 2*j-1);
		}
		for(int n = 1; n<=N; n++){
			if(mn[n] <= i && mx[n] >= i){
				addedge(i, n+N,1, 0);
			}
		}
		addedge(i+N, 2*N+1, 1, 0);
	}
	int tot = 0;
	long long ans = 0;
	while(spfa()){
		tot += flw[2*N+1];
		int n = par[2*N+1];
		while(n != -1){
			ans += flw[2*N+1]*c[n];
			f[n] -= flw[2*N+1];
			f[n^1] += flw[2*N+1];
			n = par[u[n]];
		}
	}
	cout << (tot != N ? -1 : ans) << "\n";
}