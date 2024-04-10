#include<stdio.h>
#include<algorithm>
using namespace std;
int IT[101000],n,i,w[101000];
long long S,Mod=1000000007,Res,s;
struct A{
	int a,b;
	bool operator <(const A &p)const{
		return a!=p.a?a<p.a:b<p.b;
	}
}ord[101000];
long long Sum(int a){
	long long s=0;
	while(a){
		s+=IT[a];
		a-=(a&-a);
	}
	return s;
}
void change(int a,int b){
	while(a<=n){
		IT[a]+=b;
		if(IT[a]>=Mod)IT[a]-=Mod;
		a+=(a&-a);
	}
}
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&w[i]);
		ord[i].a=w[i],ord[i].b=i;
	}
	sort(ord+1,ord+n+1);
	for(i=1;i<=n;i++){
		S=(Sum(ord[i].b)+1LL)%Mod*ord[i].a;
		if(ord[i].a==ord[i-1].a)S+=Mod-s;
		else s=0;
		S%=Mod;
		change(ord[i].b,S);
		s=(s+S)%Mod;
	}
	Res+=Sum(n);
	printf("%lld\n",Res%Mod);
}