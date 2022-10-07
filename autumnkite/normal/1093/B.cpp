#include <cstdio>
#include <cstring>
#include <algorithm>
int t, n;
char a[1005];
int main(){
	scanf("%d", &t);
	while (t--){
		scanf("%s", a + 1), n = strlen(a + 1);
		std :: sort(a + 1, a + 1 + n);
		if (a[1] == a[n]) printf("-1\n");
		else printf("%s\n", a + 1);
	}
}