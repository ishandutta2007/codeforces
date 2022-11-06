//zhouakngyang txdy!
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
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
const int N=3e5+9;
int odd[N],eve[N],n,a[N],ans[N];
int main()
{
	n=read();
	for(int i=1;i<=n;i++)a[i]=read(),ans[1]=max(ans[1],a[i]);
	for(int i=1;i<n;i++)eve[min(i,n-i)]=max(eve[min(i,n-i)],max(a[i],a[i+1]));
	for(int i=2;i<n;i++)odd[min(i-1,n-i)]=max(odd[min(i-1,n-i)],max(min(a[i],a[i-1]),min(a[i],a[i+1])));
	for(int i=n/2;i>=1;i--)
	{
		ans[i*2+1]=max(ans[i*2+3],odd[i]);
		ans[i*2]=max(ans[i*2+2],eve[i]);
	}
	for(int i=n;i>=1;i--)printf("%d ",ans[i]);
	return 0;
}