#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
const int N=105;
bool f[N][2];//i 
int n;
int a[N];
int main()
{
	scanf("%d",&n);
	for (int u=1;u<=n;u++)	scanf("%d",&a[u]);
	if (a[1]%2==0) {printf("No\n");return 0;}
	memset(f,false,sizeof(f));
	f[0][0]=true;f[1][1]=true;
	for (int u=2;u<=n;u++)
	{
		if (a[u]%2==0) continue;
		f[u][0]=f[u-1][1];f[u][1]=f[u-1][0];
		for (int i=u-2;i>=1;i-=2)// 
		{
			if (a[i]%2!=0) 
			{
				f[u][0]|=f[i-1][1];
				f[u][1]|=f[i-1][0];
			}
		}
	}
	if (f[n][1]) printf("Yes\n");
	else printf("No\n");
	return 0;
}