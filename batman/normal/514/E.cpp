#include <bits/stdc++.h>
using namespace std; 
#define ll long long
#define N ((ll)105)
#define MOD ((ll)1e9+7)

struct Mat
{
	ll a[N][N],n,m;
	Mat(){for(int i=0;i<N;i++)for(int j=0;j<N;j++)a[i][j]=0;}
	Mat operator *(Mat x)
	{
		Mat ex;ex.n=n;ex.m=x.m;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				for(int k=0;k<x.n;k++)
					ex.a[i][j]+=a[i][k]*x.a[k][j],ex.a[i][j]%=MOD;
		return ex;
	}
	Mat operator ^(ll num)
	{
		Mat ex,now=*this;ex.n=ex.m=n;
		for(int i=0;i<n;i++)ex.a[i][i]=1;
		while(num)
		{
			if(num%2)ex=ex*now;
			now=now*now;
			num/=2;
		}
		return ex;
	}
};

ll n,x,cnt[N];
Mat res;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>x;
	ll K=101;
	res.n=res.m=K;
	for(int i=0;i<n;i++)
	{
		ll ex;
		cin>>ex;
		res.a[0][ex-1]++;
	}
	for(int i=1;i<K-1;i++)res.a[i][i-1]=1;
	res.a[K-1][0]=res.a[K-1][K-1]=1;
	res=res^(x+1);
	cout<<(res.a[K-1][0]);
	return 0;
}