#include<bits/stdc++.h>
using namespace std; 
const int N=300005,M=998244353;
const long double PI=3.1415926535897932384626;
int n,p,i,t,f[N][4],j,ans;
char c[N];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",c+1);
		n=strlen(c+1);
		for(i=2;i<=n;++i)
			f[i][0]=f[i][1]=f[i][2]=f[i][3]=1<<30;
		f[1][3]=f[1][2]=1;
		for(i=2;i<=n;++i)
		{
			int s=0;
			if(c[i]==c[i-1])
				s|=2;
			if(c[i]==c[i-2])
				s|=1;
			for(j=0;j<4;++j)
			{
				if((s&(3^j))==0)
					f[i][j>>1]=min(f[i][j>>1],f[i-1][j]);
				f[i][(j>>1)|2]=min(f[i][(j>>1)|2],f[i-1][j]+1);
			}
		}
		printf("%d\n",min({f[n][0],f[n][1],f[n][2],f[n][3]}));
	}
}