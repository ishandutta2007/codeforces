# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int MAXN = 105;
int t, n;
int gcd(int x, int y){
	if (y == 0) return x;
	return gcd(y, x % y);
}
int main(){
	scanf("%d", &t);
	while (t--){
		scanf("%d", &n);
		for (int i = 1; i <= n; i++){
			for (int j = i + 1; j <= n; j++){
				if ((j - i) * 2 == n) printf("0 ");
				else if ((j - i) * 2 > n) printf("1 ");
				else printf("-1 ");
			}
		}
		putchar('\n');
	}
	return 0;
}