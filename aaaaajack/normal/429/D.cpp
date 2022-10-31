#include<cstdio>
#include<algorithm>
#include<cmath>
#define N 100010
#define inf (1LL<<60)
using namespace std;
int y[N],st[N],tmp[N];
inline long long sq(int x){
	return 1LL*x*x;
}
long long dnc(int l,int r){
	if(r-l==1) return inf;
	int m=(l+r)/2,i,j,sz;
	long long d = min( dnc(l,m), dnc(m,r) );
	for(i=m,sz=0;i<r;i++){
		if(sq(st[i]-st[m-1])<d) tmp[sz++]=st[i];
	}
	for(i=l,j=0;i<m;i++){
		while(j<sz&&y[tmp[j]]<y[st[i]]) j++;
		if(j<sz) d = min( d, sq(tmp[j]-st[i])+sq(y[tmp[j]]-y[st[i]]) );
		if(j+1<sz)d = min( d, sq(tmp[j+1]-st[i])+sq(y[tmp[j+1]]-y[st[i]]) );
	}
	for(i=l,sz=0;i<m;i++){
		if(sq(st[i]-st[m])<d) tmp[sz++]=st[i];
	}
	for(i=m,j=0;i<r;i++){
		while(j<sz&&y[tmp[j]]<y[st[i]]) j++;
		if(j<sz) d = min( d, sq(tmp[j]-st[i])+sq(y[tmp[j]]-y[st[i]]) );
		if(j+1<sz)d = min( d, sq(tmp[j+1]-st[i])+sq(y[tmp[j+1]]-y[st[i]]) );
	}
	for(i=l,j=m,sz=l;i<m;i++){
		while(j<r&&y[st[j]]<y[st[i]]) tmp[sz++]=st[j++];
		tmp[sz++]=st[i];
	}
	while(j<r) tmp[sz++]=st[j++];
	for(i=l;i<r;i++) st[i]=tmp[i];
	return d;
}
int main(){
	int n,i,j,k,acc=0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&y[i]);
		st[i]=i;
		acc=(y[i]+=acc);
	}
	printf("%I64d\n",dnc(0,n));
	return 0;
}