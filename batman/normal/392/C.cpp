#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((ll)90)
#define MOD ((ll)1e9+7)

struct Mat
{
	ll n,m,a[N][N];
	Mat(){for(int i=0;i<N;i++)for(int j=0;j<N;j++)a[i][j]=0;}
	Mat operator *(Mat B)
	{
		Mat ex;ex.n=n;ex.m=B.m;
		for(int k=0;k<m;k++)
		    for(int i=0;i<ex.n;i++)
			    for(int j=0;j<ex.m;j++)
					ex.a[i][j]+=(a[i][k]*B.a[k][j]),ex.a[i][j]%=MOD;
		return ex;
	}
	Mat operator ^(ll val)
	{
		Mat ex;ex.n=n;ex.m=m;for(int i=0;i<n;i++)ex.a[i][i]=1;
		Mat now=(*this);
		while(val)
		{
			if(val%2)ex=ex*now;
			now=now*now;
			val/=2;
		}
		return ex;
	}
};

ll n,k,tvn2[N],c[N][N];
Mat res,ans;

int main()
{
	cin>>n>>k;
	tvn2[0]=1;for(int i=1;i<N;i++)tvn2[i]=(tvn2[i-1]*2)%MOD;
	for(int i=0;i<N;i++)c[i][0]=c[i][i]=1;
	for(int i=1;i<N;i++)for(int j=1;j<i;j++)c[i][j]=(c[i-1][j]+c[i-1][j-1])%MOD;
	res.n=res.m=83;
	for(int i=41;i<=81;i++)res.a[i][i-41]=1;
	for(int i=0;i<=40;i++)
	{
		for(int j=0;j<=i;j++)res.a[i][j]=c[i][j];
		for(int j=0;j<=i;j++)res.a[i][j+41]=(tvn2[i-j]*c[i][j])%MOD;
	}
	res.a[82][82]=res.a[82][k]=1;
	
	ans.n=83;ans.m=1;
	for(int i=0;i<=41;i++)ans.a[i][0]=1;ans.a[82][0]=1;
	res=res^n;
	ans=res*ans;
	cout<<(ans.a[82][0]-1+MOD)%MOD<<"\n";
	return 0;
}