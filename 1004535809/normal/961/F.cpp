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
const int MAXN=1e6;
const int MOD=1004535809;
const int BS=193;
int n;char s[MAXN+5];
int pw[MAXN+5],hsh[MAXN+5];
vector<int> add[MAXN+5],del[MAXN+5];
int gethsh(int l,int r){return (hsh[r]-1ll*hsh[l-1]*pw[r-l+1]%MOD+MOD)%MOD;}
int main(){
	scanf("%d%s",&n,s+1);
	for(int i=(pw[0]=1);i<=MAXN;i++) pw[i]=1ll*pw[i-1]*BS%MOD;
	for(int i=1;i<=n;i++) hsh[i]=(1ll*hsh[i-1]*BS+s[i])%MOD;
	for(int i=1;i<=n>>1;i++) if(s[i]==s[n+1-i]){
		int l=1,r=i,L=0,R=0;
		while(l<=r){
			int mid=l+r>>1;
			if(gethsh(i-mid+1,i)==gethsh(n+1-i-mid+1,n+1-i)) L=mid,l=mid+1;
			else r=mid-1;
		} l=1,r=i;
		while(l<=r){
			int mid=l+r>>1;
			if(gethsh(i,i+mid-1)==gethsh(n+1-i,n-i+mid)) R=mid,l=mid+1;
			else r=mid-1;
		} int mn=min(L,R);
		add[i-mn+1].pb(i);del[i+1].pb(i);
	} multiset<int> st;
	for(int i=1;i<=(n+1>>1);i++){
		for(int x:add[i]) st.insert(x);
		for(int x:del[i]) st.erase(st.find(x));
		if(st.empty()) printf("-1 ");
		else printf("%d ",((*st.rbegin())-i+1)*2-1);
	}
	return 0;
}