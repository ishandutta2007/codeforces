#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define fz(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define ffe(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define fill0(a) memset(a,0,sizeof(a))
#define fill1(a) memset(a,-1,sizeof(a))
#define fillbig(a) memset(a,63,sizeof(a))
#define pb push_back
#define ppb pop_back
#define mp make_pair
template<typename T1,typename T2> void chkmin(T1 &x,T2 y){if(x>y) x=y;}
template<typename T1,typename T2> void chkmax(T1 &x,T2 y){if(x<y) x=y;}
typedef pair<int,int> pii;
typedef long long ll;
template<typename T> void read(T &x){
	x=0;char c=getchar();T neg=1;
	while(!isdigit(c)){if(c=='-') neg=-1;c=getchar();}
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
	x*=neg;
}
const int MAXN=1.2e5;
int n,qu,a[MAXN+5];ll ans[MAXN+5];
struct Query{int l,r;} q[MAXN+5];
vector<int> qv[MAXN+5];
struct node{
	int l,r,mn,num,add_lz;
	ll sum,cnt_lz;
} s[MAXN*4+5];
void pushup(int k){
	s[k].mn=min(s[k<<1].mn,s[k<<1|1].mn);
	s[k].num=(s[k<<1].num)*(s[k<<1].mn==s[k].mn)+(s[k<<1|1].num)*(s[k<<1|1].mn==s[k].mn);
	s[k].sum=s[k<<1].sum+s[k<<1|1].sum;
}
void pushdown(int k){
	if(s[k].add_lz){
		s[k<<1].add_lz+=s[k].add_lz;s[k<<1].mn+=s[k].add_lz;
		s[k<<1|1].add_lz+=s[k].add_lz;s[k<<1|1].mn+=s[k].add_lz;
		s[k].add_lz=0;
	}
	if(s[k].cnt_lz){
		if(s[k<<1].mn==s[k].mn) s[k<<1].cnt_lz+=s[k].cnt_lz,s[k<<1].sum+=s[k].cnt_lz*s[k<<1].num;
		if(s[k<<1|1].mn==s[k].mn) s[k<<1|1].cnt_lz+=s[k].cnt_lz,s[k<<1|1].sum+=s[k].cnt_lz*s[k<<1|1].num;
		s[k].cnt_lz=0;
	}
}
void build(int k,int l,int r){
	s[k].l=l;s[k].r=r;if(l==r){s[k].num=1;return;}
	int mid=(l+r)>>1;build(k<<1,l,mid);build(k<<1|1,mid+1,r);
	pushup(k);
}
void modify(int k,int l,int r,int x){
	if(l>r) return;
	if(l<=s[k].l&&s[k].r<=r){s[k].mn+=x;s[k].add_lz+=x;return;}
	pushdown(k);int mid=(s[k].l+s[k].r)>>1;
	if(r<=mid) modify(k<<1,l,r,x);
	else if(l>mid) modify(k<<1|1,l,r,x);
	else modify(k<<1,l,mid,x),modify(k<<1|1,mid+1,r,x);
	pushup(k);
}
void addcnt(int k,int l,int r,int x){
	if(l>r) return;
	if(l<=s[k].l&&s[k].r<=r){
		if(!s[k].mn) s[k].cnt_lz+=x,s[k].sum+=s[k].num;
		return;
	} pushdown(k);int mid=(s[k].l+s[k].r)>>1;
	if(r<=mid) addcnt(k<<1,l,r,x);
	else if(l>mid) addcnt(k<<1|1,l,r,x);
	else addcnt(k<<1,l,mid,x),addcnt(k<<1|1,mid+1,r,x);
	pushup(k);
}
int querynum(int k,int l,int r){
	if(l<=s[k].l&&s[k].r<=r) return (!s[k].mn)*s[k].num;
	pushdown(k);int mid=(s[k].l+s[k].r)>>1;
	if(r<=mid) return querynum(k<<1,l,r);
	else if(l>mid) return querynum(k<<1|1,l,r);
	else return querynum(k<<1,l,mid)+querynum(k<<1|1,mid+1,r);
}
ll query(int k,int l,int r){
	if(l<=s[k].l&&s[k].r<=r) return s[k].sum;
	pushdown(k);int mid=(s[k].l+s[k].r)>>1;
	if(r<=mid) return query(k<<1,l,r);
	else if(l>mid) return query(k<<1|1,l,r);
	else return query(k<<1,l,mid)+query(k<<1|1,mid+1,r);
}
int mx[MAXN+5],mxtp=0,mn[MAXN+5],mntp=0;
int main(){
	scanf("%d",&n);for(int i=1;i<=n;i++) scanf("%d",&a[i]);scanf("%d",&qu);
	for(int i=1;i<=qu;i++) scanf("%d%d",&q[i].l,&q[i].r),qv[q[i].r].pb(i);
	build(1,1,n);
	for(int i=1;i<=n;i++){
		while(mntp&&a[mn[mntp]]>a[i]) modify(1,mn[mntp-1]+1,mn[mntp],a[mn[mntp]]-a[i]),mntp--;mn[++mntp]=i;
		while(mxtp&&a[mx[mxtp]]<a[i]) modify(1,mx[mxtp-1]+1,mx[mxtp],a[i]-a[mx[mxtp]]),mxtp--;mx[++mxtp]=i;
		modify(1,1,i-1,-1);addcnt(1,1,i,1);ffe(it,qv[i]) ans[*it]=query(1,q[*it].l,q[*it].r);
//		for(int j=1;j<=i;j++) printf("%d %d %d\n",j,i,querynum(1,j,i));
	}
	for(int i=1;i<=qu;i++) printf("%lld\n",ans[i]);
	return 0;
}