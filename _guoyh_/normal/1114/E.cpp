# include <climits>
# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int MAXN = 1000051;
int n, cnt;
bool check(int x){
	printf("> %d\n", x - 1);
	fflush(stdout);
	int u;
	scanf("%d", &u);
	return u;
}
int gcd(int x, int y){
	if (y == 0) return x;
	else return gcd(y, x % y);
}
int main(){
	scanf("%d", &n);
	int lft = 1, rgt = 1e9, ans = 0;
	while (lft <= rgt){
		int mid = (lft + rgt) >> 1;
		cnt++;
		if (check(mid)){
			ans = mid;
			lft = mid + 1;
		} else rgt = mid - 1;
	}
	int g = 0;
	for (int i = 1; i <= 60 - cnt; i++){
		int pos = (rand() * RAND_MAX + rand()) % n + 1;
		printf("? %d\n", pos);
		fflush(stdout);
		int u;
		scanf("%d", &u);
		g = gcd(g, ans - u);
	}
	printf("! %d %d\n", ans - (n - 1) * g, g);
	return 0;
}