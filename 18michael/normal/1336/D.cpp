#include<bits/stdc++.h>
using namespace std;
int n,t=0;
int c[102],X[102],Y[102];
inline void query(int x)
{
	printf("+ %d\n",x),fflush(stdout),++t,scanf("%d %d",&X[t],&Y[t]);
}
int main()
{
	scanf("%d%d%d",&n,&X[0],&Y[0]);
	if(n>4)
	{
		for(int i=3;i<=n-2;++i)query(i);
		query(n),query(n-1),query(n),query(2);
		for(int i=t;i;--i)X[i]-=X[i-1],Y[i]-=Y[i-1];
		for(c[n-2]=Y[n-1]-Y[n-3]-1,c[n-1]=Y[n-3]/(c[n-2]+1),c[n]=max((int)(-1+sqrt(1+8*X[n-1]))/2-1,0);c[n]*(c[n]+1)/2<X[n-1];++c[n]);
		for(;c[n]*(c[n]+1)/2>X[n-1];--c[n]);
		c[n-3]=Y[n-2]/(c[n-2]+1)-1-c[n]-(n-3>2);
		for(int i=n-4;i>1;--i)c[i]=(Y[i]-(c[i+1]+1)*c[i+3]-c[i+3]*c[i+4])/(c[i+1]+(i+1>2))-(i>2);
		c[1]=Y[n]/(c[3]+1)-c[4]-1;
	}
	else
	{
		query(2),query(4),query(3),query(4);
		for(int i=t;i;--i)X[i]-=X[i-1],Y[i]-=Y[i-1];
		for(c[2]=Y[4]-Y[2]-1,c[3]=Y[2]/(c[2]+1),c[4]=max((int)(-1+sqrt(1+8*X[4]))/2-1,0);c[4]*(c[4]+1)/2<X[4];++c[4]);
		for(;c[4]*(c[4]+1)/2>X[4];--c[4]);
		c[1]=Y[3]/(c[2]+1)-c[4]-1;
	}
	printf("! ");
	for(int i=1;i<=n;++i)printf("%d%c",c[i],i==n? '\n':' ');
	return 0&fflush(stdout);
}