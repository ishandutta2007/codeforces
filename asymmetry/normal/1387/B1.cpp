#include <bits/stdc++.h>

using namespace std;

int n, a, b, l, odp;
int odw[100001];
int dp[100001];
int sko[100001];
vector <int> v[100001];

void dfs(int x)
{
	odw[x]=l;
	dp[x]=1;
	for(int i:v[x])
	{
		if(odw[i]<l)
		{
			dfs(i);
			if(dp[i] && dp[x])
			{
				dp[x]=0;
				sko[x]=i;
				sko[i]=x;
				odp-=2;
			}
		}
	}
}

int main()
{
	scanf("%d", &n);
	odp=n<<1;
	for(int i=1; i<n; ++i)
	{
		scanf("%d%d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	++l;
	dfs(1);
	++l;
	for(int i=1; i<=n; ++i)
	{
		if(sko[i] && odw[i]<l)
		{
			odw[i]=l;
			odw[sko[i]]=l;
			a=0;
			for(int j:v[i])
			{
				if(!sko[j])
				{
					a=i;
					break;
				}
			}
			if(!a)
			{
				for(int j:v[sko[i]])
				{
					if(!sko[j])
					{
						a=sko[i];
						break;
					}
				}
			}
			if(!a)
			{
				continue;
			}
			for(int j:v[a])
			{
				if(!sko[j])
				{
					sko[j]=sko[a];
					sko[a]=j;
				}
			}
		}
	}
	printf("%d\n", odp);
	for(int i=1; i<=n; ++i)
	{
		printf("%d ", sko[i]);
	}
	return 0;
}