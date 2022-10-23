# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
int t;
int n;
int gcd(int x, int y){
	if (y == 0) return x;
	else return gcd(y, x % y);
}
int main(){
	scanf("%d", &t);
	while (t--){
		scanf("%d", &n);
		int g = gcd(180, n);
		int ans = 180 / g;
		if (n / g == 180 / g - 1) ans *= 2;
		printf("%d\n", ans);
	}
	return 0;
}