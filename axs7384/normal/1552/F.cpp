#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=998244353;
const int N=200005;
int n,a[N],b[N],s[N],f[N];
int ans;
inline void add(int x,int y)
{
	for (int i=x;i<=n;i+=i&(-i))
		(f[i]+=y)%=mod;
}
inline int ask(int x)
{
	int ans=0;
	for (int i=x;i;i-=i&(-i))
		(ans+=f[i])%=mod;
	return ans;
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;++i)
		scanf("%d%d%d",&a[i],&b[i],&s[i]);
	ans=a[n]+1;
	for (int i=n;i;--i)
	{
		s[i]=(s[i]+ask(i))%mod;
		// cout<<i<<' '<<s[i]<<' '<<ask(i)<<endl;
		ans=(ans+(ll)s[i]*(a[i]-b[i])%mod)%mod;
		if (s[i])
		{
			int l=1,r=i;
			while (l<=r)
			{
				int mid=(l+r)/2;
				if (a[mid]>=b[i])
					r=mid-1;
				else
					l=mid+1;
			}
			// cout<<"?"<<i<<' '<<l<<endl;
			add(l,s[i]);
		}
		// for (int i=1;i<=n;++i)
		// 	cout<<f[i]<<endl;
	}
	cout<<ans;
	return 0;
}