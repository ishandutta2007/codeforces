#include<bits/stdc++.h>
using namespace std;
int a[405][405],h[405],d[405],s[405];
char c[1005];
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,m;
		cin>>n>>m;
		for(int i=1;i<=n;i++)
		{
			scanf("%s",c+1);
			for(int j=1;j<=m;j++)a[i][j]=c[j]-'0';
		}
		int ans=n*m;
		for(int l=1;l<n;l++)
		{
			for(int i=1;i<=m;i++)
			{
				h[i]=(a[l][i]==0)+(a[l+1][i]==0);
				d[i]=0;
			}
			for(int r=l+2;r<=n;r++)
			{
				for(int i=1;i<=m;i++)
				{
					h[i]-=(a[r-1][i]==0);
					h[i]+=(a[r-1][i]==1);
					h[i]+=(a[r][i]==0);
					d[i]+=(a[r-1][i]==0);
					s[i]=s[i-1]+h[i];
				}
				if(r-l<4)continue;
				int aa=1e8;
				for(int i=4;i<=m;i++)
				{
					aa=min(aa,d[i-3]-s[i-3]);
					ans=min(ans,d[i]+s[i-1]+aa);
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}