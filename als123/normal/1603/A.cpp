#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const int N=100005;
int a[N];
int n;
int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		int n;
		scanf("%d",&n);
		bool tf=true;
		for (int u=1;u<=n;u++)
		{
			int x;
			scanf("%d",&x);
			if (u<=1000)
			{
				bool l=false;
				for (int i=2;i<=u+1;i++) 
				if (x%i!=0) l=true;
				tf&=l;
			}
		}
		if (tf) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}