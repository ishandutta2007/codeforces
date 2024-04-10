#include <cstdio>
#include <cstring>
#define N 100005
char s[N];
int n;
int main(){
	scanf("%s", s + 1), n = strlen(s + 1);
	for (register int i = n, cnt = 0; i; --i) 
		if (s[i] == '0') ++cnt;
		else if (cnt) --cnt;
		else s[i] = '0';
	printf("%s\n", s + 1);
}