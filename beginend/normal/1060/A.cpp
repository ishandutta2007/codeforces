#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

const int N=105;

int n;
char s[N];

int main()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	int x=0,y=0;
	for (int i=1;i<=n;i++)
		if (s[i]=='8') x++;
	int ans=0;
	while (ans+1<=x&&(ans+1)*10<=n-ans-1) ans++;
	printf("%d\n",ans);
	return 0;
}