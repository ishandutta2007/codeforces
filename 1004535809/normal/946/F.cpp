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
const int MAXN=100;
const int MOD=1e9+7;
int n,x;char s[MAXN+5];
int ch[MAXN+5][2],fail[MAXN+5];
void build(){
	queue<int> q;q.push(1);
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int i=0;i<2;i++){
			if(ch[x][i]) fail[ch[x][i]]=ch[fail[x]][i],q.push(ch[x][i]);
			else ch[x][i]=ch[fail[x]][i];
		}
	}
}
int dp[MAXN+5][MAXN+5][MAXN+5],sum[MAXN+5][MAXN+5][MAXN+5];
int main(){
	scanf("%d%d%s",&n,&x,s+1);
	for(int i=1;i<=n;i++) ch[i-1][s[i]-'0']=i;
	build();
	for(int i=0;i<=n;i++){
		dp[0][i][i]++;dp[1][i][i]++;;
		dp[0][i][ch[i][0]]++;dp[1][i][ch[i][1]]++;
		sum[0][i][ch[i][0]]=(ch[i][0]==n);
		sum[1][i][ch[i][1]]=(ch[i][1]==n);
	}
	for(int i=2;i<=x;i++){
		for(int j=0;j<=n;j++) for(int k=0;k<=n;k++){
			for(int l=0;l<=n;l++){
				dp[i][j][k]=(dp[i][j][k]+1ll*dp[i-1][j][l]*dp[i-2][l][k])%MOD;
				sum[i][j][k]=(sum[i][j][k]+1ll*dp[i-1][j][l]*sum[i-2][l][k])%MOD;
				sum[i][j][k]=(sum[i][j][k]+1ll*sum[i-1][j][l]*dp[i-2][l][k])%MOD;
			}
		}
	} int res=0;
	for(int i=0;i<=n;i++) res=(res+sum[x][0][i])%MOD;
	printf("%d\n",res);
	return 0;
}