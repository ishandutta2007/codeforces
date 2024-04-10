#include <cstdio>
#include <algorithm>
int T, n, s, t;
int main(){
	scanf("%d", &T);
	while (T--){
		scanf("%d%d%d", &n, &s, &t);
		printf("%d\n", std :: max(n - s, n - t) + 1);
	}
}