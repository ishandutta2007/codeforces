#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=20005;
int n,m;
int a[12];
int t;
char s[12][N];
int f[N],p[N],final[N];
inline bool cmp(int x,int y)
{
	return p[x]<p[y];
}
signed main()
{
	scanf("%lld",&t);
	while (t--)
	{
		scanf("%lld%lld",&n,&m);
		for (int i=0;i<n;++i)
			scanf("%lld",&a[i]);
		int ans=-1;
		for (int i=0;i<n;++i)
			scanf("%s",s[i]+1);
		for (int i=1;i<=m;++i)
			f[i]=i;
		for (int i=0;i<(1<<n);++i)
		{
			int sum=0;
			for (int j=1;j<=m;++j)
				p[j]=0;
			for (int j=0;j<n;++j)
				if (i&(1<<j))
					sum-=a[j];
				else
					sum+=a[j];
			// if (i==15)
			// 	cout<<"???"<<sum<<endl;
			for (int j=0;j<n;++j)
				for (int k=1;k<=m;++k)
					if (s[j][k]=='1')
					{
						if (i&(1<<j))
							p[k]++;
						else
							p[k]--;
					}
			sort(f+1,f+1+m,cmp);
			// cout<<"??"<<p[1]<<' '<<p[2]<<endl;
			// cout<<f[1]<<' '<<f[2]<<endl;
			for (int j=1;j<=m;++j)
				sum+=j*p[f[j]];
			// if (sum==19)
			// 	cout<<"!"<<i<<endl;
			if (sum>ans)
			{
				for (int j=1;j<=m;++j)
					final[f[j]]=j;
				ans=sum;
			}
		}
		// cout<<ans<<endl;
		for (int i=1;i<=m;++i)
			printf("%lld ",final[i]);
		puts("");
	}
	return 0;
}