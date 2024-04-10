# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
int n, k, ans;
int f[261][6551];
int main(){
	memset(f, ~0x3f, sizeof(f));
	scanf("%d%d", &n, &k);
	f[0][0] = 0;
	for (int i = 1; i <= n; i++){
		int a = 0, b = 0;
		ll x;
		scanf("%lld", &x);
		while (!(x & 1)){
			a++;
			x /= 2;
		}
		while (x % 5 == 0){
			b++;
			x /= 5;
		}
		for (int l = k; l >= 1; l--){
			for (int j = 5510; j >= b; j--){
				f[l][j] = max(f[l][j], f[l - 1][j - b] + a);
				ans = max(ans, min(f[l][j], j));
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}