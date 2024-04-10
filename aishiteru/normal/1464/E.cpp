#include<bits/stdc++.h>
using namespace std; 
const int N=262144,M=998244353;
const long double PI=3.1415926535897932384626;
int n,m,i,u,v,q[N],pts[N],l,r,p[N];
long long f[N],s[N];
long long qpow(long long a,long long b)
{
	long long s=a,ans=1;
	while(b)
	{
		if(b&1)
			ans=ans*s%M;
		s=s*s%M;
		b>>=1;
	}
	return ans;
}
vector<int> g[N],t[N];
long long inv2=qpow(2,M-2);
void FWT_xor(long long *a,int opt)
{
    for(int i=1;i<N;i<<=1)
        for(int p=i<<1,j=0;j<N;j+=p)
            for(int k=0;k<i;++k)
            {
                long long X=a[j+k],Y=a[i+j+k];
                a[j+k]=(X+Y)%M;a[i+j+k]=(X+M-Y)%M;
                if(opt==-1)a[j+k]=1ll*a[j+k]*inv2%M,a[i+j+k]=1ll*a[i+j+k]*inv2%M;
            }
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d %d",&n,&m);
	for(i=1;i<=m;++i)
	{
		scanf("%d %d",&u,&v);
		g[v].push_back(u);
		++pts[u];
	}
	l=1;
	for(i=1;i<=n;++i)
		if(pts[i]==0)
			q[++r]=i;
	while(l<=r)
	{
		sort(t[q[l]].begin(),t[q[l]].end());
		for(auto it:t[q[l]])
			if(it==p[q[l]])
				++p[q[l]];
		for(auto it:g[q[l]])
		{
			--pts[it];
			t[it].push_back(p[q[l]]);
			if(pts[it]==0)
				q[++r]=it;
		}
		++l;
	}
	long long iv=qpow(n,M-2);
	for(i=1;i<=n;++i)
		++s[p[i]];
	for(i=0;i<N;++i)
		s[i]=s[i]*iv%M;
	FWT_xor(s,1);
	long long ii=qpow(n+1,M-2);
	for(i=0;i<N;++i)
		f[i]=qpow(1-s[i]*n%M*ii%M,M-2)*ii%M;
	FWT_xor(f,-1);
	cout<<((1-f[0])%M+M)%M;
}