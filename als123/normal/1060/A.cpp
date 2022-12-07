#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
const int N=105;
char ss[N];
int n;
int tot=0;
int main()
{
	scanf("%d",&n);
	scanf("%s",ss+1);
	for (int u=1;u<=n;u++)	tot=tot+(ss[u]=='8');
	int mx=0;
	for (int u=1;u<=n;u++)
	{
		if (u>tot) break;
		if ((n-u)<10*u) break;
		mx=u;
	}
	printf("%d\n",mx);
	return 0;
}