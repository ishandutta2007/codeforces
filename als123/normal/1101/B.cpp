#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
const int N=500005;
char ss[N];
int main()
{
	scanf("%s",ss+1);int n=strlen(ss+1);
	bool tf=false;
	int a=-1,b=-1;
	for (int u=1;u<=n;u++)
	{
		if (ss[u]=='[') tf=true;
		if (tf==true&&ss[u]==':')	{a=u;break;}
	}
	tf=false;
	for (int u=n;u>=1;u--)
	{
		if (ss[u]==']') tf=true;
		if (tf==true&&ss[u]==':') {b=u;break;}
	}
	if (a==-1||b==-1||a>=b)
	{
		printf("-1\n");
		return 0;
	}
	int ans=4;
	for (int i=a+1;i<b;i++)
		if (ss[i]=='|') ans++;
	printf("%d\n",ans);
	return 0;
}