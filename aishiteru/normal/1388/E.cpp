#include<bits/stdc++.h>
#define it register int
#define ct const int
#define il inline
using namespace std;
typedef long long ll;
#define rll register ll
#define cll const ll
typedef double db;
#define rdb register db
#define cdb const db
namespace io{
	il char nc(){
		static char buf[100000],*p1=buf,*p2=buf;
		return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++; 
	}
	template <class I> 
	il void fr(I &num){
		num=0;register char c=nc();it p=1;
		while(c<'0'||c>'9') c=='-'?p=-1,c=nc():c=nc();
		while(c>='0'&&c<='9') num=num*10+c-'0',c=nc();
		num*=p;
	} 
}
using io :: fr;
const int N=4000005;
int n,tot,cb;
db x[N],y[N],w[N],b[N];
pair<db,int> a[N];
template <class I>
il void ckMin(I&p,I q){p=(p<q?p:q);}
template <class I>
il void ckMax(I&p,I q){p=(p>q?p:q);}
il void ms(){
	auto calc = [&] (cdb k){
		rdb mn=1e18,mx=-1e18;
		for(it i=1;i<=n;++i)
			ckMin(mn,x[i]-k*w[i]),ckMax(mx,y[i]-k*w[i]);
		return mx-mn;
	};
	it l=1,r=cb,m1,m2,mid;rdb ans=1e18,w1,w2;
	while(r-l>=3)
		mid=(r-l)/3,m1=l+mid,m2=r-mid,w1=calc(b[m1]),w2=calc(b[m2]),w1<w2?ckMin(ans,w1),r=m2:l=m1;
	while(l<=r) ckMin(ans,calc(b[l])),++l;
	printf("%.8lf",ans);
}
int main(){ 
	scanf("%d",&n);it i,j;
	for(i=1;i<=n;++i) scanf("%lf%lf%lf",&x[i],&y[i],&w[i]);
	for(i=1;i<=n;++i)
		for(j=1;j<=n;++j)
			w[i]>w[j]?a[++tot]=make_pair((x[i]-y[j])/(w[i]-w[j]),1),a[++tot]=make_pair((y[i]-x[j])/(w[i]-w[j]),-1),0:0;
	std::sort(a+1,a+1+tot);if(!tot) a[++tot]=make_pair(0,0);it s=0;
	for(i=1;i<=tot;++i){
		if(!s) b[++cb]=a[i].first;
		if(s==1&&a[i].second==-1) b[++cb]=a[i].first;
		s+=a[i].second;
	}
	ms();
	return 0;
}