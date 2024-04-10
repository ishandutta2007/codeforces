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
const int MAXN=50;
const int DLT=453;
const int INF=0x3f3f3f3f;
int n,d[MAXN+5],tmp[MAXN+5];char s[MAXN+5];
int dp[MAXN+5][DLT*2+5][2];//0 positive 1 negative
struct lnum{
	int dig[MAXN+5],mx;//mod 10^{mx}
	lnum(){memset(dig,0,sizeof(dig));mx=0;}
	lnum operator =(const lnum &rhs){
		mx=rhs.mx;memset(dig,0,sizeof(dig));
		for(int i=0;i<mx;i++) dig[i]=rhs.dig[i];
		return *this;
	}
	void shrink(){
		for(int i=0;i+1<mx;i++) if(dig[i]>=10)
			dig[i+1]+=dig[i]/10,dig[i]%=10;
		dig[mx-1]%=10;
	}
	lnum operator +(const lnum &rhs){
		lnum res;res.mx=mx;
		for(int i=0;i<mx;i++) res.dig[i]=dig[i]+rhs.dig[i];
		res.shrink();return res;
	}
	void flip(){//x:=-x
		for(int i=0;i<mx;i++) dig[i]=9-dig[i];
		dig[0]++;shrink();
	}
};
int calc(int pos,int cur,int coef){
	if(!~pos) return 0;
	if(~dp[pos][cur+DLT][coef]) return dp[pos][cur+DLT][coef];
	dp[pos][cur+DLT][coef]=INF;lnum tmp;tmp.mx=pos+1;
	for(int i=0;i<=pos;i++) tmp.dig[i]=d[i];
	lnum _ps,_ng;_ps.mx=pos+1;
	for(int i=0;i<=pos;i++) _ps.dig[i]=1;
	_ng=_ps;_ng.flip();
	if(coef) tmp.flip();
	if(cur>0) for(int i=1;i<=cur;i++) tmp=tmp+_ps;
	else for(int i=1;i<=-cur;i++) tmp=tmp+_ng;
	int sum=0;lnum val=tmp;
	for(int i=0;i<=9;i++){
		if(val.dig[pos]==0) chkmin(dp[pos][cur+DLT][coef],calc(pos-1,cur-i,coef)+sum);
		sum+=pos+1;val=val+_ng;
	} sum=0;val=tmp;val.flip();
	for(int i=1;i<=9;i++){
		val=val+_ps;sum+=pos+1;
		if(val.dig[pos]==0) chkmin(dp[pos][cur+DLT][coef],calc(pos-1,i-cur,coef^1)+sum);
	} return dp[pos][cur+DLT][coef];
}
int main(){
	scanf("%s",s+1);n=strlen(s+1);memset(dp,-1,sizeof(dp));
	for(int i=0;i<n;i++) d[i]=s[n-i]-'0';
	printf("%d\n",calc(n,0,0));
	return 0;
}