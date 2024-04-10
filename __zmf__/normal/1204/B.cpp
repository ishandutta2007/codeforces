//zhouakngyang txdy!
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include<bits/stdc++.h>
#define Macesuted cout<<"kawaii"<<endl
#define MatrixCascade cout<<"npsl"<<endl
#define Karry5307 cout<<"nmsl"<<endl
using namespace std;
#define int long long
inline int read()
{
	int sum=0,nega=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')nega=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')sum=sum*10+ch-'0',ch=getchar();
	return sum*nega;
}
int n,l,r,ans=1,res=1;
signed main()
{
	n=read(),l=read(),r=read();
	for(int i=1;i<=l;i++)ans=ans*2;ans--;ans+=(n-l);
	cout<<ans<<" ";
	ans=1;
	for(int i=1;i<=r;i++)ans=ans*2,res=res*2;ans--;res=res/2;ans=(ans+res*(n-r));
	cout<<ans<<endl;
	return 0;
}