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
const int MAXN=1e5;
const int LOG_N=17;
int n;char s[MAXN+5];
ll d[MAXN+5],add[MAXN+5][28];
struct hsh{
	int BS,MOD;
	int hs[MAXN+5],pw[MAXN+5];
	void init(){
		for(int i=(pw[0]=1);i<=n;i++) pw[i]=1ll*pw[i-1]*BS%MOD;
		for(int i=1;i<=n;i++) hs[i]=(1ll*hs[i-1]*BS+s[i])%MOD;
	}
	int gethash(int l,int r){return (hs[r]-1ll*pw[r-l+1]*hs[l-1]%MOD+MOD)%MOD;}
} h1,h2;
bool check(int l1,int r1,int l2,int r2){
	return h1.gethash(l1,r1)==h1.gethash(l2,r2)&&
		   h2.gethash(l1,r1)==h2.gethash(l2,r2);
}
int occ[MAXN+5][28];
bool is[LOG_N+2][MAXN+5];
int getocc(int c,int l,int r){return occ[r][c]-occ[l-1][c];}
int getlcp(int x,int y){
	int l=1,r=n-max(x,y)+1,p=0;
	while(l<=r){
		int mid=l+r>>1;
		if(check(x,x+mid-1,y,y+mid-1)) p=mid,l=mid+1;
		else r=mid-1;
	} return p;
}
int getlcs(int x,int y){
	int l=1,r=min(x,y),p=0;
	while(l<=r){
		int mid=l+r>>1;
		if(check(x-mid+1,x,y-mid+1,y)) p=mid,l=mid+1;
		else r=mid-1;
	} return p;
}
int main(){
	scanf("%s",s+1);n=strlen(s+1);
	h1.BS=191;h1.MOD=998244853;h2.BS=193;h2.MOD=1004535809;
	h1.init();h2.init();
	for(int i=1;i<=n;i++){
		for(int j=0;j<26;j++) occ[i][j]=occ[i-1][j];
		occ[i][s[i]-'a']++;
	}
	for(int i=1;i<=n;i++) is[1][i]=1;ll sum=n;
	for(int i=2;i<=LOG_N;i++) for(int j=1;j+(1<<i)-2<=n;j++){
		is[i][j]=is[i-1][j]&is[i-1][j+(1<<i-1)];
		if(is[i][j]){
			is[i][j]&=check(j,j+(1<<i-1)-2,j+(1<<i-1),j+(1<<i)-2);
			is[i][j]&=(getocc(s[j+(1<<i-1)-1]-'a',j,j+(1<<i)-2)==1);
			if(is[i][j]){
				int len=(1<<i)-1;sum+=1ll*len*len;
				d[j]+=1ll*len*len;d[j+(1<<i)-1]-=1ll*len*len;
			}
		}
//		printf("%d %d %d\n",i,j,is[i][j]);
	}
	for(int i=1;i<=n;i++) d[i]+=d[i-1];
	ll dlt=0;
	for(int i=2;i<=LOG_N;i++) for(int j=1;j+(1<<i)-2<=n;j++){
		if(!is[i-1][j]&&!is[i-1][j+(1<<i-1)]) continue;
		int len=(1<<i)-1;ll bnf=1ll*len*len;
		if(is[i-1][j]&&is[i-1][j+(1<<i-1)]){
			if(check(j,j+(1<<i-1)-2,j+(1<<i-1),j+(1<<i)-2)){
				for(int c=0;c<26;c++) if(!getocc(c,j,j+(1<<i)-2)){
					add[j+(1<<i-1)-1][c]+=bnf;
				}
			}
		} if(is[i-1][j+(1<<i-1)]){
			int lcp=getlcp(j,j+(1<<i-1)),lcs=getlcs(j+(1<<i-1)-2,j+(1<<i)-2);
			if(lcp+lcs==(1<<i-1)-2){
				int ori=s[j+lcp]-'a',nd=s[j+(1<<i-1)+lcp]-'a';
				if(getocc(s[j+(1<<i-1)-1]-'a',j,j+(1<<i)-2)-(ori==s[j+(1<<i-1)-1]-'a')+(nd==s[j+(1<<i-1)-1]-'a')!=1);
				else add[j+lcp][nd]+=bnf;
			}
		} if(is[i-1][j]){
			int lcp=getlcp(j,j+(1<<i-1)),lcs=getlcs(j+(1<<i-1)-2,j+(1<<i)-2);
			if(lcp+lcs==(1<<i-1)-2){
				int ori=s[j+(1<<i-1)+lcp]-'a',nd=s[j+lcp]-'a';
				if(getocc(s[j+(1<<i-1)-1]-'a',j,j+(1<<i)-2)-(ori==s[j+(1<<i-1)-1]-'a')+(nd==s[j+(1<<i-1)-1]-'a')!=1);
				else add[j+(1<<i-1)+lcp][nd]+=bnf;
			}
		}
	}
//	printf("%lld\n",sum);
//	for(int i=1;i<=n;i++) printf("%lld%c",d[i]," \n"[i==n]);
	for(int i=1;i<=n;i++) for(int j=0;j<26;j++)
		if(s[i]-'a'!=j) chkmax(dlt,-d[i]+add[i][j]);
	printf("%lld\n",sum+dlt);
	return 0;
}