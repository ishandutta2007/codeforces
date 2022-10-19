#include<bits/stdc++.h>
using namespace std;
int t,n,m;
const int N=1000005;
int a[N],f[N],g[N];
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d%d",&n,&m);
		for (int i=1;i<=n;++i)
			// a[i]=i;
			scanf("%d",&a[i]);
		sort(a+1,a+1+n);
		for (int i=0;i<=m;++i)
			f[i]=g[i]=0;
		for (int i=1;i<=n;++i)
			if (a[i]!=a[i-1])
			{
				f[a[i]]=1;
			}
		for (int i=1;i<=m;++i)
			g[i]=g[i-1]+f[i];
		bool b=true;
		/*for (int i=1;i<=n;++i)
			if (a[i]!=a[i-1])
			{
				for (int j=1;j*j<=a[i];++j)
				{
					if (f[j])
					{
						if (!f[a[i]/j])
							b=false;
					}
					else
					{
						int l=(a[i]/(j+1))+1;
						int r=(a[i]/j);
						if (g[r]-g[l-1]!=0)
							b=false;
					}
				}
				if (!b)
					break;
			}
		puts(b?"Yes":"No");*/
		if (!f[1])
			b=false;
		for (int i=2;i<=m;++i)
			if (f[i])
				for (int j=1;j<=m/i;++j)
					if (!f[j]&&(g[min(m,(j+1)*i-1)]-g[j*i-1]!=0))
						b=false;
		puts(b?"Yes":"No");
	}
}