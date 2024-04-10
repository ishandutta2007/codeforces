#include<cstdio>
long long M;
long long pow(long long a) //calc only pow of 2
{
	if(a==0) return 1LL%M;
	long long res=pow(a/2);
	res*=res;
	res%=M;
	if(a%2==1) res*=2;
	res%=M;
	return res;
}
struct mat
{
	long long a[2][2];
};
mat prod(mat a,mat b)
{
	mat c;
	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++)
			c.a[i][j]=0;
	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++)
			for(int k=0;k<2;k++)
				c.a[i][j]=(c.a[i][j]+(a.a[i][k]*b.a[k][j])%M)%M;
	return c;
}
mat powm(long long a)
{
	if(a==0)
	{
		mat I;
		I.a[0][0]=I.a[1][1]=1%M;
		I.a[1][0]=I.a[0][1]=0;
		return I;
	}
	mat res=powm(a/2);
	res=prod(res,res);
	if(a%2==1)
	{
		mat A;
		A.a[0][0]=A.a[0][1]=A.a[1][0]=1%M;
		A.a[1][1]=0;
		res=prod(res,A);
	}
	return res;
}
long long comb[100][100];
long long solve(long long N,int k,int l)
{//N: count, k: 0 of dest, l: 0 of all
	long long res=1%M;
	long long pow2=pow(N);
	long long pow16=(powm(N+1).a)[0][0];
	long long pow2_16=(pow2-pow16+M)%M;
	for(int i=0;i<k;i++)
		res=(res*pow16)%M;
	for(int i=k;i<l;i++)
		res=(res*pow2_16)%M;
	return res;
}
int main()
{
	long long N,K;
	int L;
	scanf("%I64d%I64d%d%I64d",&N,&K,&L,&M);
	for(int i=0;i<100;i++)
	{
		comb[i][0]=1LL%M;
		for(int j=1;j<i;j++)
			comb[i][j]=(comb[i-1][j-1]+comb[i-1][j])%M;
		comb[i][i]=1LL%M;
	}
	int kbit=0;
	int tb=0;
	while(K)
	{
		tb++;
		kbit+=K%2;
		K/=2;
	}
	if(tb>L)
	{
		puts("0");
		return 0;
	}
	printf("%I64d\n",solve(N,L-kbit,L));
}