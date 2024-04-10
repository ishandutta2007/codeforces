#include<bits/stdc++.h>
int n,q;
const int mod=1e9+7;
/*
F(n) = [x^n]f(x) = \sum C(3,n) + C(6,n) + C(9,n) + ...

=> f(x) = (C(3,0)+C(6,0)+C(9,0)+...) + (C(3,1)+C(6,1)+C(9,1)+...)x + ...

= (x+1)^3 + (x+1)^6 + (x+1)^9 + ... + (x+1)^3n

= ( (x+1)^(3n+3) - (x+1)^3 ) / ((x+1)^3 - 1)

*/
// F(x) = C(3,x) + C(6,x) + C(9,x) + C(12,x) + ... + C(3n,x)
// = ( 3!/(3-x)! + 6!/(6-x)! + ... + (3n)!/(3n-x)! )/(x!)
/*
1  1  1  1  1  1  1  1  1  1
0  1  2  3  4  5  6  7  8  9
0  0  1  3  6 10 15 21 28 36
0  0  0  1  4 10 20 35 56 84
0  0  0  0  1  5 15 35 70 126
0  0  0  0  0  1  6 21 56 126
0  0  0  0  0  0  1  7 28 84
...
=>
1   1 [*1]   1   1   1
0   3 [*3]   6   9  12
0   3 [*3]  15  36  66
0   1 [*1]->20  84

f(i,j) = f(i-1,j) + 3f(i-1,j-1) + 3f(i-1,j-2) + f(i-1,j-3)

*/
int fac[3333333],inv[3333333];
inline int qpow(int x,int k)
{int r=1;for(;k;k>>=1,x=x*1ll*x%mod)if(k&1)r=r*1ll*x%mod;return r;}
int ans[3333333],f[3333333],x[3333333];
int C(int n,int r)
{return fac[n]*1ll*inv[r]%mod*inv[n-r]%mod;}
const long long modInf=mod*3ll;
void divs()
{
	for(register int i=n*3+3;i>=3;i--)
	{
		int t=f[i];
		ans[i-3]=f[i];
		f[i-1]=(f[i-1]+modInf-t*3ll)%mod;
		f[i-2]=(f[i-2]+modInf-t*3ll)%mod;
	}
}
void calc()
{
	register int i;
	for(i=1;i<=n*3+3;i++)
		f[i]=C(n*3+3,i);
	(f[1]+=mod-3)%=mod;
	(f[2]+=mod-3)%=mod;
	(f[3]+=mod-1)%=mod;
	divs();
}
int main()
{
	scanf("%d%d",&n,&q);
	register int i;
	const int N=n*3+3;
	for(i=fac[0]=1;i<=N;i++)fac[i]=fac[i-1]*1ll*i%mod;
	for(i=N,inv[N]=qpow(fac[N],mod-2);i;i--)
		inv[i-1]=inv[i]*1ll*i%mod;
	for(i=1;i<=q;i++)scanf("%d",x+i);
	calc();
	for(i=1;i<=q;i++)printf("%d\n",ans[x[i]]);
}