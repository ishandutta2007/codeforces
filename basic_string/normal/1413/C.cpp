#include<bits/stdc++.h>
using namespace std;
const int N=1e5+3;
int a[9],b[N],d[N];
struct T{
	int x,y;
	bool operator<(T a)const{return x<a.x;}
}c[N*6];
int main(){
	int T,n,m,i,j,k,t=0,s=0,ans=2e9;
	for(i=0;i<6;++i)scanf("%d",a+i);
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d",b+i);
	sort(a,a+6),sort(b+1,b+n+1);
	for(i=0;i<6;++i)for(j=1;j<=n;++j)c[++t]={b[j]-a[i],j};
	sort(c+1,c+t+1),j=0;
	for(i=1;i<=t;++i){
		while(j<t&&s<n){
			++j;
			d[c[j].y]++;
			if(d[c[j].y]==1)++s;
		}
		if(s==n)ans=min(ans,c[j].x-c[i].x);
		d[c[i].y]--;
		if(d[c[i].y]==0)--s;
	}
	printf("%d",ans);
	return 0;
}