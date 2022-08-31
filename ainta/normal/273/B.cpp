#include<stdio.h>
#include<algorithm>
using namespace std;
int n,i,c,C,C2[200001],cc,j,t;
__int64 M,R;
struct A{
	int a,b;
	bool operator <(const A &p)const{
		return a!=p.a?a<p.a:b<p.b;
	}
}w[200001];
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&w[c].a);
		w[c++].b=i;
	}
	for(i=1;i<=n;i++){
		scanf("%d",&w[c].a);
		w[c++].b=i;
	}
	scanf("%I64d",&M);
	sort(w,w+c);
	for(i=0;i<c;i++){
		if(i && w[i].a!=w[i-1].a){
			cc++;
		}
		C2[cc]++;
		if(i && w[i].a==w[i-1].a &&w[i].b==w[i-1].b)C++;
	}
	R=1;
	for(i=0;i<=cc;i++){
		for(j=C2[i];j>=1;j--){
			t=j;
			while(C&&t%2==0){
				t/=2;
				C--;
			}
			R*=(__int64)t;
			R%=M;
		}
	}
	printf("%I64d\n",R);
}