#include<stdio.h>
#include<algorithm>
using namespace std;
struct A{
	__int64 a,b;
	bool operator <(const A &p)const{
		return a<p.a;
	}
}w[100001];
int n,i,k;
__int64 a,b,t,c;
int main()
{
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%I64d%I64d",&w[i].a,&w[i].b);
	}
	sort(w,w+n);
	for(i=1;i<n;i++){
		if(w[i].a-w[i-1].a>15)continue;
		t=1<<(2*(w[i].a-w[i-1].a));
		a=w[i].b,b=w[i-1].b;
		b-=a*t;
		if(b<=0)continue;
		w[i].b+=(b-1)/t+1;
	}
	c=w[n-1].a+1;
	while(1){
		t=1<<((c-w[n-1].a)*2);
		if(t>=w[n-1].b)break;
		c++;
	}
	printf("%I64d\n",c);
}