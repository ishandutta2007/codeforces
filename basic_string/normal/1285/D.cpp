#include<bits/stdc++.h>
using namespace std;
int n,a[31][100009];
int get(int x,int y,int t){
	register int i;
	register bool f0=0,f1=0;
	for(i=1;i<=t;++i)if(a[x][i]&y)f1=1;else f0=1;
	if(!(f0&&f1)){
		if(!x)return 0;
		for(i=1;i<=t;++i)a[x-1][i]=a[x][i];
		return get(x-1,y>>1,t);
	}
	if(!x)return 1;
	register int p=0,q;
	for(i=1;i<=t;++i)if(a[x][i]&y)a[x-1][++p]=a[x][i];
	q=get(x-1,y>>1,p),p=0;
	for(i=1;i<=t;++i)if(!(a[x][i]&y))a[x-1][++p]=a[x][i];
	return min(q,get(x-1,y>>1,p))+y;
}
int main(){
	register int i;
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d",a[29]+i);
	printf("%d",get(29,1<<29,n));
	return 0;
}//+++