#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,Mx;
char ch;
int one[2097162];
LL a[2097162],b[2097162],pw[22];
inline void Or(LL a[],int o)
{
	for(int i=1;i<n;i<<=1)for(int j=0;j<n;j+=(i<<1))for(int k=0;k<i;++k)a[i+j+k]+=o*a[j+k];
}
int main()
{
	scanf("%d",&Mx),n=(1<<Mx),pw[0]=1;
	for(int i=1;i<=Mx;++i)pw[i]=(pw[i-1]<<2);
	for(int i=0;i<n;++i)one[i]=one[i>>1]+(i&1);
	for(int i=0;i<n;++i)
	{
		do ch=getchar();while(ch<'0' || ch>'3');
		a[i]=(ch^48)*pw[one[i]];
	}
	for(int i=0;i<n;++i)
	{
		do ch=getchar();while(ch<'0' || ch>'3');
		b[i]=(ch^48)*pw[one[i]];
	}
	Or(a,1),Or(b,1);
	for(int i=0;i<n;++i)a[i]*=b[i];
	Or(a,-1);
	for(int i=0;i<n;++i)printf("%lld",(a[i]/pw[one[i]])&3);
	return 0;
}