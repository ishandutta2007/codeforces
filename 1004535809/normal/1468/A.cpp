#include <bits/stdc++.h>
using namespace std;
#define fz(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define ffe(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define fi first
#define se second
#define fill0(a) memset(a,0,sizeof(a))
#define fill1(a) memset(a,-1,sizeof(a))
#define fillbig(a) memset(a,63,sizeof(a))
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
template<typename T1,typename T2> void chkmin(T1 &x,T2 y){if(x>y) x=y;}
template<typename T1,typename T2> void chkmax(T1 &x,T2 y){if(x<y) x=y;}
template<typename T>
void read(T &x){
	x=0;char c=getchar();T neg=1;
	while(!isdigit(c)){
		if(c=='-') neg=-1;
		c=getchar();
	}
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
	x*=neg;
}
const int MAXN=5e5;
const int LOG_N=20;
int n,a[MAXN+5],dp[MAXN+5];
struct node{
	int l,r,mx,ch[2];
	void clear(){l=r=mx=ch[0]=ch[1]=0;}
} s[2*MAXN*LOG_N+5];
int ncnt=0,rt[MAXN+5];
int build(int l,int r){
	int k=++ncnt;s[k].clear();s[k].l=l;s[k].r=r;
	if(l==r) return k;int mid=(s[k].l+s[k].r)>>1;
	s[k].ch[0]=build(l,mid);s[k].ch[1]=build(mid+1,r);
	return k;
}
int modify(int pre,int x,int v){
	int k=++ncnt;s[k].clear();s[k]=s[pre];
	if(s[k].l==s[k].r){s[k].mx=max(s[k].mx,v);return k;}
	int mid=(s[k].l+s[k].r)>>1;
	if(x<=mid) s[k].ch[0]=modify(s[pre].ch[0],x,v);
	else s[k].ch[1]=modify(s[pre].ch[1],x,v);
	s[k].mx=max(s[k].mx,v);return k;
}
int query(int k,int l,int r){
	if(l<=s[k].l&&s[k].r<=r) return s[k].mx;
	int mid=(s[k].l+s[k].r)>>1;
	if(r<=mid) return query(s[k].ch[0],l,r);
	else if(l>mid) return query(s[k].ch[1],l,r);
	else return max(query(s[k].ch[0],l,mid),query(s[k].ch[1],mid+1,r));
}
int stk[MAXN+5],tp=0;
void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);a[n+1]=n+1;
	for(int i=1;i<=n+1;i++) dp[i]=0;
	ncnt=0;rt[0]=build(1,n+1);tp=0;
	for(int i=1;i<=n+1;i++){
		dp[i]=query(rt[i-1],1,a[i])+1;
		while(tp&&a[stk[tp]]<=a[i]) tp--;
		if(tp) dp[i]=max(dp[i],query(rt[stk[tp]-1],1,a[i])+2);
		stk[++tp]=i;
		if(i!=n+1) rt[i]=modify(rt[i-1],a[i],dp[i]);
//		printf("%d %d\n",i,dp[i]);
	} printf("%d\n",dp[n+1]-1);
}
signed main(){
//	freopen("in.txt","r",stdin);
	int qu;scanf("%d",&qu);
	while(qu--) solve();
	return 0;
}