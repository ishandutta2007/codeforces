#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
int a[N],b[N];
struct P{
	int s,t;
	inline bool operator<(P a)const{return s<a.s||(s==a.s&&t<a.t);}
}s[N];
int main(){
	int i,j,k,p,q,n,u,v,t=0;
	scanf("%d",&n);
	for(i=1;i<=n;++i){
		scanf("%d",&j),a[i]=a[i-1],b[i]=b[i-1];
		if(j==1)++a[i];else ++b[i];
	}
	for(i=max(a[n],b[n]);i;--i){
		j=p=q=0;
		while(1){
			if(a[n]-a[j]<i&&b[n]-b[j]<i)break;
			u=lower_bound(a+1,a+n+1,a[j]+i)-a;
			v=lower_bound(b+1,b+n+1,b[j]+i)-b;
			k=min(u,v);
			if(a[k]-a[j]==i)++p;
			else ++q;
			if(k==n){
				if(p>q&&a[n]-a[j]==i)s[++t]={p,i};
				else if(p<q&&b[n]-b[j]==i)s[++t]={q,i};
				break;
			}
			j=k;
		}
	}
	sort(s+1,s+t+1);
	printf("%d\n",t);
	for(i=1;i<=t;++i)printf("%d %d\n",s[i].s,s[i].t);
	return 0;
}