#include<bits/stdc++.h>
using namespace std;
const int N=1005,P=998244353,iv2=(P+1)/2;
int n,m,x,y;double f[N],a[N],b[N];
int main()
{
	scanf("%d%d%d%d",&n,&m,&x,&y);
	if(m==1){printf("%d\n",(n-x)*2);return 0;}
	for(int i=n-1;i>=x;i--)
	{
		a[1]=0.5;b[1]=(f[1]+3)/2;
		for(int j=2;j<m;j++){a[j]=1/(3-a[j-1]);b[j]=(b[j-1]+f[j]+4)*a[j];}
		f[m]=(b[m-1]+f[m]+3)/(2-a[m-1]);
		for(int j=m-1;j;j--)f[j]=a[j]*f[j+1]+b[j];
	}
	printf("%.6f\n",f[y]);return 0;
}