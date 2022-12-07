#include<cstdio>
#include<cstring>
const int N=100005;
int n;
int a[N];
int in[N],TT;
int ans[N];
int get (int u)
{
	TT++;
	int ans=1,cnt=0;
	for (int i=1;i<=n;i++)
	{
		if (in[a[i]]!=TT)
		{
			if (cnt<u)
			{
				cnt++;
				in[a[i]]=TT;
			}
			else
			{
				TT++;
				ans++;
				cnt=1;
				in[a[i]]=TT;
			}
		}
	}
	return ans;
}
void solve (int l,int r)
{
	if (l>r) return ;
	int cntl=get(l);
	int cntr=get(r);
	if (cntl==cntr)
	{
		for (int u=l;u<=r;u++)
			ans[u]=cntl;
		return ;
	}
	ans[l]=cntl;ans[r]=cntr;
	int mid=(l+r)>>1;
	solve(l+1,mid);
	solve(mid+1,r-1);
}
int main()
{
	scanf("%d",&n);
	for (int u=1;u<=n;u++)	scanf("%d",&a[u]);
	solve(1,n);
	for (int u=1;u<=n;u++)
		printf("%d ",ans[u]);
	return 0;
}