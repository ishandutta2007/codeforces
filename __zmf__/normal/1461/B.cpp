#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int sum=0,nega=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')nega=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')sum=sum*10+ch-'0',ch=getchar();
	return sum*nega;
}
int taxi,n,m,s[509][509],cnt,l,r;
char a[509][509];
long long ans;
int main()
{
	taxi=read();
	for(int ttt=1;ttt<=taxi;ttt++)
	{
		ans=0;
		n=read(),m=read();
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				cin>>a[i][j];
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(a[i][j]=='*')s[i][j]=s[i][j-1]+1;
				else s[i][j]=s[i][j-1];
			//	cout<<s[i][j]<<" ";
			}
			//cout<<endl;
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
			{
				if(a[i][j]=='*')
				{
					cnt=1;l=j-1,r=j+1;
					while(l>0&&r<=m&&i+cnt<=n)
					{
					//	cout<<i<<" "<<cnt<<" "<<s[i+cnt][r]<<" "<<s[i+cnt][l-1]<<endl;
						if(s[i+cnt][r]-s[i+cnt][l-1]==r-l+1)cnt++,l--,r++;
						else break;
					}
					//cout<<i<<" "<<cnt<<" "<<j<<endl;
					ans+=cnt;
				}
			}
		cout<<ans<<endl;
	}
	return 0;
}