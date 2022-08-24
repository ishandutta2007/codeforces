#include<stdio.h>
#include<algorithm>
using namespace std;
struct A{
	int P,len;
	bool operator <(const A &k)const{
		return P*len*(100-k.P)-k.P*k.len*(100-P)>0;
	}
}w[50001];
double S,t;
int n,i;
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d%d",&w[i].len,&w[i].P);
	}
	sort(w+1,w+n+1);
	for(i=1;i<=n;i++){
		S+=10000.0*w[i].len+t*(100.0-w[i].P);
		t+=w[i].P*w[i].len;
	}
	printf("%.10lf\n",S/10000.0);
}