#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define fill0(a) memset(a,0,sizeof(a))
#define fill1(a) memset(a,-1,sizeof(a))
#define fillbig(a) memset(a,63,sizeof(a))
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define mt make_tuple
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
template<typename T1,typename T2> void chkmin(T1 &x,T2 y){if(x>y) x=y;}
template<typename T1,typename T2> void chkmax(T1 &x,T2 y){if(x<y) x=y;}
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef long double ld;
namespace fastio{
	#define FILE_SIZE 1<<23
	char rbuf[FILE_SIZE],*p1=rbuf,*p2=rbuf,wbuf[FILE_SIZE],*p3=wbuf;
	inline char getc(){return p1==p2&&(p2=(p1=rbuf)+fread(rbuf,1,FILE_SIZE,stdin),p1==p2)?-1:*p1++;}
	inline void putc(char x){(*p3++=x);}
	template<typename T> void read(T &x){
		x=0;char c=getchar();T neg=0;
		while(!isdigit(c)) neg|=!(c^'-'),c=getchar();
		while(isdigit(c)) x=(x<<3)+(x<<1)+(c^48),c=getchar();
		if(neg) x=(~x)+1;
	}
	template<typename T> void recursive_print(T x){return (!x)?void():(recursive_print(x/10),putc(x%10^48),void());}
	template<typename T> void print(T x){(!x)&&(putc('0'),0);(x<0)&&(putc('-'),x=~x+1);recursive_print(x);}
	template<typename T> void print(T x,char c){print(x);putc(c);}
	void print_final(){fwrite(wbuf,1,p3-wbuf,stdout);}
}
const int MAXN=1e6;
int n,m,a[MAXN+5],b[MAXN+5],isp[MAXN+5];
int key[MAXN*2+5],uni[MAXN*2+5],cnt=0,num=0;
pii c[MAXN+5];
struct node{int l,r,lz;pii mn;} s[MAXN*4+5];
void pushup(int k){s[k].mn=min(s[k<<1].mn,s[k<<1|1].mn);}
void build(int k,int l,int r){
	s[k].l=l;s[k].r=r;s[k].mn=mp(l,l);s[k].lz=0;if(l==r) return;
	int mid=l+r>>1;build(k<<1,l,mid);build(k<<1|1,mid+1,r);
}
void tag(int k,int v){s[k].lz+=v;s[k].mn.fi+=v;}
void pushdown(int k){if(s[k].lz) tag(k<<1,s[k].lz),tag(k<<1|1,s[k].lz),s[k].lz=0;}
void modify(int k,int l,int r,int v){
	if(l<=s[k].l&&s[k].r<=r) return tag(k,v),void();
	pushdown(k);int mid=s[k].l+s[k].r>>1;
	if(r<=mid) modify(k<<1,l,r,v);
	else if(l>mid) modify(k<<1|1,l,r,v);
	else modify(k<<1,l,mid,v),modify(k<<1|1,mid+1,r,v);
	pushup(k);
}
pii query(int k,int l,int r){
	if(l<=s[k].l&&s[k].r<=r) return s[k].mn;
	pushdown(k);int mid=s[k].l+s[k].r>>1;
	if(r<=mid) return query(k<<1,l,r);
	else if(l>mid) return query(k<<1|1,l,r);
	else return min(query(k<<1,l,mid),query(k<<1|1,mid+1,r));
}
struct fenwick_tree{
	int t[MAXN*2+5];
	fenwick_tree(){memset(t,0,sizeof(t));}
	void add(int x,int v){for(int i=x;i<=num;i+=(i&(-i))) t[i]+=v;}
	int query(int x){int ret=0;for(int i=x;i;i&=(i-1)) ret+=t[i];return ret;}
} t;
void solve(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),c[i]=mp(a[i],i);
	for(int i=1;i<=m;i++) scanf("%d",&b[i]);
	sort(b+1,b+m+1);sort(c+1,c+n+1);build(1,0,n);
	int cur=1,pre_pos=0,pre_val=-1;
	for(int l=1,r;l<=m;l=r){
		r=l;while(r<=m&&b[l]==b[r]) ++r;
		while(cur<=n&&c[cur].fi==pre_val) modify(1,c[cur].se,n,-1),cur++;
		while(cur<=n&&c[cur].fi<b[l]) modify(1,c[cur].se,n,-2),cur++;
		int tmp=cur;
		while(cur<=n&&c[cur].fi==b[l]) modify(1,c[cur].se,n,-1),cur++;
		pre_pos=query(1,pre_pos,n).se;
		for(int i=l;i<r;i++) isp[i]=pre_pos;
		pre_val=b[l];cur=tmp;
	}
	vector<int> d;
	for(int i=1;i<=m;i++){
		for(int j=isp[i-1]+1;j<=isp[i];j++) d.pb(a[j]);
		d.pb(b[i]);
	} for(int i=isp[m]+1;i<=n;i++) d.pb(a[i]);
//	for(int x:d) printf("%d ",x);printf("\n");
	cnt=num=0;ll res=0;
	for(int x:d) key[++cnt]=x;sort(key+1,key+cnt+1);
	for(int i=1;i<=cnt;i++) if(key[i]!=key[i-1]) uni[++num]=key[i];
	for(int i=1;i<=num;i++) t.t[i]=0;
	for(int x:d){
		int v=lower_bound(uni+1,uni+num+1,x)-uni;
		res+=t.query(num)-t.query(v);t.add(v,1);
	} printf("%lld\n",res);
}
int main(){
	int qu;scanf("%d",&qu);
	while(qu--) solve();
	return 0;
}
/*
1
4 4
1 2 4 3
1 3 5 6
*/