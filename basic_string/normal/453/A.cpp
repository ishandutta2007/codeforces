#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m,i;
	long double s=0,x,y=0;
	scanf("%d%d",&m,&n);
	for(i=1;i<=m;++i)x=pow((long double)i/m,n),s+=i*(x-y),y=x;
	printf("%.9lf",(double)s);
	return 0;
}