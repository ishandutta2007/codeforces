#include<bits/stdc++.h>
using namespace std;
#define ll long long
int qp(int a,int b,int p){
	int r=1;
	for(;b;b>>=1,a=a*1ll*a%p)if(b&1)r=r*1ll*a%p;
	return r;
}
int main(){
	int a,b,p,ia,ip,i;
	ll x,y,w=0,o,u,v;
	scanf("%d%d%d%lld",&a,&b,&p,&x),ia=qp(a,p-2,p),ip=qp(p-1,p-2,p),y=(p-1ll)*p,u=x/y,v=x%y;
	for(i=1;i<p;++i){
		b=b*1ll*ia%p,o=(((b-i)*1ll*ip%p*(p-1)+i)%y+y)%y;
		w+=u+(v>=o);
	}
	printf("%lld",w);
	return 0;
}