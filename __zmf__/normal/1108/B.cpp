//zhouakngyang txdy!
#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read()
{
	int sum=0,nega=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')nega=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')sum=sum*10+ch-'0',ch=getchar();
	return sum*nega;
}
int n,a[130],maxn;
inline bool cmp(int xx,int yy)
{
	return xx>yy;
}
signed main()
{
	n=read();
	for(int i=1;i<=n;i++)a[i]=read(),maxn=max(maxn,a[i]);
	sort(a+1,a+n+1,cmp);
	cout<<maxn<<" ";
	for(int i=1;i<=n;i++)
		if(maxn%a[i]!=0)
		{
			cout<<a[i]<<endl;return 0;
		}
	for(int i=1;i<=n;i++)
		if(a[i]==a[i+1])
		{
			cout<<a[i]<<endl;
			return 0;
		}
	cout<<1<<endl;
	return 0;
}