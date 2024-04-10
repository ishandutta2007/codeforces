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
const int MAXN=1e5;
int n,siz[MAXN+5],mxdep[MAXN+5];vector<int> g[MAXN+5];
void dfs0(int x){
	siz[x]=1;mxdep[x]=0;
	for(int y:g[x]) dfs0(y),siz[x]+=siz[y],chkmax(mxdep[x],mxdep[y]+1);
}
int seq[MAXN+5],slen=0;vector<int> res;
void dfs1(int x){seq[++slen]=x;for(int y:g[x]) dfs1(y);}
void dfs2(int x,int l,int r){
	++l;
	for(int y:g[x]){
		dfs2(y,l,l+siz[y]-1);
		if(l+siz[y]<=r){
//			printf("%d %d\n",y,l);
			for(int i=1;i<=mxdep[y]+1;i++)
				res.pb(seq[l+siz[y]]);
		} l+=siz[y];
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1,f;i<n;i++) scanf("%d",&f),g[f].pb(i);dfs0(0);
	for(int i=0;i<n;i++) sort(g[i].begin(),g[i].end(),[&](int x,int y){return mxdep[x]<mxdep[y];});
	dfs1(0);for(int i=1;i<=n;i++) printf("%d%c",seq[i]," \n"[i==n]);
	dfs2(0,1,n);printf("%d\n",res.size());
	for(int x:res) printf("%d ",x);
	return 0;
}
/*
7
0 0 1 1 2 2
*/