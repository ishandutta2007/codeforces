#include<bits/stdc++.h>
using namespace std;
const int N=2000005;
vector<int> a[N],na[N];
vector<int> b[N],nb[N];
int nn;
int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		nn=0;
		a[0].clear();b[0].clear();
		int n;
		scanf("%d",&n);
		for (int u=1;u<=n;u++)
		{
			int x;
			scanf("%d",&x);
			a[0].push_back(x);
		}
		for (int u=1;u<=n;u++)
		{
			int x;
			scanf("%d",&x);
			b[0].push_back(x);
		}
		int ans=0;
		for (int u=30;u>=0;u--)
		{
			bool tf=true;
			for (int i=0;i<=nn;i++)
			{
				int siz=a[i].size();
				int x=0;
				for (int j=0;j<siz;j++)
				{
					if (a[i][j]&(1<<u)) x++;
					if (!(b[i][j]&(1<<u))) x--; 
				}
				if (x!=0) 	{tf=false;break;}
			}
			if (!tf) continue;
			ans|=(1<<u);
			int n1=0;
			for (int i=0;i<=nn;i++)
			{
				na[n1].clear();na[n1+1].clear();
				nb[n1].clear();nb[n1+1].clear();
				int siz=a[i].size();
				for (int j=0;j<siz;j++)
				{
					if (a[i][j]&(1<<u)) 	na[n1].push_back(a[i][j]);
					else 					na[n1+1].push_back(a[i][j]);
					if (!(b[i][j]&(1<<u)))  nb[n1].push_back(b[i][j]);
					else 					nb[n1+1].push_back(b[i][j]);
				}
				n1+=2;
			}
			nn=-1;
			for (int u=0;u<n1;u++)
			{
				if (!na[u].empty())
				{
					nn++;
					a[nn]=na[u];
					b[nn]=nb[u];
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}