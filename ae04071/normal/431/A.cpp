#include <cstdio>
#include <cstring>
int a[4];
char str[100001];

int main() {
	for(int i=0;i<4;i++) scanf("%d",a+i);
	scanf("%s",str);

	int sum=0;
	int n=strlen(str);
	for(int i=0;i<n;i++) sum+=a[str[i]-'1'];
	printf("%d\n",sum);
	return 0;
}