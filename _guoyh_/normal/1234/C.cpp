# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
int q, n;
int a[200051][3];
bool work(int x, int y){
	if (x == n + 1) return y == 2;
	if (a[x][y] <= 2) return work(x + 1, y);
	if (a[x][3 - y] <= 2) return false;
	return work(x + 1, 3 - y);
}
int main(){
	scanf("%d", &q);
	while (q--){
		scanf("%d", &n);
		for (int i = 1; i <= 2; i++)
			for (int j = 1; j <= n; j++){
				scanf("%1d", a[j] + i);
			}
		if (work(1, 1)) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}