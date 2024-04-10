#include<bits/stdc++.h>
#define mod 1000000007
#define int __int128
using namespace std;
long long h(int x,int y,int k,int wz){
	if(x<0||y<0)return 0;
	if(x>y)swap(x,y);
	int xx=x>>(wz+1),yy=y>>(wz+1);
	if(xx!=yy)return x+1;
	x=x&((1ll<<(wz+1))-1);
	y=y&((1ll<<(wz+1))-1);
	if(xx!=0)return (1ll*xx*(1ll<<(wz+1))+h(x,y,k,wz))%mod;
	if(wz==0){
		if(k==0)return min(x,y)+1;
		return x+y;
	}
	int X=x>>wz,Y=y>>wz;
	xx=x^(X<<wz),yy=y^(Y<<wz);
	if(!(k&(1<<wz))){
		if(X==1)return ((1<<wz)+h(xx,yy,k,wz-1))%mod;
		if(Y==1)return x+1;
		return h(xx,yy,k,wz-1);
	}
	if(X==1)return (xx+yy+2)%mod;
	if(Y==1)return h(xx,yy,k^(1<<wz),wz-1);
	return 0;
}
long long H(int x,int y,int k,int wz,int L){
	if(L==0)return h(x,y,k,wz);
	k>>=L,wz-=L;
	int xx=x>>L,yy=y>>L;
	int X=x^(xx<<L),Y=y^(yy<<L);
	long long ans=0;
	int A=h(xx-1,yy-1,k,wz),B=h(xx,yy-1,k,wz);
	int C=h(xx-1,yy,k,wz),D=h(xx,yy,k,wz);
	ans+=1ll*(1<<L)*(1<<L)%mod*A%mod;
	ans+=1ll*(X+1)*(1<<L)%mod*(B-A)%mod;
	ans+=1ll*(Y+1)*(1<<L)%mod*(C-A)%mod;
	ans+=1ll*(X+1)*(Y+1)%mod*(0ll+D-C-B+A)%mod;
	return ans%mod;
}
long long C(int x,int i){
	long long a1=(x>>(i+1))<<i;
	long long a2=max((__int128)0,(x&((1ll<<(i+1))-1))-(1<<i)+1);
	return a1+a2;
}
long long S(int x,int y){
	long long ans=0;
	for(int i=0;i<=30;++i){
		long long A=C(x,i),B=x-A+1;
		long long F=C(y,i),G=y-F+1;
		ans+=(A*G%mod+B*F%mod)*(1<<i)%mod;
	}
	return ans%mod;
}
long long _H(int x,int y,int k,int wz,int L){
	if(L==0)return 1ll*k*h(x,y,k,wz)%mod;
	k>>=L,wz-=L;
	int xx=x>>L,yy=y>>L;
	int X=x^(xx<<L),Y=y^(yy<<L);
	long long ans=0;
	int A=h(xx-1,yy-1,k,wz),B=h(xx,yy-1,k,wz);
	int C=h(xx-1,yy,k,wz),D=h(xx,yy,k,wz);
	ans+=1ll*(1<<L)*(1<<L)%mod*A%mod*(k<<L);
	ans+=1ll*S((1<<L)-1,(1<<L)-1)%mod*A;
	ans+=1ll*(X+1)*(1<<L)%mod*(B-A)%mod*(k<<L);
	ans+=1ll*S(X,(1<<L)-1)%mod*(B-A);
	ans+=1ll*(Y+1)*(1<<L)%mod*(C-A)%mod*(k<<L);
	ans+=1ll*S((1<<L)-1,Y)%mod*(C-A);
	ans+=1ll*(X+1)*(Y+1)%mod*(0ll+D-C-B+A)%mod*(k<<L);
	ans+=1ll*S(X,Y)*(0ll+D-C-B+A);
	return ans%mod;
}
long long _g(int x,int y,int k){
	if(k==0)return 0;
	long long ans=0;
	int wz=log2(k+0.5),ys=0;
	int X=x>>(wz+1),Y=y>>(wz+1);
	int xx=x&((1ll<<(wz+1))-1),yy=y&((1ll<<(wz+1))-1);
	for(int i=wz;i>=0;--i){
		if((k&(1<<i))){
			int fs=(0ll+ys+ys+(1<<i)-1)*(1<<i)/2;
			ans=(ans+X*(1ll<<(wz+1))%mod*fs)%mod;
			if(X<Y)ans=(ans+1ll*(xx+1)*fs)%mod;
			else ans=(ans+_H(xx,yy,ys,wz,i));
			ys|=1<<i;
		}
		if(i==0){
			int fs=(0ll+ys+ys+(1<<i)-1)*(1<<i)/2;
			ans=(ans+X*(1ll<<(wz+1))%mod*fs)%mod;
			if(X<Y)ans=(ans+1ll*(xx+1)*fs)%mod;
			else ans=(ans+_H(xx,yy,ys,wz,0));
		}
	}
	return ans;
}
long long g(int x,int y,int k){
	if(k==0)return x+1;
	long long ans=0;
	int wz=log2(k+0.5),ys=0;
	int X=x>>(wz+1),Y=y>>(wz+1);
	int xx=x&((1ll<<(wz+1))-1),yy=y&((1ll<<(wz+1))-1);
	for(int i=wz;i>=0;--i){
		if((k&(1<<i))){
			ans=(ans+X*(1ll<<(wz+1))%mod*(1<<i))%mod;
			if(X<Y)ans=(ans+1ll*(xx+1)*(1<<i))%mod;
			else ans=(ans+H(xx,yy,ys,wz,i));
			ys|=1<<i;
		}
		if(i==0){
			ans=(ans+X*(1ll<<(wz+1))%mod*(1<<i))%mod;
			if(X<Y)ans=(ans+1ll*(xx+1)*(1<<i))%mod;
			else ans=(ans+H(xx,yy,ys,wz,0));
		}
	}
	return ans;
}
long long f(int x,int y,int k){
	if(x==0||y==0||k==0)return 0;
	--x,--y,--k;
	if(x>y)swap(x,y);
	return g(x,y,k)+_g(x,y,k);
}
signed main(){
	signed T;
	cin>>T;
	while(T--){
		signed a,b,c,d,k;
		scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
		long long ans=f(c,d,k)-f(a-1,d,k)-f(c,b-1,k)+f(a-1,b-1,k);
		ans=(ans%mod+mod)%mod;
		printf("%lld\n",ans);
	}
	return (signed)0;
}