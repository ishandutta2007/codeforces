# include <vector>
# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
int n, m, cnt, tmp;
int r[100050];
int p[100050];
int num[4];
vector <int> g[100050];
int find(int x){
	if (p[x] == x) return x;
	else return p[x] = find(p[x]);
}
int main(){
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) p[i] = i;
	for (int i = 1; i <= m; i++){
		int a, b;
		scanf("%d%d", &a, &b);
		g[a].push_back(b);
		g[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) sort(g[i].begin(), g[i].end());
	for (int i = 1; i <= n; i++){
		int sz = g[i].size();
		int la = 0;
		for (int j = 0; j < sz; j++){
			if (g[i][j] - la > 1) break;
			la = g[i][j];
		}
		p[find(i)] = find(la + 1);
	}
	for (int i = 1; i <= n; i++){
		int sz = g[i].size();
		for (int j = 0; j < sz; j++){
			if (find(g[i][j]) == find(i)){
				printf("-1\n");
				return 0;
			}
		}
	}
	for (int i = 1; i <= n; i++)
		if (p[i] == i)
			r[i] = ++cnt;
	if (cnt != 3){
		printf("-1\n");
		return 0;
	}
	for (int i = 1; i <= n; i++){
		r[i] = r[find(i)];
		num[r[i]]++;
	}
	for (int i = 1; i <= n; i++){
		int sz = g[i].size();
		if (sz != num[1] + num[2] + num[3] - num[r[i]]){
			printf("-1\n");
			return 0;
		}
	}
	for (int i = 1; i <= n; i++)
		printf("%d ", r[i]);
	return 0;
}