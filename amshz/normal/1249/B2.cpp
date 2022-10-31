# include <bits/stdc++.h>

using namespace std;

const int xn = 2e5+10;
int a[xn];
int ans[xn];
int door[xn];
bool mark[xn];

void DFS(int v, int k){
	if (mark[v]) return ;
	mark[v] = true;
	door[k]++;
	ans[v] = k;
	int u = a[v]-1;
	if (!mark[u]) DFS(u, k);
	//DFS(u, k);
}

int main(){
	int q;
	cin >> q;
	while (q--){
		int n;
		cin >> n;
		for (int i=0; i<n; i++) cin >> a[i];
		for (int i=0; i<n; i++) mark[i] = false, door[i] = 0, ans[i] = 0;
		int k = 0;
		for (int i=0; i<n; i++){
			if (!mark[i]) DFS(i, k), k++;
		}
		//cout << "ans : " << endl;
		for (int i=0; i<n; i++){
			cout << door[ans[i]] << ' ';
		}
		cout << endl;
	}
}