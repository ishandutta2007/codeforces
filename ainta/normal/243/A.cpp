#include<stdio.h>
#include<algorithm>
using namespace std;
int n,w[100001],i,x,j,C,P[32],a[32],b[32],c,T,tt;
struct A{
	int a,b;
	bool operator()(A p,A q){return p.a<q.a;}
}z[32];
bool v[1048577];
int main(){
	scanf("%d",&n);
	for(i=0;i<20;i++)a[i]=1<<i;
	for(i=1;i<=n;i++){
		scanf("%d",&w[i]);
		if(!v[w[i]])v[w[i]]=1,C++;
		for(j=0;j<20;j++){if(a[j]&w[i])b[j]=1;else b[j]=0;}
		c=0;
		for(j=0;j<20;j++){
			if(!b[j]){
				if(P[j])z[++c].a=P[j],z[c].b=j;
			}
			else P[j]=i;
		}
		sort(z+1,z+c+1,A());
		T=w[i];
		for(j=c;j>=1;j--){
			tt=j;T+=1<<z[j].b;
			while(tt>1&&z[tt].a==z[tt-1].a)T+=1<<z[--tt].b;
			if(!v[T])v[T]=1,C++;
			j=tt;
		}
	}
	printf("%d\n",C);
}