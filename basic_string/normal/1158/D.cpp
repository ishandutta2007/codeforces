#include<bits/stdc++.h>
using namespace std;
const int N=2009;
int x[N],y[N];
bool v[N];
char s[N];
bool le(int a,int b,int c){
	return(x[b]-x[a])*1ll*(y[c]-y[a])>(x[c]-x[a])*1ll*(y[b]-y[a]);
}
int main(){
	int n,i,j=0,l,k;
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d%d",x+i,y+i);
	scanf("%s",s+2);
	for(i=1;i<=n;++i)if(!j||x[i]<x[j])j=i;
	for(v[j]=1,printf("%d ",j),i=2;i<n;++i){
		l=0;
		if(s[i]=='L'){
			for(k=1;k<=n;++k)if(!v[k]&&(!l||!le(j,l,k)))l=k;
		}else{
			for(k=1;k<=n;++k)if(!v[k]&&(!l||le(j,l,k)))l=k;
		}
		v[j=l]=1,printf("%d ",j);
	}
	for(i=1;i<=n;++i)if(!v[i])printf("%d ",i);
	return 0;
}