#include <bits/stdc++.h>
using namespace std;
#define K ((int)16)
#define M ((int)30)
#define N ((int)(1<<K))
#define W ((int)44759)
#define MOD ((int)998244353)
int tavan(int x,int y){int res=1;while(y){if(y%2)res=(1LL*res*x)%MOD;x=(1LL*x*x)%MOD;y/=2;}return res;}

int n,k;
int dp[2][3][N],inv_dp[2][3][N],ex[N],inv_now[3][N],now[3][N];

void ntt(int a[],int inv)
{
	for(int i=0;i<N;i++)
	{
		int x=0;
		for(int j=0;j<K;j++)if((i&(1<<j)))x+=(1<<(K-j-1));
		if(x>i)swap(a[x],a[i]);
	}
	for(int len=2;len<=N;len*=2)
	{
		int wn=tavan(W,N/len);
		if(inv==-1)wn=tavan(wn,MOD-2);
		for(int i=0;i<N;i+=len)
		{
			int w=1;
			for(int j=0;j<len/2;j++)
			{
				int ex=(1LL*w*a[i+j+len/2])%MOD;
				int ex1=a[i+j]+ex,ex2=a[i+j]-ex;
				if(ex1>=MOD)ex1-=MOD;
				if(ex2<0)ex2+=MOD;
				a[i+j]=ex1;a[i+j+len/2]=ex2;
				w=(1LL*w*wn)%MOD;
			}
		}
	}
	if(inv==-1)
	{
		int ex=tavan(N,MOD-2);
		for(int i=0;i<N;i++)a[i]=(1LL*a[i]*ex)%MOD;
		for(int i=N/2;i<N;i++)a[i]=0;
	}
}

void mul(int a[N],int b[N],int c[N])
{
	for(int i=0;i<N;i++)c[i]=(1LL*a[i]*b[i])%MOD;
	ntt(c,-1);
}

void merge(int a[3][N],int b[3][N],int c[3][N])
{
	mul(a[0],b[0],c[0]);
	mul(a[1],b[1],ex);
	for(int j=0;j<N/2;j++)c[2][j]=ex[j];
	for(int j=1;j<N/2;j++){c[0][j]+=ex[j-1];if(c[0][j]>=MOD)c[0][j]-=MOD;}
	mul(a[0],b[1],c[1]);
	mul(a[1],b[2],ex);
	for(int j=1;j<N/2;j++){c[1][j]+=ex[j-1];if(c[1][j]>=MOD)c[1][j]-=MOD;}
	mul(a[2],b[2],ex);
	for(int j=1;j<N/2;j++){c[2][j]+=ex[j-1];if(c[2][j]>=MOD)c[2][j]-=MOD;}
}

void _inv(int a[3][N],int b[3][N])
{
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<N;j++)b[i][j]=a[i][j];
		ntt(b[i],1);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>k;
	dp[0][1][0]=dp[0][0][0]=dp[0][0][1]=now[0][0]=1;
	_inv(dp[0],inv_dp[0]);_inv(now,inv_now);
	if(n&1)merge(inv_now,inv_dp[0],now),_inv(now,inv_now);
	for(int i=1;i<M;i++)
	{
		merge(inv_dp[!(i&1)],inv_dp[!(i&1)],dp[(i&1)]);
		_inv(dp[(i&1)],inv_dp[(i&1)]);
		if((n&(1<<i)))
		{
			merge(inv_now,inv_dp[(i&1)],now);
			_inv(now,inv_now);
		}
	}
	for(int i=1;i<=k;i++)cout<<now[0][i]<<" ";
	cout<<"\n";
	return 0;
}