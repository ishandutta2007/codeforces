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
int n;
char a[209];
int k[209],res1,res2,now,cnt,ans[1009];
int main()
{
	n=read();cin>>a;
	for(int i=n;i>=1;i--)
		if(a[i-1]=='B')k[i]=0,res1++;
		else k[i]=1,res2++;
	if(n%2==0&&res1%2==1)
	{
		puts("-1");return 0;
	}
	if(res2%2==1&&n%2==1)now=1;
	for(int i=1;i<=n;i++)
	{
		if(k[i]!=now)ans[++cnt]=i,k[i]=k[i]^1,k[i+1]=k[i+1]^1;
	}
	printf("%d\n",cnt);
	for(int i=1;i<=cnt;i++)printf("%d ",ans[i]);
	return 0;
}