#include<bits/stdc++.h>
using namespace std;
int n,m,k;
double res=1;
int main(){
	scanf("%d%d%d",&n,&m,&k);
	if(m<=k){puts("1");return 0;}
	for(int i=0;i<=k;i++)res*=1.0*(m-k+i)/(n+i+1);
	printf("%lf\n",max(1-res,0.0));
	return 0;
}