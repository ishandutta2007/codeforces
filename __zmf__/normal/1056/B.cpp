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
int n,m;
long long ans=0;
signed main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
		{
			if((i*i+j*j)%m==0)
				ans=ans+((n-i+m)/m)*((n-j+m)/m);
		}
	cout<<ans<<endl;
	return 0;
}