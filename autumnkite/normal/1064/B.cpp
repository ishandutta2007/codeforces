#include <cstdio>
#include <algorithm>
int T, a, ans;
int main(){
	scanf("%d", &T);
	while (T--){
		scanf("%d", &a), ans = 1 << 30;
		for (register int i = 0; i < 30; ++i, a >>= 1)
			if (!(a & 1)) ans >>= 1;
		printf("%d\n", ans);
	}
}