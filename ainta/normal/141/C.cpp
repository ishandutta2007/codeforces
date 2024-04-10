#include<stdio.h>
#include<algorithm>
using namespace std;
struct A{
	char p[20];
	int a;
	bool operator()(A p,A q){
		if(p.a<q.a)return 1;
		return 0;
	}
}D[3010];
int n,i,j,k,w[3010],v[3010],c;
int main(){
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%s",D[i].p);
		scanf("%d",&D[i].a);}
	stable_sort(D,D+n,A());
	for(i=n-1;i>=0;i--){
		if(i==n-1){
			w[i]=D[i].a+1;
			v[w[i]]=1;
			continue;}
		c=0;
		for(j=1;j<=n;j++){
			if(v[j]==0)c++;
			if(c==D[i].a+1)break;
		}
		if(j==n+1)break;
		w[i]=j;
		v[j]=1;}
	if(i!=-1){
		printf("-1\n");
		return 0;}
	for(i=0;i<n;i++)printf("%s %d\n",D[i].p,n+1-w[i]);
}