#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1000005;
int n,a[N],b[N];ll s;
inline ll gt(ll l,ll r,ll p,ll x,ll n)
{
	ll t1=0,t2=0,t3=0;
	if(l<=p)t1=min(p-l+1,r-l+1)*x;
	if(p<r)t2=min(r-p,r-l+1)*x;
	if(l<=p&&p<=r)t3=x*p-x*(n-p);
//	cout<<t1<<" "<<t2<<" "<<t3<<endl;
	return t2-t1+t3;
}
inline ll sol(ll x)
{
	ll w=0,p=(x+1)/2,res=0;
	for(int i=1;i<=n;i++)b[i]=a[i];
	for(int i=1;i<=n;i++)
	{
		if(b[i]>=x-w)
		{
			res+=gt(w+1,x,p,i,x);
			b[i]-=x-w;b[i]%=x;w=b[i];
			if(w)res+=gt(1,w,p,i,x);
		}
		else
		{
			res+=gt(w+1,w+b[i],p,i,x);
			w+=b[i];
		}
//		cout<<res<<endl;
	}
	return res;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),s+=a[i];
	if(s==1){puts("-1");return 0;}
	ll tmp=s,ans=2000000000000000000ll;
	for(int i=2;i<=1000005;i++)if(tmp%i==0)
	{
//		cout<<i<<" "<<sol(i)<<endl;
		ans=min(ans,sol(i));
		while(tmp%i==0)tmp/=i;
	}
	if(tmp>1)ans=min(ans,sol(tmp));
	printf("%lld\n",ans);
	return 0;
}