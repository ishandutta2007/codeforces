//zhouakngyang txdy!
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include<bits/stdc++.h>
#define Macesuted cout<<"kawaii"<<endl
#define MatrixCascade cout<<"npsl"<<endl
#define Karry5307 cout<<"nmsl"<<endl
using namespace std;
//#define int long long
inline int read()
{
	int sum=0,nega=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')nega=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')sum=sum*10+ch-'0',ch=getchar();
	return sum*nega;
}
const int N=2e5+9;
int n,s,ans,now,cnt,tot;
int p[N],a[N];
int main()
{
	n=read(),s=read();
	for(int i=1;i<=n;i++)a[i]=read();
	if(a[s]!=0)ans++,a[s]=0;tot=1;
	for(int i=1;i<=n;i++)cnt+=(a[i]==0);cnt--;ans+=cnt,tot+=cnt;
	for(int i=1;i<=n;i++)p[a[i]]++;
	for(int i=1;i<=n&&tot<n;i++)
	{
		tot+=p[i];
		if(p[i]==0)
		{
			if(cnt!=0)cnt--;
			else ans++,tot++;
		}
	}
	cout<<ans<<endl;
	return 0;
}