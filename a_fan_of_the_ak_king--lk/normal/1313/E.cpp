#include<bits/stdc++.h>
using namespace std;
const int N=1000005,M=998244353,P=1000000007;
//typedef long double lb;
int i,t,n,la[N],lb[N],tree[2*N],m,j,lm;
char a[N],b[N],c[N*2];
long long ans,t2[2*N],s,ha[N],hb[N],hc[N],ed[N],h2a[N],h2b[N],h2c[N],pm[N];
void motor(int x,int y)
{
	while(x<=lm)
	{
		++tree[x];
		t2[x]+=y;
		x+=-x&x;
	}
}
int lkak(int x)
{
	int s=0;
	while(x)
	{
		s+=tree[x];
		x-=-x&x;
	}
	return s;
}
long long lkwin(int x)
{
	long long s=0;
	while(x)
	{
		s+=t2[x];
		x-=-x&x;
	}
	return s;
}
long long hasha(int i,int l)
{
	return ((ha[i+l-1]-ha[i-1]*ed[l])%M+M)%M;
}
long long hashb(int i,int l)
{
	return ((hb[i+l-1]-hb[i-1]*ed[l])%M+M)%M;
}
long long hashc(int i,int l)
{
	return ((hc[i+l-1]-hc[i-1]*ed[l])%M+M)%M;
}
long long hasha2(int i,int l)
{
	return ((h2a[i+l-1]-h2a[i-1]*pm[l])%P+P)%P;
}
long long hashb2(int i,int l)
{
	return ((h2b[i+l-1]-h2b[i-1]*pm[l])%P+P)%P;
}
long long hashc2(int i,int l)
{
	return ((h2c[i+l-1]-h2c[i-1]*pm[l])%P+P)%P;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d %d",&n,&m);
	scanf("%s\n%s\n%s",a+1,b+1,c+1);
	srand(time(0));
	long long sd=rand()*2%10000000+7777;
	long long sq=rand()*2%10000000+7777;
	lm=max(n,m);
	pm[0]=ed[0]=1;
	for(i=1;i<=n;++i)
	{
		ha[i]=(ha[i-1]*sd+a[i])%M;
		hb[i]=(hb[i-1]*sd+b[i])%M;
		h2a[i]=(h2a[i-1]*sq+a[i])%P;
		h2b[i]=(h2b[i-1]*sq+b[i])%P;
		ed[i]=ed[i-1]*sd%M;
		pm[i]=pm[i-1]*sq%P;
	}
	for(i=1;i<=m;++i)
	{
		hc[i]=(hc[i-1]*sd+c[i])%M;
		h2c[i]=(h2c[i-1]*sq+c[i])%P;
	}
	for(i=1;i<=n;++i)
	{
		int l=1,r=min(n-i+1,m)+1;
		while(l<r)
		{
			int mid=l+r>>1;
			if(hasha(i,mid)==hashc(1,mid)&&hasha2(i,mid)==hashc2(1,mid))
				l=mid+1;
			else
				r=mid;
		}
		la[i]=min(l-1,m-1);
	}
	for(i=1;i<=n;++i)
	{
		int l=1,r=i+1;
		while(l<r)
		{
			int mid=l+r>>1;
			if(hashb(i-mid+1,mid)==hashc(m-mid+1,mid)&&hashb2(i-mid+1,mid)==hashc2(m-mid+1,mid))
				l=mid+1;
			else
				r=mid;
		}
		lb[i]=min(l-1,m-1);
	}
	for(i=n;i>=1;--i)
	{
		motor(lb[i]+1,lb[i]);
		s+=lb[i];
		ans+=s-lkwin(m-la[i])+1ll*(n-i+1-lkak(m-la[i]))*(la[i]-m+1);
	//	cout<<s-lkwin(m-la[i])+(n-i+1-lkak(m-la[i]))*(la[i]-m+1)<<endl;
		//cout<<la[i]<<' '<<s-lkwin(m-la[i]+1)<<' '<<(i-lkak(m-la[i]+1))*(la[i]-m+1)<<endl;
	}
	s=0;
	memset(tree,0,sizeof(tree));
	memset(t2,0,sizeof(t2));
	for(i=n;i>=m;--i)
	{
		motor(lb[i]+1,lb[i]);
		s+=lb[i];
		ans-=s-lkwin(m-la[i-m+1])+1ll*(n-i+1-lkak(m-la[i-m+1]))*(la[i-m+1]-m+1);
	}
	cout<<ans;
}