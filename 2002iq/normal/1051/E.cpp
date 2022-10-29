#include <iostream>
using namespace std;
#define mod 998244353
int z[2][2000005],dp[1000005],cum[1000005];
void Z(int idx,string t,string pat)
{
	string s=pat+'$'+t;
	int l,r;
	l=r=0;
	z[idx][0]=s.size();
	for (int i=1;i<s.size();i++)
	{
		if (i>r)
		{
			l=r=i;
			while (r<s.size() && s[r]==s[r-l])
			r++;
			z[idx][i]=r-l;
			r--;
		}
		else
		{
			int k=i-l;
			if (z[idx][k]<r-i+1)
			z[idx][i]=z[idx][k];
			else
			{
				l=i;
				while (r<s.size() && s[r]==s[r-l])
				r++;
				z[idx][i]=r-l;
				r--;
			}
		}
	}
}
int main()
{
	string a,l,r;
	cin >> a >> l >> r;
	Z(0,a,l);
	Z(1,a,r);
	dp[0]=1;
	cum[0]=(a[0]!='0');
	for (int i=1;i<=a.size();i++)
	{
		int mx=max(i-(int)l.size()-1,-1),mn=min(max(i-(int)r.size(),-1),mx);
		if (mx!=-1)
		dp[i]=cum[mx];
		if (mn!=-1)
		dp[i]=(dp[i]-cum[mn]+mod)%mod;
		bool b1,b2;
		if (i>=l.size())
		{
			int idx=z[0][i+1];
			b1=(idx==l.size() || a[i-l.size()+idx]>l[idx]);
			b1&=(a[i-l.size()]!='0' || l.size()==1);
		}
		if (i>=r.size())
		{
			int idx=z[1][i+1];
			b2=(idx==r.size() || a[i-r.size()+idx]<r[idx]);
			b2&=(a[i-r.size()]!='0' || r.size()==1);
		}
		if (i>=l.size())
		{
			if (l.size()==r.size())
			{
				if (b1 && b2)
				dp[i]=(dp[i]+dp[i-l.size()])%mod;
			}
			else if (b1)
			dp[i]=(dp[i]+dp[i-l.size()])%mod;
		}
		if (i>=r.size() && b2 && l.size()!=r.size())
		dp[i]=(dp[i]+dp[i-r.size()])%mod;
		cum[i]=cum[i-1];
		if (i!=a.size() && a[i]!='0')
		cum[i]=(cum[i]+dp[i])%mod;
	}
	cout << dp[a.size()];
}