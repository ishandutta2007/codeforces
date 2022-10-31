#include<cstdio>
using namespace std;
char s[100010];
int main(){
	int a[4],i,total=0;
	for(i=0;i<4;i++) scanf("%d",&a[i]);
	scanf("%s",s);
	for(i=0;s[i];i++) total+=a[s[i]-'1'];
	printf("%d\n",total);
	return 0;
}