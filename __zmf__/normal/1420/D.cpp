#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=300009;
long long n,k,p=998244353;
struct point
{
	long long l,r;
}q[N];
long long a[N],val[N];
bool cmp(point xxx,point yyy)
{
	return xxx.r<yyy.r;
}
long long qpow(long long x,long long y)
{
	long long res=1,base=x;
	while(y!=0)
	{
		if(y%2==1)res=(res*base)%p;
		base=base*base%p;
		y=y/2;
	}
	return res;
}
long long kk,ans;
signed main()
{
    cin>>n>>k;
    k--;
    for(int i=1;i<=k-1;i++)val[i]=0;
    val[k]=1;
    for(int i=k+1;i<=n;i++)val[i]=val[i-1]*i%p*qpow(i-k,p-2)%p;
    for(int i=1;i<=n;i++)cin>>q[i].l>>q[i].r;
    sort(q+1,q+n+1,cmp);
    for(int i=1;i<=n;i++)a[i]=q[i].l;
    sort(a+1,a+n+1);
    //for(int i=1;i<=n;i++)cout<<a[i]<<" ";
	//cout<<endl; 
    for(int i=1;i<=n;i++)
    {
    	if(a[n]<=q[i].r)
		{
			ans=(ans+val[n-i])%p;
			continue;
		}
    	kk=upper_bound(a+1,a+n+1,q[i].r)-a;
    	//cout<<q[i].r<<" ";
    	kk=n-kk+1;
		//cout<<kk<<endl;
    	kk=n-(i-1)-kk;
    	//cout<<kk<<endl;
    	ans=(ans+val[kk-1])%p;
	}
	cout<<ans%p<<endl;
    return 0;
}