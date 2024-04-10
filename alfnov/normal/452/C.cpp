#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	double ans=0;
	for(int j=1;j<=n;++j){
		double he=j*j;
		for(int i=m;i>=m-j+1;--i)he=he*i/(m-i+1);
		for(int i=m*(n-1);i>=m*(n-1)-n+j+1;--i)he=he*i/(m*(n-1)-i+1);
		for(int i=m*n;i>=(m-1)*n+1;--i)he=he/i*(m*n-i+1);
		ans+=he;
	}
	ans/=n;
	printf("%.8f\n",ans);
	return 0;
}