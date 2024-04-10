#include <bits/stdc++.h>
using namespace std;
#define N ((int)(1<<19))
#define R ((int)1847)
#define MOD ((int)998244353)
int tavan(int x,int y){int res=1;while(y){if(y%2)res=1LL*res*x%MOD;x=1LL*x*x%MOD;y/=2;}return res;}

int lg[N];
int c[N],dp[N],lazy[N],ex[N],ex2[N];

void ntt(int a[],int n,int inv)
{
	int r=tavan(R,N/n),k=0,nn=n;
	while(nn>1)k++,nn/=2;
	for(int i=0;i<n;i++)
	{
		int x=0;
		for(int j=0;j<k;j++)
			if((i&(1<<j)))
				x+=(1<<(k-j-1));
		if(i<x)swap(a[i],a[x]);
	}
	for(int l=2;l<=n;l*=2)
	{
		int wn=tavan(r,n/l);
		if(inv==-1)wn=tavan(wn,MOD-2);
		for(int i=0;i<n;i+=l)
		{
			int w=1;
			for(int j=0;j<l/2;j++)
			{
				int p=1LL*w*a[i+j+l/2]%MOD;
				a[i+j+l/2]=(a[i+j]-p+MOD)%MOD;
				a[i+j]=(a[i+j]+p)%MOD;
				w=1LL*w*wn%MOD;
			}
		}
	}
	if(inv==-1)
	{
		int p=tavan(n,MOD-2);
		for(int i=0;i<n;i++)
			a[i]=1LL*a[i]*p%MOD;
	}
}

void solve(int l,int r)
{
	if(r==l+1)
	{
		if(l==0)dp[l]=1;
		return ;
	}
	int mid=(l+r)/2,n=(1<<lg[r-l]);
	vector <int> safe;
	for(int i=0;i<n;i++)safe.push_back(lazy[i]);
	solve(l,mid);
	//
	for(int i=0;i<n;i++)lazy[i]=safe[i];
	for(int i=0;i<n;i++)ex[i]=lazy[i];
	for(int i=l;i<mid;i++)ex2[i-l]=dp[i];
	ntt(ex,n,1);ntt(ex2,n,1);
	for(int i=0;i<n;i++)ex[i]=1LL*ex[i]*ex2[i]%MOD,ex2[i]=0;
	ntt(ex,n,-1);
	for(int i=mid;i<r;i++)dp[i]+=ex[i-l],dp[i]%=MOD;
	for(int i=0;i<n;i++)ex[i]=0;
	//
	for(int i=l;i<mid;i++)ex[i-l]=dp[i];
	for(int i=0;i<r-l;i++)ex2[i]=c[i];
	ntt(ex,n,1);ntt(ex2,n,1);
	for(int i=0;i<n;i++)ex[i]=1LL*ex[i]*ex2[i]%MOD,ex2[i]=0;
	ntt(ex,n,-1);
	for(int i=0;i<n;i++)
	{
		if(i+l<N)lazy[i+l]+=ex[i],lazy[i+l]%=MOD;
		ex[i]=0;
	}
	//
	for(int i=0;i<n;i++)ex[i]=lazy[i];
	for(int i=l;i<mid;i++)ex2[i-l]=dp[i];
	ntt(ex,n,1);ntt(ex2,n,1);
	for(int i=0;i<n;i++)ex[i]=1LL*ex[i]*ex2[i]%MOD,ex2[i]=0;
	ntt(ex,n,-1);
	for(int i=mid;i<r;i++)dp[i]+=ex[i-l],dp[i]%=MOD;
	for(int i=0;i<n;i++)ex[i]=0;
	solve(mid,r);
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	lg[1]=1;
	for(int i=2;i<N;i++)
	{
		if((1<<lg[i-1])>=2*i)lg[i]=lg[i-1];
		else lg[i]=lg[i-1]+1;
	}
	int n,m;cin>>n>>m;
	for(int i=0;i<n;i++){int x;cin>>x;c[x]=1;}
	solve(0,m+1);
	for(int i=1;i<=m;i++)cout<<dp[i]<<"\n";
	return 0;
}