#include<stdio.h>
#include<algorithm>
using namespace std;
struct A{
	int a,b;
	bool operator()(A p,A q){return p.a<q.a;}
}w[100010];
int n,h,i,Max,L,T,TM,R[100010];
int main()
{
	scanf("%d%d",&n,&h);
	for(i=1;i<=n;i++){
		scanf("%d",&w[i].a);
		w[i].b=i;
	}
	stable_sort(w+1,w+n+1,A());
	L=0,Max=w[n].a+w[n-1].a-w[2].a-w[1].a;
	if(n==2){printf("%d\n1 1\n",Max);return 0;}
	for(i=1;i<n;i++){
		if(i==1){
			T=w[1].a+w[2].a+h;
			if(T>w[2].a+w[3].a)T=w[2].a+w[3].a;
		}
		else T=w[1].a+w[2].a;
		if(i==n-1){
			TM=w[n].a+w[n-1].a+h;
		}
		else{
			TM=w[n].a+w[n-1].a;
			if(w[n].a+w[i].a+h>TM)TM=w[n].a+w[i].a+h;}
		if(TM-T<Max)Max=TM-T,L=i;
	}
	printf("%d\n",Max);
	for(i=1;i<=L;i++)R[w[i].b]=1;
	for(i=L+1;i<=n;i++)R[w[i].b]=2;
	for(i=1;i<=n;i++)printf("%d ",R[i]);
}