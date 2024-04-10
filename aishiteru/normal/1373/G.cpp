#include<stdio.h>
#include<set>
#define it register int
#define ct const int
#define il inline
const int N=2000005;
typedef long long ll;
std::set<ll> S;
int s[N],t[N],n,k,m;
il int Max(ct p,ct q){return p>q?p:q;}
il void upd(ct rt,ct l,ct r,ct pos,ct x){
	if(l==r) return s[rt]+=x,t[rt]=(s[rt]?l+s[rt]:0),void();
	ct mid=l+r>>1,ls=rt<<1,rs=ls|1;
	pos<=mid?upd(ls,l,mid,pos,x):upd(rs,mid+1,r,pos,x);
	s[rt]=s[ls]+s[rs],t[rt]=Max(t[ls]+s[rs],t[rs]);
}
int main(){
	scanf("%d%d%d",&n,&k,&m);it x,y,l;ct mx=(n<<1)+10;register ll val;
	while(m--)
		scanf("%d%d",&x,&y),l=y+(x>k?x-k:k-x),val=x+(0ll+y)*n,S.count(val)?S.erase(val),upd(1,0,mx,l,-1):(S.insert(val),upd(1,0,mx,l,1)),printf("%d\n",t[1]-1-n>0?t[1]-1-n:0);
	return 0;
}