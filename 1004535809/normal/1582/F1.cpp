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
const int MAXV=5000;
const int INF=0x3f3f3f3f;
int n,a[MAXN+5],mn[MAXV+5],b[MAXV*2+5],m,mx[MAXV+5];
int mnp[8193];
int main(){
	scanf("%d",&n);memset(mn,63,sizeof(mn));
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),chkmin(mn[a[i]],i),chkmax(mx[a[i]],i);
	vector<pii> p;
	for(int i=1;i<=MAXV;i++){
		if(mx[i]) p.pb(mp(mx[i],i));
		if(mn[i]!=INF&&mn[i]!=mx[i]) p.pb(mp(mn[i],i));
	} sort(p.begin(),p.end());
	for(pii pp:p) b[++m]=pp.se;
	memset(mnp,63,sizeof(mnp));
	mnp[0]=0;
	for(int i=1;i<=m;i++){
		for(int j=0;j<8192;j++) if(mnp[j]<=b[i]-1){
			chkmin(mnp[j^b[i]],b[i]);
		}
	}
	vector<int> res;
	for(int j=0;j<8192;j++) if(mnp[j]<INF) res.pb(j);
	printf("%d\n",res.size());
	for(int x:res) printf("%d ",x);
	return 0;
}