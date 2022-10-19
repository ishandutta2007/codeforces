#include<bits/stdc++.h>
using namespace std;
int d[10000005],s[10000005],tt1[1000005],tt2[1000005],tot=0;
void print()
{
	s[1]=1;
	for(int i=1;i<=10000000;i++)
	{
		if(!s[i])d[++tot]=i;
		for(int j=1;j<=tot&&i*d[j]<=10000000;j++)
		{
			s[i*d[j]]=1;
			if(i%d[j]==0)break;
		}
	}
}
int main()
{
	print();
	int t;
	cin>>t;
	while(t--)
	{
		long long x,y;
		cin>>x>>y;
		if(x%y)
		{
			cout<<x<<endl;
			continue;
		}
		memset(tt2,0,sizeof(tt2));
		memset(tt1,0,sizeof(tt1));
		long long xx=x,yy=y;
		for(int i=1;d[i]*d[i]<=y;i++)
			while(yy%d[i]==0)yy/=d[i],tt2[i]++;
		for(int i=1;d[i]*d[i]<=y;i++)
			while(xx%d[i]==0)xx/=d[i],tt1[i]++;
		long long ans=0;
		if(yy!=1)ans=x;
		while(yy!=1&&ans%yy==0)ans/=yy;
		for(int i=1;d[i]*d[i]<=y;i++)
		{
			if(!tt2[i])continue;
			long long aa=1;
			for(int j=1;j<=tt1[i]-tt2[i]+1;j++)aa*=d[i];
			ans=max(ans,x/aa);
		}
		cout<<ans<<endl;
	}
	return 0;
}