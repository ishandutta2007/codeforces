#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
int p[N],s[N<<2],t[N<<2],v,w;
void upd(int k,int l,int r){
	if(r<=v){s[k]+=w,t[k]+=w;return;}
	int m=l+r>>1,a=k<<1,b=a|1;
	s[a]+=t[k],s[b]+=t[k],t[a]+=t[k],t[b]+=t[k],t[k]=0;
	upd(a,l,m);
	if(m<v)upd(b,m+1,r);
	s[k]=max(s[a],s[b]);
}
int main(){
	int n,i,j;
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d",&j),p[j]=i;
	printf("%d ",j=n),v=p[j],w=1,upd(1,1,n);
	for(i=1;i<n;++i){
		scanf("%d",&v),w=-1,upd(1,1,n);
		while(s[1]<=0)v=p[--j],w=1,upd(1,1,n);
		printf("%d ",j);
	}
	return 0;
}