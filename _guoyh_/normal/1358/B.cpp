# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int NR = 200051;
int t, n;
int a[NR], c[NR];
int lowbit(int x){
	return x & (-x);
}
void add(int x){
	for (int i = x; i < NR; i += lowbit(i)){
		c[i]++;
	}
}
int getsum(int x){
	int ans = 0;
	for (int i = x; i; i -= lowbit(i)) ans += c[i];
	return ans;
}
bool check(int x){
	return getsum(x - 1) + 1 >= x;
}
int main(){
	scanf("%d", &t);
	while (t--){
		memset(c, 0, sizeof(c));
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", a + i);
		for (int i = 1; i <= n; i++) add(a[i]);
		// for (int i = 1; i <= 6; i++) printf("%d ", c[i]);
		int ans = 1;
		for (int i = n + 1; i >= 1; i--){
			if (check(i)){
				ans = i;
				break;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}