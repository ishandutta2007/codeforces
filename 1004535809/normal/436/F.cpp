//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("fast-math")
//#pragma GCC optimize("profile-values,profile-reorder-functions,tracer")
//#pragma GCC optimize("move-loop-invariants")
//#pragma GCC optimize("unswitch-loops")
//#pragma GCC optimize("branch-target-load-optimize")
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
const int MAXN=1e5;
const int BLK=320;
int n,w,a[MAXN+5],b[MAXN+5],tot,mxa=0,mxb=0;
int L[BLK+5],R[BLK+5];
vector<int> pos[MAXN+5];
int blk_sz,blk_cnt,bel[MAXN+5];
struct line{
	ll k,b;
	line(ll _k=0,ll _b=0):k(_k),b(_b){}
	ll get(ll x){return x*k+b;}
};
double inter(line x,line y){return 1.0*(y.b-x.b)/(x.k-y.k);}
struct hull{
	ll tag;vector<line> lns;
	line stk[BLK+5];int tp=0;double itr[BLK+5];
	void build(){
		tp=0;
		for(int i=0;i<lns.size();i++){
			while(tp>1&&itr[tp-1]>inter(stk[tp],lns[i])) --tp;
			stk[++tp]=lns[i];
			if(tp>=2) itr[tp-1]=inter(stk[tp-1],stk[tp]);
		}
	}
	void modify(int l,int r,int v){
		for(int i=0;i<lns.size();i++) if(l<=lns[i].k&&lns[i].k<=r)
			lns[i].b+=1ll*v*lns[i].k;
//		printf("rebuild:\n");
//		for(int i=0;i<lns.size();i++) printf("%d %d\n",lns[i].k,lns[i].b);
		build();
	}
	pair<ll,int> calc(){
		int l=1,r=tp-1,p=tp;
//		printf("tag=%lld\n",tag);
		while(l<=r){
			int mid=l+r>>1;
			if(tag<itr[mid]) p=mid,r=mid-1;
			else l=mid+1;
		} return mp(stk[p].get(tag),stk[p].k);
	}
} h[BLK+5];
void add_range(int l,int r,int v){
	if(bel[l]==bel[r]){
		h[bel[l]].modify(l,r,v);
	} else {
		for(int i=bel[l]+1;i<bel[r];i++) h[i].tag+=v;
		h[bel[l]].modify(l,R[bel[r]],v);
		h[bel[r]].modify(L[bel[r]],r,v);
	}
}
pair<ll,int> query(){
	pair<ll,int> res=mp(0,0);
	for(int i=1;i<=blk_cnt;i++) chkmax(res,h[i].calc());
	return res;
}
int main(){
	scanf("%d%d",&n,&w);tot=n;
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a[i],&b[i]);pos[b[i]].pb(i);
		chkmax(mxa,a[i]);chkmax(mxb,b[i]);
	} blk_sz=(int)(sqrt(mxa+1));blk_cnt=mxa/blk_sz+1;
//	printf("%d\n",blk_sz);
	for(int i=1;i<=blk_cnt;i++){
		L[i]=(i-1)*blk_sz+1;R[i]=min(i*blk_sz,mxa+1);
		L[i]--;R[i]--;
//		printf("%d %d\n",L[i],R[i]);
		for(int j=L[i];j<=R[i];j++) bel[j]=i;
		for(int j=L[i];j<=R[i];j++) h[i].lns.pb(line(j,0));
		h[i].build();
	} //puts("-1");
	for(int i=0;i<=mxb+1;i++){
		pair<ll,int> res=query();
		printf("%lld %d\n",res.fi+1ll*tot*w*i,res.se);
		for(int x:pos[i]) add_range(0,a[x],1),tot--;
	}
	return 0;
}