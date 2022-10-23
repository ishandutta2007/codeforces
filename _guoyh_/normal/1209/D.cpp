# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
int n, k, ans;
int p[100051];
int find(int x){
	if (p[x] == x) return x;
	else return p[x] = find(p[x]);
}
int main(){
//	freopen("1.in", "r", stdin);
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) p[i] = i;
	for (int i = 1; i <= k; i++){
		int x, y;
		scanf("%d%d", &x, &y);
		if (find(x) == find(y)) continue;
		p[find(x)] = find(y);
		ans++;
	}
	printf("%d\n", k - ans);
	return 0;
}