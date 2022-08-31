#include<stdio.h>
__int64 a,c;
int main(){
	scanf("%I64d",&a);
	while(a>0){if(a%10==4||a%10==7)c++;a/=10;}
	if(c==4||c==7)printf("YES\n");
	else printf("NO\n");
}