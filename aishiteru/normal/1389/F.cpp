#include<stdio.h>
#include<algorithm>
#define it register int
#define ct const int
#define il inline
using namespace std;
typedef long long ll;
#define rll register ll
#define cll const ll
#define P 1000000007
const int N=1600005;
struct ky{
	int l,r,c;
	bool operator < (const ky&p)const{return r<p.r;}
}a[N];
int n,s[N][2],tag[N][2],mx[2],b[N];
template <class I> 
il I Max(I p,I q){return p>q?p:q;}
template <class I>
il void ckMax(I&p,I q){p=(p>q?p:q);}
il void pd(ct rt,ct id){
	ct ls=rt<<1,rs=ls|1;
	tag[ls][id]+=tag[rt][id],tag[rs][id]+=tag[rt][id],s[ls][id]+=tag[rt][id],s[rs][id]+=tag[rt][id],tag[rt][id]=0;
}
il void upd(ct rt,ct l,ct r,ct u,ct v,ct x,ct id){
//	printf("upd1 : %d %d %d %d %d %d %d\n",rt,l,r,u,v,x,s[rt][id]);
	if(u>v) return;
	if(l>=u&&r<=v) return s[rt][id]+=x,tag[rt][id]+=x,void();
	if(tag[rt][id]) pd(rt,id);
	ct mid=l+r>>1,ls=rt<<1,rs=ls|1;
	if(u<=mid) upd(ls,l,mid,u,v,x,id);
	if(v>mid) upd(rs,mid+1,r,u,v,x,id);
	s[rt][id]=Max(s[ls][id],s[rs][id]);
}
il void upd(ct rt,ct l,ct r,ct pos,ct x,ct id){
	//printf("upd2 : %d %d %d %d %d %d\n",rt,l,r,pos,x,s[rt][id]);
	if(l==r) return s[rt][id]=x,void();
	if(tag[rt][id]) pd(rt,id);
	ct mid=l+r>>1,ls=rt<<1,rs=ls|1;
	pos<=mid?upd(ls,l,mid,pos,x,id):upd(rs,mid+1,r,pos,x,id);
	s[rt][id]=Max(s[ls][id],s[rs][id]);
}
il int que(ct rt,ct l,ct r,ct u,ct v,ct id){
	//printf("que : %d %d %d %d %d %d\n",rt,l,r,u,v,s[rt][id]);
	if(u>v) return 0;
	if(l>=u&&r<=v) return s[rt][id];
	if(tag[rt][id]) pd(rt,id);
	ct mid=l+r>>1,ls=rt<<1,rs=ls|1;it ans=0;
	if(u<=mid) ans=que(ls,l,mid,u,v,id);
	if(v>mid) ans=Max(ans,que(rs,mid+1,r,u,v,id));
	return ans;
}
int main(){
	scanf("%d",&n);it i;
	for(i=1;i<=n;++i) scanf("%d%d%d",&a[i].l,&a[i].r,&a[i].c),a[i].c&=1,b[++*b]=a[i].l,b[++*b]=a[i].r;
	std::sort(b+1,b+1+*b);//*b=std::unique(b+1,b+1+*b)-b-1;
	for(i=1;i<=n;++i) a[i].l=std::lower_bound(b+1,b+1+*b,a[i].l)-b,a[i].r=std::lower_bound(b+1,b+1+*b,a[i].r)-b;
	std::sort(a+1,a+1+n);
	for(it i=1,j=1,k;i<=n;i=j){
		while(j<=n&&a[j].r==a[i].r) upd(1,0,b[0],0,a[j].l-1,1,a[j].c),++j;
	//	printf("l : %d r : %d\n",i,j-1);printf("mx : ");
		for(k=i,mx[0]=mx[1]=0;k<j;++k) ckMax(mx[a[k].c^1],que(1,0,b[0],0,a[k].l-1,a[k].c));//printf("%d ",mx[a[k].c^1]);puts("");
		upd(1,0,b[0],a[i].r,mx[0],0),upd(1,0,b[0],a[i].r,mx[1],1);
	//	printf("%d %d\n",mx[0],mx[1]);
	}
	printf("%d",Max(que(1,0,b[0],0,b[0],0),que(1,0,b[0],0,b[0],1)));
	return 0;
}