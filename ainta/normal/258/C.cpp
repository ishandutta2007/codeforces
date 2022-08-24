#include<stdio.h>
#include<algorithm>
using namespace std;
int n,i,w[100001],j,d[1000],c,t,tp;
__int64 p,q,Mod=1000000007,Res,T,pp;
int main()
{
	int b,e,m,z;
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d",&w[i]);
	sort(w+1,w+n+1);
	for(i=1;i<=w[n];i++){
		c=0;
		for(j=1;j*j<=i;j++)if(i%j==0)d[++c]=j;
		for(j=c;j>=1;j--){
			if(d[j]*d[j]==i)continue;
			d[++c]=i/d[j];
		}
		t=1;T=1;
		d[c+1]=99999999;
		for(j=1;j<=c+1;j++){
			if(t==n)break;
			b=t,e=n,z=n+1;
			while(b<=e){
				m=(b+e+1)/2;
				if(w[m]>=d[j])z=m,e=m-1;
				else b=m+1;
			}
			tp=z;
			z=z-t;
			p=1,q=j-1;
			while(z){
				if(z&1){
					p=p*q%Mod;
				}
				q=q*q%Mod;
				z/=2;
			}
			if(j==c+1){
				pp=p;
				z=tp-t;
				p=1,q=j-2;
				while(z){
					if(z&1){
						p=p*q%Mod;
					}
					q=q*q%Mod;
					z/=2;
				}
				p=(pp-p+Mod)%Mod;
			}
			T=T*p%Mod;
			t=tp;
		}
		Res+=T;
		Res%=Mod;
	}
	printf("%I64d\n",Res);
}