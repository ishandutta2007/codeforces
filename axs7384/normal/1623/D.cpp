#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=1e9+7;
inline int ksm(int x,int y)
{
	int ans=1;
	for (;y;y/=2,x=(ll)x*x%mod)
		if (y&1)
			ans=(ll)ans*x%mod;
	return ans;
}
int t;
int n,m,x,y,px,py,p;
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d%d%d%d%d%d%d",&n,&m,&x,&y,&px,&py,&p);
		p=(ll)p*ksm(100,mod-2)%mod;
		int _p=1-p+mod;
		int dx=1,dy=1;
		int q=1;
		int C=(n-1)*(m-1)/__gcd(n-1,m-1)*2;
		for (int i=1;i<=C;++i)
		{
			// cout<<x<<' '<<y<<endl;
			if (x==px||y==py)
			{
				q=(ll)q*_p%mod;
				// cout<<"???"<<endl;
			}
			// cout<<i<<' '<<q<<endl;
			// (ti+=q)%=mod;
			if (x+dx<=0||x+dx>n)
				dx=-dx;
			if (y+dy<=0||y+dy>m)
				dy=-dy;
			x+=dx;
			y+=dy;
		}
		// cout<<C<<' '<<q<<' '<<ti<<endl;
		// int bl=(ll)q*ksm(1-q+mod,mod-2)%mod;
		// int ans=((ll)ti*ksm(1-q+mod,mod-2)%mod+(ll)bl*C%mod)%mod;
		int ans=0;
		int xs=ksm(1-q+mod,mod-2);
		// cout<<q<<' '<<xs<<endl;
		q=1;
		for (int i=1;i<=C;++i)
		{
			if (x==px||y==py)
				q=(ll)q*_p%mod;
			(ans+=(ll)q*xs%mod)%=mod;
			// cout<<i<<' '<<q<<endl;
			// (ti+=q)%=mod;
			if (x+dx<=0||x+dx>n)
				dx=-dx;
			if (y+dy<=0||y+dy>m)
				dy=-dy;
			x+=dx;
			y+=dy;
		}
		cout<<ans<<endl;
	}
	return 0;
}