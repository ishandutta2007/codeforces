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
#define mt make_tuple
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
template<typename T1,typename T2> void chkmin(T1 &x,T2 y){if(x>y) x=y;}
template<typename T1,typename T2> void chkmax(T1 &x,T2 y){if(x<y) x=y;}
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef long double ld;
const int MOD=51123987;
const int INF=0x3f3f3f3f;
const ll INFll=0x3f3f3f3f3f3f3f3fll;
const double EPS=1e-6;
namespace fastio{
	#define FILE_SIZE 1<<23
	char rbuf[FILE_SIZE],*p1=rbuf,*p2=rbuf,wbuf[FILE_SIZE],*p3=wbuf;
	inline char getc(){return p1==p2&&(p2=(p1=rbuf)+fread(rbuf,1,FILE_SIZE,stdin),p1==p2)?-1:*p1++;}
	inline void putc(char x){(*p3++=x);}
	template<typename T> void read(T &x){
		x=0;char c=getchar();T neg=0;
		while(!isdigit(c)) neg|=(c=='-'),c=getchar();
		while(isdigit(c)) x=(x<<3)+(x<<1)+(c^48),c=getchar();
		if(neg) x=-x;
	}
	template<typename T> void recursive_print(T x){
		if(!x) return;
		recursive_print(x/10);putc(x%10+'0');
	}
	template<typename T> void print(T x){
		if(!x) putc('0');if(x<0) putc('-'),x=-x;
		recursive_print(x);
	}
	template<typename T> void print(T x,char c){print(x);putc(c);}
	void print_final(){fwrite(wbuf,1,p3-wbuf,stdout);}
}
template<typename Tv,int limN,int limM> struct link_list{
	int hd[limN+5],nxt[limM+5],item_n=0;Tv val[limM+5];
	void clear(){memset(hd,0,sizeof(hd));item_n=0;}//be aware of the TC of memset
	void ins(int x,Tv y){val[++item_n]=y;nxt[item_n]=hd[x];hd[x]=item_n;}
};
const int MAXN=2e6;
int n,res=0,tmp[MAXN+5];char s[MAXN+5],t[MAXN+5];
struct PAM{
	link_list<pii,MAXN,MAXN> ch;
	int len[MAXN+5],fail[MAXN+5],ncnt,cur,ed[MAXN+5],num[MAXN+5],tot=0;
	void init(){fail[0]=1;fail[1]=0;len[0]=0;len[1]=-1;ncnt=1;cur=0;}
	void clear(){init();ch.clear();fill0(len);fill0(fail);fill0(ed);fill0(num);tot=0;init();}
	PAM(){clear();}
	int getchd(int p,int c){
		for(int e=ch.hd[p];e;e=ch.nxt[e]){
			if(ch.val[e].fi==c) return ch.val[e].se;
		} return -1;
	}
	void insert(int ps,char *s){
		while(s[ps-len[cur]-1]!=s[ps]) cur=fail[cur];
		if(!~getchd(cur,s[ps]-'a')){
			int fa=fail[cur];
			while(s[ps-len[fa]-1]!=s[ps]) fa=fail[fa];
			fail[++ncnt]=max(getchd(fa,s[ps]-'a'),0);
			ch.ins(cur,mp(s[ps]-'a',ncnt));
			len[ncnt]=len[cur]+2;num[ncnt]=num[fail[ncnt]]+1;
		} cur=getchd(cur,s[ps]-'a');//printf("%d\n",cur);
		ed[ps]=cur;tot=(tot+num[cur])%MOD;
	}
} p;
int main(){
	scanf("%d%s",&n,s+1);
	for(int i=1;i<=n;i++) t[i]=s[i];reverse(t+1,t+n+1);
	for(int i=1;i<=n;i++) p.insert(i,s);
	int res=1ll*p.tot*(p.tot-1)/2%MOD;
	for(int i=1;i<=n;i++) tmp[i]=p.num[p.ed[n-i]];
	p.clear();
	for(int i=1;i<=n;i++) p.insert(i,t),res=(res-1ll*tmp[i]*p.tot%MOD+MOD)%MOD;
	printf("%d\n",res);
	return 0;
}