#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int N=100005;
char ss[N];
int n;
int main()
{
	scanf("%s",ss+1);
	n=strlen(ss+1);
	int cnt=0;
	for (int u=1;u<=n;u++)
		if (ss[u]=='1')
			cnt++;
	bool tf=false;
	for (int u=1;u<=n;u++)
	{
		if (ss[u]=='1') continue;
		if (ss[u]=='2'&&tf==false)
		{
			for (int i=1;i<=cnt;i++)
				printf("1");
			tf=true;
		}
		printf("%c",ss[u]);
	}
	if (tf==false)
	{
		for (int i=1;i<=cnt;i++)
		printf("1");
	}
	return 0;
}