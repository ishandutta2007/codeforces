#include<bits/stdc++.h>
using namespace std; 
const int N=100005,M=533;
const long double PI=3.1415926535897932384626;
int n,m,i,f[N],x,y,s0,s1,t[N*4];
char c[N];
long long a0,a1,ans=2000000000000000000ll;
void modify(int i,int l,int r,int x)
{
	if(l==r)
	{
		t[i]^=1;
		return;
	}
	int mid=l+r>>1;
	if(mid>=x)
		modify(i<<1,l,mid,x);
	else
		modify(i<<1|1,mid+1,r,x);
	t[i]=t[i<<1]+t[i<<1|1];
}
int Query(int i,int l,int r,int ll,int rr)
{
	if(l>=ll&&r<=rr)
		return t[i];
	int mid=l+r>>1,s=0;
	if(mid>=ll)
		s+=Query(i<<1,l,mid,ll,rr);
	if(mid<rr)
		s+=Query(i<<1|1,mid+1,r,ll,rr);
	return s;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%s",c+1);
	scanf("%d %d",&x,&y);
	n=strlen(c+1);
	for(i=1;i<=n;++i)
		if(c[i]=='0'||c[i]=='?')
		{
			++s0;
			a1+=s1;
		}
		else
		{
			++s1;
			a0+=s0;
			modify(1,1,n,i);
		}
	ans=min(ans,a0*x+a1*y);
	for(i=1;i<=n;++i)
		if(c[i]=='?')
		{
			modify(1,1,n,i);
			int u=0,v=0;
			if(i!=1)
				u=Query(1,1,n,1,i-1);
			if(i!=n)
				v=Query(1,1,n,i+1,n);
			a1-=u,a0-=v;
			a0+=i-1-u,a1+=n-i-v;
			//cout<<a0<<' '<<a1<<endl;
			ans=min(ans,a0*x+a1*y);
		}
	for(i=1;i<=n;++i)
		if(c[i]=='?')
		{
			modify(1,1,n,i);
			int u=0,v=0;
			if(i!=1)
				u=Query(1,1,n,1,i-1);
			if(i!=n)
				v=Query(1,1,n,i+1,n);
			a1+=u,a0+=v;
			a0-=i-1-u,a1-=n-i-v;
			ans=min(ans,a0*x+a1*y);
		}
	cout<<ans;
}