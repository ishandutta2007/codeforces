#include<bits/stdc++.h>
using namespace std;
int n,mod,L,R,t;
struct Residue{
int p,k,q,phi,fac[100100],per[100100];
int ksm(int x,int y){int z=1;for(;y;y>>=1,x=1ll*x*x%q)if(y&1)z=1ll*z*x%q;return z;}
int occ(int x){return !x?0:occ(x/p)+x/p;}
int rem(int x){return !x?1:1ll*rem(x/p)*per[x/q]%q*fac[x%q]%q;}
void init(){
	q=1;for(int i=1;i<=k;i++)q*=p;phi=q/p*(p-1);
//	printf("%d^%d=%d | %d\n",p,k,q,phi);
	fac[0]=1;for(int i=1;i<=min(n,q);i++)if(i%p)fac[i]=1ll*fac[i-1]*i%q;else fac[i]=fac[i-1];
	per[0]=1;if(q<=n)for(int i=1;i<=n;i++)per[i]=1ll*per[i-1]*fac[q]%mod;
//	for(int i=0;i<=min(n,q);i++)printf("%d ",fac[i]);puts("");
}
int calc(int a,int b,int c){
	return 1ll*ksm(p,occ(a+b+c)-occ(a)-occ(b)-occ(c))*rem(a+b+c)%q*ksm(1ll*rem(a)*rem(b)%q*rem(c)%q,phi-1)%q;
}
}r[10];
void factorize(){
	int x=mod;
	for(int i=2;i*i<=x;i++){
		if(x%i)continue;
		r[t].p=i,r[t].k=0;while(!(x%i))r[t].k++,x/=i;
		r[t++].init();
	}
	if(x!=1)r[t].p=x,r[t].k=1,r[t++].init();
}
int sum[10],res;
void work(int x,int tp){
	for(int i=0;(i<<1)+x<=n;i++)
		for(int j=0;j<t;j++)(sum[j]+=(r[j].q+tp*r[j].calc(x+i,i,n-x-(i<<1)))%r[j].q)%=r[j].q;
}
int main(){
	scanf("%d%d%d%d",&n,&mod,&L,&R),factorize();
	work(L,1),work(L+1,1),work(R+1,-1),work(R+2,-1);
	for(int i=0;i<t;i++)res=(1ll*sum[i]*(mod/r[i].q)*r[i].ksm(mod/r[i].q,r[i].phi-1)+res)%mod;
	printf("%d\n",res);
	return 0;
}