#include <cstdio>
int t, n;
int main(){
	scanf("%d", &t);
	while (t--){
		scanf("%d", &n);
		if (n & 1) printf("%d\n", (n - 3) / 2 + 1);
		else printf("%d\n", n >> 1);
	}
}