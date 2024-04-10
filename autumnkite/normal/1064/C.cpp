#include <cstdio>
#include <cstring>
#include <algorithm>
int n;
char c[1000005];
int main(){
	scanf("%d%s", &n, c);
	std :: sort(c, c + n);
	printf("%s", c);
}