#include<cstdio>
 //
int main(){
	register int t,a,b,c;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&a,&b,&c);
		if(a+b>c-2&&b+c>a-2&&c+a>b-2)puts("Yes");
		else puts("No");
	}
	return 0;
}