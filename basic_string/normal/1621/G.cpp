#include<bits/stdc++.h>
using namespace std;
const int N=2e5+3,P=1e9+7;
int T,n,a[N],pr[N],sf[N],id,t[N],v[N];
struct A{
	int a,i;
}p[N],q[N];
bool b[N];
void add(int x,int y){
	for(;x<=n;x+=x&-x){
		if(v[x]!=id)v[x]=id,t[x]=0;
		t[x]=(t[x]+y)%P;
	}
}
int sum(int x){
	int r=0;
	for(;x;x&=x-1)if(v[x]==id)r=(r+t[x])%P;
	return r;
}
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int i,j,la,m,o,ans;
	for(cin>>T;T--;cout<<(ans%P+P)%P<<'\n'){
		cin>>n,ans=0;
		for(i=1;i<=n;++i)cin>>a[i],p[i].a=a[i],p[i].i=i,b[i]=0;
		for(i=n,la=0;i;--i)if(p[i].a>la)b[i]=1,la=p[i].a;
		sort(a+1,a+n+1);
		for(i=1;i<=n;++i)p[i].a=lower_bound(a+1,a+n+1,p[i].a)-a;
		for(i=1,++id;i<=n;++i)pr[i]=(sum(p[i].a-1)+1)%P,add(p[i].a,pr[i]),p[i].a=n-p[i].a+1;
		for(i=n,++id;i;--i)sf[i]=(sum(p[i].a-1)+1)%P,add(p[i].a,sf[i]);
		sort(p+1,p+n+1,[](A x,A y){return x.a>y.a||(x.a==y.a&&x.i>y.i);});
		for(i=la=1;i<=n;++i)if(b[p[i].i]){
			for(m=0,j=la;j<=i;++j)if(p[j].i<=p[i].i)q[++m]=p[j];
			sort(q+1,q+m+1,[](A x,A y){return x.i>y.i;});
			++id,add(q[1].a,1);
			for(j=2;j<=m;++j)o=sum(q[j].a-1),add(q[j].a,o),ans=(ans+(sf[q[j].i]-o)*1ll*pr[q[j].i])%P;
			la=i+1;
		}
	}
	return 0;
}