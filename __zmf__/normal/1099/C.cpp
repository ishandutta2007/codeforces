//zhouakngyang txdy!
#include<bits/stdc++.h>
using namespace std;
//#define int long long
inline int read()
{
	int sum=0,nega=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')nega=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')sum=sum*10+ch-'0',ch=getchar();
	return sum*nega;
}
int n,k,del,cnt,pp;
char a[209],p,ans[209];
int main()
{
	cin>>a;n=strlen(a);cin>>k;p=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]>='a'&&a[i]<='z')cnt++;
		if(a[i+1]=='*')p=a[i],del++;
		if(a[i+1]=='?')del++;
	}
	if(cnt>=k)
	{
		if(k+del<cnt)puts("Impossible");
		else
		{
			del=cnt-k;
			for(int i=0;i<n;i++)
			{
				if(a[i+1]=='*'&&del>0)del--;
				else if(a[i+1]=='?'&&del>0)del--;
				else if(a[i]>='a'&&a[i]<='z')cout<<a[i];
			}
		}
		return 0;
	}
	else
	{
		if(p==0)
		{
			puts("Impossible");return 0;
		}
		int flag=0;
		for(int i=0;i<n;i++)
			if(a[i]>='a'&&a[i]<='z')
			{
				cout<<a[i];
				if(a[i+1]=='*'&&flag==0)
				{
					for(int j=1;j<=k-cnt;j++)cout<<a[i];
					flag=1;
				}
			}
		return 0;
	}
	return 0;
}