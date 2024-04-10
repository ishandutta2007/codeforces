#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 5555;
LL sq(int x){
	return (LL)x*x;
}
int n,x[N],y[N],a[N];
LL dis(int i,int j){
	return sq(x[i]-x[j])+sq(y[i]-y[j]);
}
int main(){
	int T,i,j,p,r;
	LL s;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d%d",x+i,y+i);
	p=1;
	a[1]=1;
	printf("1");
	for(i=1;i<=n-1;i=i+1){
		s=0,r=0;
		for(j=1;j<=n;j=j+1)
			if(!a[j])
				if(dis(p,j)>s)
					s=dis(p,j),r=j;
		p=r;
		a[p]=1;
		printf(" %d",p);
	}
	return 0;
}