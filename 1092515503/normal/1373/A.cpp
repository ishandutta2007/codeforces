#include<bits/stdc++.h>
using namespace std;
int T,a,b,c;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&a,&b,&c);
		if(a<c)printf("1 ");
		else printf("-1 ");
		if(1ll*a*b>c)printf("%d\n",b);
		else puts("-1");
	}
	return 0;
}