#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m,a,b,c,d;
	scanf("%d%d",&n,&m);
	scanf("%d%d%d%d",&a,&b,&c,&d);
	if(n==4||m<n+1) puts("-1");
	else{
		printf("%d %d",a,c);
		for(int i=1;i<=n;i++) if(i!=a&&i!=b&&i!=c&&i!=d) printf(" %d",i);
		printf(" %d %d\n",d,b);
		printf("%d %d",c,a);
		for(int i=1;i<=n;i++) if(i!=a&&i!=b&&i!=c&&i!=d) printf(" %d",i);
		printf(" %d %d\n",b,d);
	}
	return 0;
}