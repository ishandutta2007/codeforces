# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
int t, a, b;
int gcd(int x, int y){
	if (y == 0) return x;
	return gcd(y, x % y);
}
int main(){
	scanf("%d", &t);
	while (t--){
		scanf("%d%d", &a, &b);
		if (gcd(a, b) == 1) printf("Finite\n");
		else printf("Infinite\n");
	}
	return 0;
}