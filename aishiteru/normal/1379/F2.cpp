#include<stdio.h>
#include<set>
#include<algorithm>
#define it register int
#define ct const int
#define il inline
#define pi pair<int,int>
using namespace std;
const int N=2000005;
multiset<int> ms[N];
set<pi> S;
int n,m,Q,mn[N],mx[N],s[N],x,y,p[N];
il void B(ct rt,ct l,ct r){
	mn[rt]=2e9,mx[rt]=s[rt]=0;
	if(l==r) return p[l]=rt,void();
	ct mid=l+r>>1;
	B(rt<<1,l,mid),B(rt<<1|1,mid+1,r);
}
il int Max(ct p,ct q){return p>q?p:q;}
il int Min(ct p,ct q){return p<q?p:q;}
il void upd(){
	it rt=p[x],ls,rs;
	x&1?mn[rt]=(ms[x].size()?*ms[x].begin():2e9):mx[rt]=(ms[x].size()?*ms[x].rbegin():0);
	while(rt>>=1) ls=rt<<1,rs=ls|1,s[rt]=(s[ls]||s[rs]||(mn[ls]<mx[rs])),mn[rt]=Min(mn[ls],mn[rs]),mx[rt]=Max(mx[ls],mx[rs]); 
}
int main(){
	scanf("%d%d%d",&n,&m,&Q),B(1,1,n<<1);pi now;
	while(Q--) scanf("%d%d",&x,&y),now=pi(x,y),S.count(now)?ms[x].erase(ms[x].find(y)),S.erase(now),upd():(ms[x].insert(y),S.insert(now),upd()),s[1]?puts("NO"):puts("YES");
	return 0;
}