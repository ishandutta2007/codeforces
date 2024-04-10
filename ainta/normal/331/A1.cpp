#include<stdio.h>
#include<algorithm>
using namespace std;
#define INF 2000000001
int w[300001],SZ=524288;
long long IT[2000001];
bool v[300001];
struct A{
	int a,b;
	bool operator <(const A &p)const{
		return a!=p.a?a<p.a:b<p.b;
	}
}o[300001];
long long Sum(int a,int b){
	long long S=0;
	while(a<=b){
		if(a&1)S+=IT[a];
		if(!(b&1))S+=IT[b];
		a=(a+1)>>1,b=(b-1)>>1;
	}
	return S;
}
int main()
{
	int n,i,t,x1,x2;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&w[i]);
		o[i].a=w[i],o[i].b=i;
		if(w[i]>0){
			t=SZ+i;
			while(t){
				IT[t]+=w[i];
				t>>=1;
			}
		}
	}
	sort(o+1,o+n+1);
	t=1;
	long long Res=-INF,S;
	while(t<=n){
		if(t==n||o[t].a!=o[t+1].a){
			t++;
			continue;
		}
		i=t;
		while(t<n && o[t].a==o[t+1].a)t++;
		S=o[t].a*2+Sum(SZ+o[i].b+1,SZ+o[t].b-1);
		if(Res<S)Res=S,x1=o[i].b,x2=o[t].b;
		t++;
	}
	t=0;
	for(i=1;i<=n;i++){
		if(i<x1 || i>x2)v[i]=true,t++;
		else if(i!=x1 && i!=x2 && w[i]<0)v[i]=true,t++;
	}
	printf("%lld %d\n",Res,t);
	for(i=1;i<=n;i++)if(v[i])printf("%d ",i);
}