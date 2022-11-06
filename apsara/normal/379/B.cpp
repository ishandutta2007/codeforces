#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef long long LL;
const int V=310;
int a[V],n;
int main()
{
	while(~scanf("%d",&n))
	{
		for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<a[i];j++)
			{
				printf("P");
				if(i==0)printf("RL");
				else printf("LR");
			}
			if(i!=n-1)printf("R");
		}
		puts("");
	}
}