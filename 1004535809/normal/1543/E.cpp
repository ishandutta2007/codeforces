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
const int MAXN=65536;
const int MAXM=1048576;
int n,hd[MAXN+5],to[MAXM+5],nxt[MAXM+5],ec=0;
void adde(int u,int v){to[++ec]=v;nxt[ec]=hd[u];hd[u]=ec;}
int id[MAXN+5],vis[MAXN+5],iv[MAXN+5];
void solve(){
	scanf("%d",&n);
	for(int i=0;i<(1<<n);i++) hd[i]=0,vis[i]=0,id[i]=0;ec=0;
	for(int i=1,u,v;i<=(n<<(n-1));i++) scanf("%d%d",&u,&v),adde(u,v),adde(v,u);
	id[0]=0;int cur=0;vis[0]=1;queue<int> q;
	for(int e=hd[0];e;e=nxt[e]){int y=to[e];id[y]=1<<cur;cur++;q.push(y);}
	while(!q.empty()){
		int x=q.front();q.pop();
		if(vis[x]) continue;vis[x]=1;
		for(int e=hd[x];e;e=nxt[e]){
			int y=to[e];if(vis[y]) continue;
			id[y]|=id[x];q.push(y);
		}
	}
	for(int i=0;i<(1<<n);i++) iv[id[i]]=i;
	for(int i=0;i<(1<<n);i++) printf("%d ",iv[i]);printf("\n");
	bool flg=0;
	for(int i=0;i<=4;i++) if((1<<i)==n) flg=1;
	if(!flg) puts("-1");
	else{
		vector<int> res(2,0);
		for(int i=2;i<=n;i<<=1){
			vector<int> nres(1<<i,0);
			for(int j=0;j<(1<<i);j++){
				if(__builtin_parity(j>>(i>>1)))
					nres[j]=(res[j&((1<<(i>>1))-1)]+res[j>>(i>>1)])%(i>>1)+(i>>1);
				else nres[j]=(res[j&((1<<(i>>1))-1)]+res[j>>(i>>1)])%(i>>1);
			} swap(nres,res);
//			for(int j=0;j<(1<<(i));j++) printf("%d ",res[j]);printf("\n");
		}
		for(int i=0;i<(1<<n);i++) printf("%d ",res[id[i]]);
		printf("\n");
	}
}
int main(){
	int qu;scanf("%d",&qu);
	while(qu--) solve();
	return 0;
}