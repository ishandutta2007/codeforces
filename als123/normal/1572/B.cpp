#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const int N=200005;
int n;
int a[N];
vector<int> ans;
void solve (int l,int r)
{
	if (l>r) return ;
	for (int u=l;u<r;u+=2) ans.push_back(u);
	for (int u=r-4;u>=l;u-=2) ans.push_back(u);
}

int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		int sum=0;
		for (int u=1;u<=n;u++) 	
		{
			scanf("%d",&a[u]);
			sum^=a[u];
		}
		if (sum==1) 	{printf("NO\n");continue;}
		ans.clear();
		if (n&1)	solve(1,n);
		else
		{
			int sum=0;
			for (int u=1;u<=n;u+=2)
			{
				sum^=a[u];sum^=a[u-1];
				if (sum==0) {solve(1,u);solve(u+1,n);break;}
			}
		}
		if (ans.size()==0) printf("NO\n");
		else
		{
			printf("YES\n");
			int siz=ans.size();
			printf("%d\n",siz);
			for (int u=0;u<siz;u++) printf("%d ",ans[u]);
			printf("\n");
		}
	}
	return 0;
}