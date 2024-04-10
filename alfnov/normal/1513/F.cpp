#include<bits/stdc++.h>
using namespace std;
struct seg
{
	int fl,l,r;
	bool operator<(const seg &other)const
	{
		if(l==other.l)return r<other.r;
		return l<other.l;
	}
}e[200005];
int a[200005],b[200005];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)scanf("%d",&b[i]);
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		ans+=abs(a[i]-b[i]);
		if(a[i]<b[i])e[i].fl=1;
		else e[i].fl=-1;
		e[i].l=min(a[i],b[i]),e[i].r=max(a[i],b[i]);
	}
	sort(e+1,e+n+1);
	int a1=0,a2=0,mx=0;
	for(int i=1;i<=n;i++)
	{
		if(e[i].fl==1)mx=max(mx,2*min(e[i].r-e[i].l,a2-e[i].l));
		else mx=max(mx,2*min(e[i].r-e[i].l,a1-e[i].l));
		if(e[i].fl==1)a1=max(a1,e[i].r);
		else a2=max(a2,e[i].r);
	}
	cout<<ans-mx<<endl;
	return 0;
}