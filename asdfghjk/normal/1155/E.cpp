#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<cstdlib>
using namespace std;
const int md=1000003;
int i,j,k,x,ans[55],a[55][15];
int pw(int a,int b)
{
	int rtn=1;
	while(b)
	{
		if(b&1)
			rtn=1ll*rtn*a%md;
		a=1ll*a*a%md;
		b>>=1;
	}
	return rtn;
}
int main()
{
	//freopen("guess.in","r",stdin);
	//freopen("guess.out","w",stdout);
	for(i=0;i<50;++i)
	{
		cout<<'?'<<' '<<i<<endl;
		cout.flush();
		cin>>a[i][11];
		for(j=0,k=1;j<=10;++j)
		{
			a[i][j]=k;
			k=1ll*k*i%md;
		}
	}
	for(i=0;i<=10;++i)
	{
		for(j=i;j<50;++j)
			if(a[j][i])
				break;
		if(j!=i)
			for(k=0;k<=11;++k)
				swap(a[i][k],a[j][k]);
		for(j=i+1;j<50;++j)
		{
			x=1ll*a[j][i]*pw(a[i][i],md-2)%md;
			for(k=i;k<=11;++k)
				a[j][k]=(a[j][k]-1ll*a[i][k]*x%md+md)%md;
		}
	}
	ans[10]=1ll*a[10][11]*pw(a[10][10],md-2)%md;
	for(i=9;i>=0;--i)
	{
		ans[i]=a[i][11];
		for(j=i+1;j<=10;++j)
			ans[i]=(ans[i]-1ll*ans[j]*a[i][j]%md+md)%md;
		ans[i]=1ll*ans[i]*pw(a[i][i],md-2)%md;
	}
	for(i=0;i<md;++i)
	{
		for(j=0,k=1,x=0;j<=10;++j)
		{
			x=(x+1ll*k*ans[j])%md;
			k=1ll*k*i%md;
		}
		if(x==0)
		{
			cout<<'!'<<' '<<i;
			return 0;
		}
	}
	cout<<'!'<<' '<<'-'<<'1';
	return 0;
}