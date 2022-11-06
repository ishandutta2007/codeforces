#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1005;
int n,a[N],b[N];ll L,l[N],r[N];
inline ll qry(int i,ll x){printf("? %d %lld\n",i+1,x);fflush(stdout);scanf("%lld",&x);return x;}
void sol(int l1,int r1,ll l2,ll r2)
{
	if(l1==r1){l[a[l1]]=l2;r[a[l1]]=r2;return;}
	int m1=(l1+r1)/2;ll x=L/n*(m1+1),m2;
	for(int l=l1,r=r1;;)
	{
		int i=rand()%(r-l+1)+l;
		ll lb=l2,rb=r2;
		while(lb<rb)
		{
			ll mb=(lb+rb)/2;
			if(qry(a[i],mb)<x)lb=mb+1;else rb=mb;
		}
		int l2=l,r2=r;
		vector<int>e;
		for(int j=l;j<=r;++j)
		{
			ll y=qry(a[j],lb);
			if(y>x)b[l2++]=a[j];
			else if(y<x)b[r2--]=a[j];
			else e.push_back(a[j]);
		}
		for(int j=0;j<e.size();++j)b[l2+j]=e[j];
		memcpy(a+l,b+l,4*(r-l+1));
		if(l2<=m1&&m1<=r2){m2=lb;break;}
		if(l2<m1)l=l2+1;else r=l2-1;
	}
	sol(l1,m1,l2,m2);sol(m1+1,r1,m2,r2);
}
int main()
{
	scanf("%d%lld",&n,&L);
	for(int i=0;i<n;++i)a[i]=i;
	sol(0,n-1,0,1e18);puts("!");
	for(int i=0;i<n;++i)printf("%lld %lld\n",l[i],r[i]);
	return 0;
}