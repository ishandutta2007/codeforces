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
const int N=3e5+9;
int n,p,k,a[N],ans;
map<int,int> mp;
map<int,int> kp;
inline void solve1()
{
	for(int i=1;i<=n;i++)a[i]=read(),mp[a[i]]++;
	ans=ans+mp[0]*(mp[0]-1);
	for(int i=1;i<=n;i++)
		if(a[i]!=0)
		{
			ans=ans+mp[p-a[i]];
		//	cout<<p-a[i]<<" "<<mp[p-a[i]]<<endl;
		}
	ans=ans/2;
	for(int i=1;i<=n;i++)
		if(a[i]!=0)
		{
			ans+=kp[p-a[i]*a[i]%p];
			kp[a[i]*a[i]%p]++;
		}
	cout<<ans<<endl;
}
signed main()
{
	n=read();p=read(),k=read();
	if(k==0)
	{
		solve1();return 0;
	}
	for(int i=1;i<=n;i++)a[i]=read(),ans=ans-mp[a[i]],mp[a[i]]++;
	ans=ans+(mp[0]*(mp[0]-1)/2);
	for(int i=1;i<=n;i++)
		if(a[i]!=0)
		{
			int pp=a[i]*a[i]%p*a[i]%p*a[i]%p;
			pp=pp-a[i]*k%p;pp=pp+p;pp=pp%p;
			ans+=kp[pp];
		//	cout<<a[i]<<" "<<pp<<endl;
			kp[pp]++;
		}
	for(int i=1;i<=n;i++)
		if(a[i]*a[i]%p*a[i]%p==k)ans+=mp[0];
	cout<<ans<<endl;
	return 0;
}