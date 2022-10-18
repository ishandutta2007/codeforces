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
const int LOG_N=20;
const int MAXP=1<<21;
int n,mn[MAXP+5];pii mx[MAXP+5];
pii merge(pii x,pii y){
	pii res;res.fi=max(x.fi,y.fi);
	if(x.fi>y.fi) res.se=max(y.fi,x.se);
	else res.se=max(x.fi,y.se);
	return res;
}
bool check(int x){
	for(int i=x;i;--i&=x) if(mn[i]<mx[x^i].se) return 1;
	if(mn[0]<mx[x].se) return 1;
	return 0;
}
int main(){
	scanf("%d",&n);memset(mn,63,sizeof(mn));
	for(int i=1,x;i<=n;i++){scanf("%d",&x);chkmin(mn[x],i);mx[x]=merge(mx[x],mp(i,0));}
	for(int i=0;i<=LOG_N;i++) for(int j=0;j<MAXP;j++) if(~j>>i&1){
		chkmin(mn[j],mn[j^(1<<i)]);
		mx[j]=merge(mx[j],mx[j^(1<<i)]);
	} int res=0;//printf("%d %d\n",mx[0].fi,mx[0].se);
	for(int i=LOG_N;~i;i--) if(check(res|(1<<i))) res|=(1<<i);
	printf("%d\n",res);
	return 0;
}