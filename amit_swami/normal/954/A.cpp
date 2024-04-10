#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
const int N=100+10;

int n,cnt,k;
char s[N];

int main()
{
	scanf("%d%s",&n,s+1);
	int i;
	for(i=1,k=-1;i<=n;++i)
	{
		if(s[i]=='U')
		{
			if(k==1)
			{
				k=-1;
				++cnt;
			}
			else if(k==-1)
			{
				k=0;
			}
		}
		else if(s[i]=='R')
		{
			if(k==0)
			{
				k=-1;
				++cnt;
			}
			else if(k==-1)
			{
				k=1;
			}
		}
	}
	printf("%d",n-cnt);
	return 0;
}