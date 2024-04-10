#include<bits/stdc++.h>

const int maxn=1e3+7;

using namespace std;

int n;
int a[maxn],vis[maxn];
map <int,vector<int> > mp;
vector<int> now;

void solve (vector<int> A,vector<int> B)
{
	printf("YES\n");
	int len=A.size();
	for (int i=0;i<A.size();i++) vis[A[i]]=1;
	for (int i=0;i<B.size();i++)
	{
		if (vis[B[i]]) vis[B[i]]=0,len--;
		          else vis[B[i]]=2;
	}
	int l=1,r=1,ls=0,now;
	while (vis[l]!=1) l++;
	now=a[l];
	for (int i=1;i<=len;i++)
	{
		while (vis[l]!=1) l++;
		printf("%d ",a[l]-ls);
		ls=a[l]-ls;
		while (vis[r]!=2) r++;
		if (i==len) printf("%d",a[r]-ls); 
		       else printf("%d ",a[r]-ls);
		ls=a[r]-ls;
		l++,r++;
	}
	for (int i=1;i<=n;i++)
	{
		if (!vis[i]) printf(" %d",a[i]-now);
	}
}

void dfs(int x,int y,int sum)
{
	if (y==n/2)
	{
		if (mp.find(sum)==mp.end()) mp[sum]=now;
		else {solve(now,mp[sum]);exit(0);}
		return ;
	}
	if (x>n) return ;
	for (int u=x;u<=n;u++)
	{
		now.push_back(u);
		dfs(u+1,y+1,sum+a[u]);
		now.pop_back();
	}
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++)
	{
		for (int j=i+1;j<=n;j++)
		{
			if (a[i]==a[j])
			{
				printf("YES\n");
				printf("%d %d",0,a[i]);
				for (int k=1;k<=n;k++)
				{
					if ((i!=k) && (j!=k)) printf(" %d",a[k]);
				}
				return 0;
			}
		}
	}
	
	if (n==2) printf("NO\n");
	if (n>=3)
	{
		int num1=0,num2=0;
		for (int i=1;i<=n;i++)
		{
			if (a[i]%2==0) num1++;
			          else num2++;
		}
		if (num2==n)
		{
			dfs(1,0,0);
			printf("NO\n");
		}
		else
		{
			if (num1>=3)
			{
				int x=0,y=0,z=0;
				for (int i=1;i<=n;i++)
				{
					if (a[i]%2==0)
					{
						if (!x) x=i;
						else if (!y) y=i;
						else z=i;
					}
				}
				int p=(a[x]+a[y]+a[z])/2-a[x];
				printf("YES\n");
				printf("%d %d %d",(a[x]+a[y]+a[z])/2-a[x],(a[x]+a[y]+a[z])/2-a[y],(a[x]+a[y]+a[z])/2-a[z]);
				for (int i=1;i<=n;i++)
				{
					if ((i!=x) && (i!=y) && (i!=z)) printf(" %d",a[i]-p);
				}
				return 0;
			}
			else
			{
				if (num2>=2)
				{
					int x=0,y=0,z=0;
					for (int i=1;i<=n;i++)
					{
						if (a[i]%2==0)
						{
							if (!x) x=i;
						}
						else
						{
							if (!y) y=i;
							else z=i;
						}
					}
					int p=(a[x]+a[y]+a[z])/2-a[x];
					printf("YES\n");
					printf("%d %d %d",(a[x]+a[y]+a[z])/2-a[x],(a[x]+a[y]+a[z])/2-a[y],(a[x]+a[y]+a[z])/2-a[z]);
					for (int i=1;i<=n;i++)
					{
						if ((i!=x) && (i!=y) && (i!=z)) printf(" %d",a[i]-p);
					}
					return 0;
				}
				else printf("NO\n");
			}
		}
	}
}