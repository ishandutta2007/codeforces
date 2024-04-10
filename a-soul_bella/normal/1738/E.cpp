#include <bits/stdc++.h>
#define mod 998244353
#define int long long
using namespace std;
int a[1000005],l[1000005],r[1000005],dp[1000005];
int jc[1000005],inv[1000005],jcinv[1000005];
int C(int x,int y)
{
	return jc[x]*jcinv[y]%mod*jcinv[x-y]%mod;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	jc[0]=jcinv[0]=inv[1]=jcinv[1]=jc[1]=1;
	for(int i=2;i<=1000000;i++)
	{
		jc[i]=jc[i-1]*i%mod;
		inv[i]=(mod-mod/i)*inv[mod%i]%mod;
		jcinv[i]=jcinv[i-1]*inv[i]%mod;
	}
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		for(int i=1;i<=n;i++) l[i]=r[i]=dp[i]=0;
		for(int i=1;i<=n;i++)
			cin >> a[i];
		int s1=0,s2=0,L=n+1,R=n+1;
		for(int i=1;i<=n;i++)
		{
			s1+=a[i];
			while(R>i&&s2<s1) s2+=a[R-1],--R;
			L=min(L,R);
			while(L>i+1&&a[L-1]==0) --L;
			L=max(L,i+1);
			if(s1==s2) l[i]=L,r[i]=R;
		}
		for(int i=1;i<=n;i++) r[i]=min(r[i],n),l[i]=max(l[i],i+1);
		dp[0]=1;
		int s=0,ns=1;
		if(!a[1])
		{
			int cl=0,cr=r[1]-l[1]+1;
			for(int i=1;i<=n;i++)
			{
				if(a[i]) break;
				++cl;
			}
			if(cl==n)
			{
				int ans=1;
				for(int i=1;i<n;i++) ans=ans*2%mod;
				cout << ans << "\n";
				continue;
			}
			for(int j=1;j<=min(cl,cr);j++)
				dp[0]=(dp[0]+C(cl,j)*C(cr,j))%mod;
		}
		ns=dp[0];
		for(int i=1;i<=n;i++)
		{
			s+=a[i];
			if(l[i]>r[i]) continue;
			if(s*2>s1) break;
			if(s*2==s1)
			{
				int q=ns*2%mod;
				for(int j=i+1;j<=n;j++)
				{
					if(a[j]==0) q*=2,q%=mod;
					else break;
				}
				q-=ns;
				dp[i]=(q)%mod;
				ns=(ns+dp[i])%mod;
				break;
			}
			if(!a[i]) continue;
			int cl=1;
			for(int j=i+1;j<=n;j++)
			{
				if(a[j]==0) ++cl;
				else break;
			}
			int cr=r[i]-l[i]+1;
			for(int j=1;j<=min(cl,cr);j++)
			{
				dp[i]=(dp[i]+C(cl,j)*C(cr,j)%mod*ns)%mod;
			}
			ns=(ns+dp[i])%mod;
		}
	//	cout << dp[1] << "*\n";
	/*	for(int i=1;i<=n;i++)
			cout << l[i] << " " << r[i] << "\n";
		cout << "\n";*/
		cout << (ns%mod+mod)%mod << "\n";
	}
	return 0;
}
/*
2
3
1 0 1
5
1 0 2 0 3
*/
/*
4

*/