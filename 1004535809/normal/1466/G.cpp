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
const int MAXM=100;
const int MAXL=1e6;
const int BS=191;
const int MOD=1e9+7;
const int INV2=5e8+4;
const int HMOD=1004535809;
int n,qu,occ[MAXN+5][28],pw[MAXN+5],ipw[MAXN+5],pw_hs[MAXL+5];
char s[MAXM+5],t[MAXN+5];string str[22];
int getocc(string s,string t){
	static int hss[MAXL*2+5];int hst=0,res=0;
	for(int i=1;i<=s.size();i++) hss[i]=(1ll*hss[i-1]*BS+s[i-1])%HMOD;
	for(int i=0;i<t.size();i++) hst=(1ll*BS*hst+t[i])%HMOD;
	for(int i=0;i+t.size()<=s.size();i++)
		if((hss[i+t.size()]-1ll*pw_hs[t.size()]*hss[i]%HMOD+HMOD)%HMOD==hst)
			res++;
	return res;
}
int main(){
	scanf("%d%d%s%s",&n,&qu,s+1,t+1);
	for(int i=(pw[0]=ipw[0]=1);i<=MAXN;i++){
		ipw[i]=1ll*ipw[i-1]*INV2%MOD;
		pw[i]=(pw[i-1]<<1)%MOD;
	}
	for(int i=(pw_hs[0]=1);i<=MAXL;i++) pw_hs[i]=1ll*pw_hs[i-1]*BS%HMOD;
	for(int i=1;i<=n;i++){
		for(int j=0;j<26;j++) occ[i][j]=occ[i-1][j];
		occ[i][t[i]-'a']=(occ[i][t[i]-'a']+ipw[i])%MOD;
	}
	int len=strlen(s+1),cur=0;for(int i=1;i<=len;i++) str[0].pb(s[i]);
	while(str[cur].size()<=MAXL&&cur<n){
		cur++;
		for(int i=0;i<str[cur-1].size();i++) str[cur].pb(str[cur-1][i]);
		str[cur].pb(t[cur]);
		for(int i=0;i<str[cur-1].size();i++) str[cur].pb(str[cur-1][i]);
	}
	while(qu--){
		int k;string p;static char buf[MAXL+5];
		scanf("%d%s",&k,buf+1);int L=strlen(buf+1);
		for(int i=1;i<=L;i++) p.pb(buf[i]);
		int mx=0;while(str[mx].size()<=L) mx++;
		if(k<=mx){printf("%d\n",getocc(str[k],p));continue;}
		int res=1ll*getocc(str[mx],p)*pw[k-mx]%MOD;
		for(int i=0;i<26;i++){
			string nw_s;
			for(int j=str[mx].size()-L+1;j<str[mx].size();j++) nw_s.pb(str[mx][j]);
			nw_s.pb(i+'a');
			for(int j=0;j<L-1;j++) nw_s.pb(str[mx][j]);
			int msk=occ[k][i],cnt=getocc(nw_s,p);
//			printf("%d %d\n",msk,cnt);
//			cout<<nw_s<<" "<<p<<endl;
			for(int j=1;j<=mx;j++) if(t[j]-'a'==i) msk=(msk-ipw[j]+MOD)%MOD;
			res=(res+1ll*msk*pw[k]%MOD*cnt)%MOD;
		} printf("%d\n",res);
	}
	return 0;
}