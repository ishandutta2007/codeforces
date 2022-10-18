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
const int MAXN=500;
const int INF=0x3f3f3f3f;
int n,k;char s[MAXN+5],res[MAXN+5];
int dp[MAXN+5][2];
string decode(int x){
	string res;
	res.pb(x>>21&127);res.pb(x>>14&127);
	res.pb(x>>7&127);res.pb(x&127);
	return res;
}
int encode(char c1,char c2,char c3,char c4){
	return c1<<21|c2<<14|c3<<7|c4;
}
int getpre(char c,int k){return (c-'a'+k-1)%k+'a';}
int getnxt(char c,int k){return (c-'a'+1)%k+'a';}
void print(int x){
	if(x==INF) return printf("INF"),void();
	if(x>>21&127) putchar(x>>21&127);
	if(x>>14&127) putchar(x>>14&127);
	if(x>>7&127) putchar(x>>7&127);
	if(x&127) putchar(x&127);
}
void solve(){
	scanf("%d%d%s",&n,&k,s+1);res[n+1]=0;
	memset(dp,63,sizeof(dp));dp[0][0]=s[1];
	for(int i=1;i<=n;i++){
		if(i>=4) res[i-3]=0x7f;
		if(dp[i-1][1]<INF){
			if(i>=4) chkmin(res[i-3],dp[i-1][1]>>21);
		} if(dp[i-1][0]<INF){
			if(i>=4) chkmin(res[i-3],dp[i-1][0]>>21);
		} if(dp[i-1][1]<INF){
			if(i<=3||res[i-3]==(dp[i-1][1]>>21)){
				string ss=decode(dp[i-1][1]);
				chkmin(dp[i][0],encode(ss[1],ss[2],ss[3],s[i+1]));
				if(ss[1]) chkmin(dp[i][0],encode(ss[2],ss[1],ss[3],s[i+1]));
				chkmin(dp[i][0],encode(ss[1],getpre(ss[2],k),ss[3],s[i+1]));
				chkmin(dp[i][0],encode(ss[1],getnxt(ss[2],k),ss[3],s[i+1]));
			}
		} if(dp[i-1][0]<INF){
			if(i<=3||res[i-3]==(dp[i-1][0]>>21)){
				string ss=decode(dp[i-1][0]);
				chkmin(dp[i][0],encode(ss[1],ss[2],ss[3],s[i+1]));
				if(i>1) chkmin(dp[i][0],encode(ss[1],ss[3],ss[2],s[i+1]));
				if(i<n) chkmin(dp[i][1],encode(ss[1],ss[2],s[i+1],ss[3]));
				chkmin(dp[i][0],encode(ss[1],ss[2],getpre(ss[3],k),s[i+1]));
				chkmin(dp[i][0],encode(ss[1],ss[2],getnxt(ss[3],k),s[i+1]));
			}
		} //printf("%d: ",i);
//		print(dp[i][0]);putchar(' ');print(dp[i][1]);printf("\n");
	} string ss=decode(dp[n][0]);
	res[n-2]=ss[0];res[n-1]=ss[1];res[n]=ss[2];
	printf("%s\n",res+1);
}
int main(){
	int qu;scanf("%d",&qu);
	while(qu--) solve();
	return 0;
}