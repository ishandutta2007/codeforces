#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int t,n,cnt,tot;
int vis[N],f[N],a[N],g[N],p[N],q[N];
int ans;
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		// puts("?");
		scanf("%d",&n);
		for (int i=1;i<=n;++i)
			scanf("%d",&a[i]);
		for (int i=1;i<=n;++i)
			vis[i]=f[i]=0;
		ans=0;
		for (int i=1;i<=n;++i)
			if (!vis[a[i]])
			{
				vis[a[i]]=1;
				f[i]=a[i];
				++ans;
			}
		cnt=0;
		for (int i=1;i<=n;++i)
			if (!vis[i])
			{
				// cout<<"?"<<i<<endl;
				p[++cnt]=i;
			}
		cnt=0;
		for (int i=1;i<=n;++i)
			if (!f[i])
				q[++cnt]=i;
		tot=0;
		// cout<<p[1]<<' '<<p[2]<<' '<<p[3]<<endl;
		if (cnt==1)
		{
			f[q[1]]=p[1];
			if (p[1]==q[1])
			{
				// puts("!");
				// --ans;
				for (int i=1;i<=n;++i)
					if (f[i]==a[q[1]])
					{
						swap(f[i],f[q[1]]);
						break;
					}
				if (f[q[1]]==q[1])
				{
					--ans;
					for (int i=1;i<=n;++i)
						if (f[i]!=q[1])
						{
							swap(f[i],f[q[1]]);
							break;
						}
				}
			}
		}
		else
		{
			// puts("!");
			for (int i=1;i<=cnt;++i)
			{
				// cout<<p[i]<<' '<<q[i]<<endl;
				f[q[i]]=p[i];
				if (q[i]==p[i])
				{
					// cout<<"?"<<i<<endl;
					g[++tot]=i;
				}
			}
			// cout<<"!"<<tot<<endl;
			if (tot>1)
			{
				for (int i=1;i<tot;++i)
					swap(f[q[g[i]]],f[q[g[i+1]]]);
			}
			else
			{
				if (tot==1)
				{
					for (int i=1;i<=cnt;++i)
						if (i!=g[1])
						{
							// cout<<"?"<<i<<endl;
							swap(f[q[i]],f[q[g[1]]]);
							break;
						}
				}
			}
		}
		printf("%d\n",ans);
		// for (int i=1;i<=n;++i)
		// {
		// 	if (f[i]==i)
		// 		// puts("???");
		// 	if (f[i]==a[i])
		// 		--ans;
		// }
		// if (ans!=0)
		// 	puts("!!!");
		for (int i=1;i<=n;++i)
			printf("%d%c",f[i],i==n?'\n':' ');
	}
	return 0;
}