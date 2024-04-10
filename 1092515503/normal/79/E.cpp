#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a,b,c;ll T;
int dis(int x,int y,int X,int Y){return abs(x-X)+abs(y-Y);}
ll route(int s,int t){return 1ll*(s<t?s+t+1:s+t-1)*abs(s-t)>>1;}
#define _A a+c-1,b+c-1
#define _B a,b+c-1
#define _C a,b
#define _D a+c-1,b
bool che(int x,int y,ll A,ll B,ll C,ll D){
//	printf("I%d %d %lld %lld %lld %lld\n",x,y,A,B,C,D);
	ll _a,_b,_c,_d;
	if(x<a){
		_a=route(dis(x,y,_A),dis(a,y,_A));if(A<_a)return false;A-=_a;
		_b=route(dis(x,y,_B),dis(a,y,_B));if(B<_b)return false;B-=_b;
		_c=route(dis(x,y,_C),dis(a,y,_C));if(C<_c)return false;C-=_c;
		_d=route(dis(x,y,_D),dis(a,y,_D));if(D<_d)return false;D-=_d;
		x=a;
	}
	if(y<b){
		_a=route(dis(x,y,_A),dis(x,b,_A));if(A<_a)return false;A-=_a;
		_b=route(dis(x,y,_B),dis(x,b,_B));if(B<_b)return false;B-=_b;
		_c=route(dis(x,y,_C),dis(x,b,_C));if(C<_c)return false;C-=_c;
		_d=route(dis(x,y,_D),dis(x,b,_D));if(D<_d)return false;D-=_d;
		y=b;
	}
//	printf("II%d %d %lld %lld %lld %lld\n",x,y,A,B,C,D);
	_c=route(dis(x,y,_C),dis(n,n,_C));if(C<_c)return false;
	if(x>=a+c-1||y>=b+c-1){
		if(x<a+c-1){
			_a=route(dis(x,y,_A),dis(a+c-1,y,_A));if(A<_a)return false;A-=_a;
			_b=route(dis(x,y,_B),dis(a+c-1,y,_B));if(B<_b)return false;B-=_b;
			_d=route(dis(x,y,_D),dis(a+c-1,y,_D));if(D<_d)return false;D-=_d;
			x=a+c-1;
		}
		if(y<b+c-1){
			_a=route(dis(x,y,_A),dis(x,b+c-1,_A));if(A<_a)return false;A-=_a;
			_b=route(dis(x,y,_B),dis(x,b+c-1,_B));if(B<_b)return false;B-=_b;
			_d=route(dis(x,y,_D),dis(x,b+c-1,_D));if(D<_d)return false;D-=_d;
			y=b+c-1;
		}
		_a=route(dis(x,y,_A),dis(n,n,_A));if(A<_a)return false;A-=_a;
		_b=route(dis(x,y,_B),dis(n,n,_B));if(B<_b)return false;B-=_b;
		_d=route(dis(x,y,_D),dis(n,n,_D));if(D<_d)return false;D-=_d;
		return true;
	}
	_a=route(dis(_A,_A),dis(n,n,_A));if(A<_a)return false;A-=_a;
	_b=route(dis(_A,_B),dis(n,n,_B));if(B<_b)return false;B-=_b;
	_d=route(dis(_A,_D),dis(n,n,_D));if(D<_d)return false;D-=_d;
	_a=route(dis(x,y,_A),dis(a+c-1,b+c-1,_A));if(A<_a)return false;
	ll bl=route(dis(x,y,_B),dis(x,b+c-1,_B))+route(dis(x,b+c-1,_B),dis(_A,_B));
	ll dr=route(dis(x,y,_D),dis(x,b+c-1,_D))+route(dis(x,b+c-1,_D),dis(_A,_D));
	ll br=route(dis(x,y,_B),dis(a+c-1,y,_B))+route(dis(a+c-1,y,_B),dis(_A,_B));
	ll dl=route(dis(x,y,_D),dis(a+c-1,y,_D))+route(dis(a+c-1,y,_D),dis(_A,_D));
	if(B<bl)return false;if(D<dl)return false;
	assert(bl+dr==br+dl);
	ll sum=bl+dr;
	if(D<sum-min(br,B))return false;
	return true;
}
int main(){
	scanf("%d%lld%d%d%d",&n,&T,&a,&b,&c);
	if(!che(1,1,T,T,T,T)){puts("Impossible");return 0;}
	int x=1,y=1;ll A=T,B=T,C=T,D=T;
	while(x!=n||y!=n){
		if(x!=n&&(y==n||che(x+1,y,A-dis(x+1,y,_A),B-dis(x+1,y,_B),C-dis(x+1,y,_C),D-dis(x+1,y,_D))))
			x++,A-=dis(x,y,_A),B-=dis(x,y,_B),C-=dis(x,y,_C),D-=dis(x,y,_D),putchar('R');
		else y++,A-=dis(x,y,_A),B-=dis(x,y,_B),C-=dis(x,y,_C),D-=dis(x,y,_D),putchar('U');
	}
	return 0;
}