# include <bits/stdc++.h>
using namespace std;
const int MAXN = 505;
int n, m;
int w[MAXN], p[MAXN];
bool flag[MAXN];
int getval(){
	cout << "? ";
	for (int i = 1; i <= m; i++) cout << flag[i];
	cout << '\n';
	cout.flush();
	int ans = 0;
	cin >> ans;
	return ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= m; i++){
		flag[i] = true;
		w[i] = getval();
		flag[i] = false;
		p[i] = i;
	}
	sort(p + 1, p + m + 1, [&](int u, int v){
		return w[u] < w[v];
	});
	int lst = 0;
	for (int i = 1; i <= m; i++){
		int j = p[i];
		flag[j] = true;
		int nw = getval();
		if (nw - lst != w[j]) flag[j] = false;
		else lst = nw;
	}
	cout << "! " << lst << '\n';
	cout.flush();
	return 0;
}