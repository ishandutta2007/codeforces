#include<bits/stdc++.h>
using namespace std;
typedef unsigned int ui;
typedef long long ll;
int n,p,q;
ui C[150],res;
void exgcd(ll a,ll b,ll&x,ll&y){if(!b)x=1,y=0;else exgcd(b,a%b,y,x),y-=a/b*x;}
ui inv(ui a){ll x,y;exgcd(a,(1ll<<32),x,y);return x;}
int main(){
	scanf("%d%d%d",&n,&p,&q);
	ui val=1;int num=0;
	auto ins=[&](int x,int tp){
		while(!(x&1))x>>=1,num+=tp;
		if(tp==1)val*=x;else val*=inv(x);
	};
	for(int i=0;i<=min(p,n-1);i++){
		C[i]=val<<num;
		ins(n-i,1),ins(i+1,-1);
	}
//	for(int i=0;i<=min(p,n-1);i++)printf("%u ",C[i]);
	for(int i=1;i<=q;i++){
		ui val=0,x=i;
		for(int j=0;j<=min(p,n-1);j++)val+=C[j]*x,x*=i;
		res^=val;
	}
	printf("%u\n",res);
	return 0;
}