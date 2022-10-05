#include<bits/stdc++.h>
using namespace std;
const int N=4e5+3;
using ll=long long;
ll o;
struct T{ll s;int z,l,r;}s[N*19];
int f[N],g[N],r[N],i,u;
int gf(int x){return f[x]==x?x:f[x]=gf(f[x]);}
void upd(int&k,int l,int r){
	if(k=++i,s[k].s+=u,++s[k].z,l==r)return;
	int m=l+r>>1;
	u>m?upd(s[k].r,m+1,r):upd(s[k].l,l,m);
}
void mg(int&k,int t){if(k&&t)o-=s[s[k].l].s*1ll*s[s[k].r].z+s[s[t].l].s*1ll*s[s[t].r].z,mg(s[k].l,s[t].l),mg(s[k].r,s[t].r),o+=s[s[k].l].s*1ll*s[s[k].r].z,s[k].s+=s[t].s,s[k].z+=s[t].z;else k|=t;}
void wk(int x,int y){x=gf(x),y=gf(y),f[y]=x,g[x]=g[y],o-=s[r[y]].s*1ll*(y-x),mg(r[x],r[y]);}
int main(){
	int n,i,a,b;
	for(scanf("%d",&n),i=1;i<=n;printf("%lld\n",o),++i){
		scanf("%d%d",&a,&b),o-=a*1ll*b,a=r[a]?g[gf(a)]+1:a,f[a]=g[a]=a,o+=a*1ll*b,u=b,upd(r[a],1,n);
		if(r[a-1])wk(a-1,a);
		if(r[a+1])wk(a,a+1);
	}
	return 0;
}