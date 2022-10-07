#include <cstdio>
int n, x;
int main(){
	scanf("%d", &n);
	for (register int i = 1; i <= n; ++i){
		scanf("%d", &x);
		if (x) return printf("HARD"), 0;
	}
	printf("EASY");
}