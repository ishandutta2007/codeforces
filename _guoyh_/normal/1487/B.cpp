# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
int t, n, k;
int main(){
	scanf("%d", &t);
	while (t--){
		scanf("%d%d", &n, &k);
		k--;
		int ans = 0;
		if (n & 1) ans = (k + k / (n / 2)) % n + 1;
		else ans = k % n + 1;
		printf("%d\n", ans);
	}
	return 0;
}