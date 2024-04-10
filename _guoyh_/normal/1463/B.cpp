# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int MAXN = 55;
int t, n;
int a[MAXN];
int work(int x){
	for (int i = 30; i >= 0; i--) if ((x >> i) & 1) return (1 << i);
}
int main(){
	scanf("%d", &t);
	while (t--){
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", a + i);
		for (int i = 1; i <= n; i++){
			printf("%d ", work(a[i]));
		}
		putchar('\n');
	}
	return 0;
}