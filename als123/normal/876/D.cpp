#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
const int N=300005;
int n;
bool ok[N];//  
int lalal;
int main()
{
	memset(ok,false,sizeof(ok));
	scanf("%d",&n);printf("1 ");
	lalal=n+1;
	for (int u=1;u<=n;u++)
	{
		int x;
		scanf("%d",&x);
		ok[x]=true;
		while (lalal>1)
		{
			if (ok[lalal-1]==false) break;
			lalal--;
		}
		int shen=n-lalal+1;
		printf(" %d",max(1,u-shen+1)); 
	}
	return 0;
}