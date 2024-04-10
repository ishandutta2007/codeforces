# include <bits/stdc++.h>

using namespace std;

const int xn = 1e2+10;
vector <int> adj[xn];
bool mark[xn];
int x[xn], y[xn];

void DFS(int v){
	mark[v] = true;
	for (int i=0; i<adj[v].size(); i++){
		int u = adj[v][i];
		if (mark[u]) continue;
		DFS(u);
	}
}

int main(){
	int n;
	cin >> n;
	int q, w, e;
	int t = 0;
	for (int i=0; i<n; i++){
		cin >> q >> w >> e;
		//if (e > w) swap(w, e);
		if (q == 1){
			for (int j=0; j<t; j++){
				if ((x[j] < w and w < y[j]) or (x[j] < e and e < y[j])) adj[t].push_back(j);
				if ((w < x[j] and x[j] < e) or (w < y[j] and y[j] < e)) adj[j].push_back(t);
			}
			x[t] = w, y[t] = e;
			t++;
		}
		if (q == 2){
			for (int j=0; j<t; j++) mark[j] = false;
			DFS(w-1);
			if (mark[e-1]) cout << "YES" << endl;
			else cout << "NO" << endl;
		}
	}
}