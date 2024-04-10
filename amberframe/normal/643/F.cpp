#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <memory.h>

using namespace std;
typedef unsigned int u32;
typedef long long LL;
const int maxp = 145;
const int maxq = 19605;
const int M = 19600;
const int Q = 140;

int n,p,q;u32 f[maxq][maxp],ans;

u32 tmp[maxp][maxp];
u32 tr[maxp][maxp];
struct Matrix {
	u32 mat[maxp][maxp];
	void operator*=(const Matrix v)
	{
		for (u32 i=0;i<=p;i++)
		for (u32 j=0;j<=p;j++)
			tmp[i][j]=mat[i][j];
		for (u32 i=0;i<=p;i++)
		for (u32 j=0;j<=p;j++)
		{
			u32 sum=0;
			for (int k=0;k<=p;k++)
				sum+=tmp[i][k]*v.mat[k][j];
			mat[i][j]=sum;
		}
	}
	u32 calc(u32 *f)
	{
		u32 res=0;
		for (u32 i=0;i<=p;i++)
			res+=f[i]*mat[i][p];
		return res;
	}
}trans,T[maxp];

int count(u32 &n)
{
	int cnt=0;
	for (;n%2==0;n>>=1) ++cnt;
	return cnt;
}
u32 fpm(u32 p)
{
	u32 res=1;
	for (u32 i=0;i<=30;i++)
		res*=p,p*=p;
	return res;
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("game.in","r",stdin);
		freopen("game.out","w",stdout);
	#endif
	scanf("%d %d %d",&n,&p,&q);p=min(p,n-1);
	for (u32 i=0;i<=p;i++) {
		u32 cur=1;//tr[i][j]=comb(b-p+j,j-i)
				  //tr[i][p]=comb(b,p-i)
		tr[i][i]=1;int cnt=0; 
		for (u32 j=i+1;j<=p;j++)
		{
			u32 u=n-p+j,v=j-i;
			cnt+=count(u)-count(v);
			cur=cur*u*fpm(v);
			tr[i][j]=cnt>=32?0:(cur<<cnt);
		}
	}
	for (u32 i=0;i<=p;i++) f[0][i]=1;
	for (u32 i=1;i<=min(M,q)+1;i++)
	for (u32 j=0;j<=p;j++)
	for (u32 k=j;k<=p;k++)
		f[i][k]+=f[i-1][j]*tr[j][k];
	for (u32 i=0;i<=p;i++)
	for (u32 j=0;j<=p;j++)
		trans.mat[i][j]=tr[i][j];
	
	for (u32 i=1;i<=min(q,M);i++)
		ans^=i*f[i][p];
	if (q>M) {
		T[1]=trans;int k=M-1;
		while (k) {
			if (k&1) T[1]*=trans;
			trans*=trans;k>>=1;
		}
		for (u32 i=2;i<=Q;i++)
			T[i]=T[1],T[i]*=T[i-1];
		for (u32 i=M+1;i<=q;i++)
			ans^=i*T[(i-1)/M].calc(f[(i-1)%M+1]); 
	}
	printf("%u",ans);
	return 0;
}