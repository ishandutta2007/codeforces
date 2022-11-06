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
int n,cnt[109],k,x;
int main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		k=read();
		for(int j=1;j<=k;j++)x=read(),cnt[x]++;
	}
	for(int i=1;i<=100;i++)
		if(cnt[i]==n)
		{
			cout<<i<<" ";
		}
	return 0;
}