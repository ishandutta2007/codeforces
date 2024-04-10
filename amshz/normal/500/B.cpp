# include <bits/stdc++.h>

using namespace std;

const int xn = 3e2+10;
bool adj[xn][xn], flag[xn][xn], mark[xn];
int a[xn], n, ans[xn];

void DFS(int v, int dx){
	mark[v] = true;
	flag[dx][v] = true;
	for (int i=0; i<n; i++){
		if (mark[i]) continue;
		if (adj[v][i]) DFS(i, dx);
	}
}

int main(){
	cin >> n;
	for (int i=0; i<n; i++) cin >> a[i];
	string sr;
	for (int i=0; i<n; i++){
		cin >> sr;
		for (int j=0; j<n; j++)
			if (sr[j] == '1') adj[i][j] = true;
	}
	for (int i=0; i<n; i++){
		DFS(i, a[i]-1);
		for (int j=0; j<n; j++) mark[j] = false;
	}
	/*
	for (int i=0; i<n; i++){
		cout << i+1 << " : ";
		for (int j=0; j<n; j++)
			if (flag[i][j]) cout << j+1 << ' ';
		cout << endl;
	}
	*/
	int p = -1;
	for (int i=0; i<n; i++) mark[i] = false;
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			if (flag[i][j] and !mark[j]){
				mark[j] = true;
				ans[j] = i+1;
				break;
			}
		}
	}
	for (int i=0; i<n; i++) cout << ans[i] << ' ';
	cout << endl;
	return 0;
}