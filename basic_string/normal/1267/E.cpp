#include<bits/stdc++.h>
using namespace std;
int a[109][109],b[109];
struct P{
	int a,id;
	inline bool operator<(P x)const{return a>x.a;}
}p[109];
int main(){
	int n,m,i,j,k,l,s;
	scanf("%d%d",&n,&m),s=m+1;
	for(i=1;i<=m;++i){
		for(j=1;j<=n;++j)scanf("%d",&a[i][j]); 
	}
	for(i=1;i<n;++i){
		for(j=1;j<=m;++j)b[j]=a[j][n]-a[j][i];
		sort(b+1,b+m+1);
		k=0,j=1;
		while(k<=0&&j<=m+1)k+=b[j],++j;
		if(s>m-j+2)s=m-j+2,l=i;
	}
	printf("%d\n",s);
	if(s){
		for(j=1;j<=m;++j)p[j].id=j,p[j].a=a[j][n]-a[j][l];
		sort(p+1,p+m+1);
		for(j=1;j<=s;++j)printf("%d ",p[j].id);
	}
	return 0;
}