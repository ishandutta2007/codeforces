#include <cstdio>
#include <vector>
int n, m;
std :: vector<int> p[105];
int main(){
	scanf("%d%d", &n, &m);
	for (register int i = 1, x, y; i <= m; ++i)
		scanf("%d%d", &x, &y), p[x].push_back(i), p[y].push_back(i);
	for (register int i = 1; i <= n; ++i){
		if (!p[i].size()) ++m, p[i].push_back(m);
		printf("%d\n", p[i].size());
		for (register int j = 0; j < p[i].size(); ++j) printf("%d %d\n", i, p[i][j]);
	}
}