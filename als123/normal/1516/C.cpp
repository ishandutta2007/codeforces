#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const int N=105;
int a[N];
int n;
int check ()
{
	for (int u=1;u<=n;u++) if (a[u]%2!=0) return u;
	return -1;
}
bool f[2][2005*N];
int main()
{
	int sum=0;
	scanf("%d",&n);
	for (int u=1;u<=n;u++) 
	{
		scanf("%d",&a[u]);
	}
	while (check()==-1)
	{
		for (int u=1;u<=n;u++) a[u]/=2;
	}
	int op=0;
	memset(f,false,sizeof(f));
	f[0][0]=true;
	for (int u=1;u<=n;u++)
	{
		sum=sum+a[u];
		for (int i=sum;i>=0;i--)	f[op^1][i]=f[op][i];
		for (int i=sum;i>=a[u];i--) f[op^1][i]|=f[op][i-a[u]];
		op^=1;
	}
	if (sum%2!=0) {printf("0\n");return 0;}
	int x=check();
	//printf("%d %d %d\n",x,a[x],a[x]%2);
	if (f[op][sum/2]==true) printf("1\n%d\n",x);
	else printf("0\n"); 
	return 0;
}