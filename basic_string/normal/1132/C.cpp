#include<bits/stdc++.h>
using namespace std;
const int N=1e4+3;
int s[N],l[N],r[N],s1[N],s2[N];
struct P{
	int l,r;
	bool operator<(P a)const{return l<a.l;}
}p[N];
int main(){
	int m,n,i,j,k,ll,rr,w,ans=0,mn=1e9;
	scanf("%d%d",&m,&n);
	for(i=1;i<=n;++i){
		scanf("%d%d",&j,&k),p[i].l=j,p[i].r=k;
		++s[j],--s[k+1];
	}
	sort(p+1,p+n+1);
	for(i=1;i<=m;++i)s[i]+=s[i-1],ans+=(s[i]>0),s1[i]=(s[i]==1)+s1[i-1],s2[i]=(s[i]==2)+s2[i-1];
	for(i=1;i<=n;++i)for(j=i+1;j<=n;++j){
		ll=p[j].l,rr=min(p[j].r,p[i].r),w=s1[p[i].r]-s1[p[i].l-1]+s1[p[j].r]-s1[p[j].l-1];
		if(ll<=rr)w+=s2[rr]-s2[ll-1];
		mn=min(mn,w);
	}
	printf("%d",ans-mn);
	return 0;
}