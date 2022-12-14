#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 1e5 + 10;
const int maxl = 30;

int newint = 2;
int lc[maxn * maxl], rc[maxn * maxl];

int dfs(int v, int h = 30){
	if (h == 0)
		return 0 ;
	if (lc[v] == 0)
		return dfs(rc[v], h - 1);
	if (rc[v] == 0)
		return dfs(lc[v], h - 1);
	return min(dfs(lc[v], h - 1), dfs(rc[v], h - 1)) + (1 << (h - 1));
}

void add(int x){
	int now = 1;
	for (int i = 29; i >= 0; i--){
		if (x & (1 << i)){
			if (rc[now] == 0)
				rc[now] = newint ++;
			now = rc[now];
		}
		else{
			if (lc[now] == 0)
				lc[now] = newint ++;
			now = lc[now];
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		int x;
		cin >> x;
		add(x);
	}
	cout << dfs(1) << endl;
}