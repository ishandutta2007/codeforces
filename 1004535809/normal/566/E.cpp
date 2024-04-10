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
const int MAXN=1000;
int n;
bitset<MAXN+5> a[MAXN+5],b[MAXN+5],is;
int main(){
	scanf("%d",&n);bool flg=1;
	for(int i=1;i<=n;i++){
		int len;scanf("%d",&len);flg&=(len==n);
		while(len--){int x;scanf("%d",&x);a[i][x]=1;}
	} if(flg){
		for(int i=1;i<n;i++) printf("%d %d\n",i,n);
		return 0;
	} vector<pii> res;
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++){
		bitset<MAXN+5> tmp=a[i]&a[j];
		if(tmp.count()==2){
			int x=tmp._Find_first(),y=tmp._Find_next(x);
			if(b[x][y]) continue;
			b[x].set(y);b[y].set(x);is[x]=is[y]=1;
			b[x][x]=b[y][y]=1;res.pb(mp(x,y));
		}
	} if(is.count()==2){
		int r1=0,r2=0;
		static int vis[MAXN+5];
		for(int i=1;i<=n;i++) if(is[i]) (r1)?(r2=i):(r1=i);
		for(int i=1;i<=n;i++) if(a[i].count()<n){
			for(int j=1;j<=n;j++) if(!is[j]&&a[i][j]) vis[j]=1;
			break;
		}
		for(int i=1;i<=n;i++) if(!is[i]){
			if(vis[i]) res.pb(mp(r1,i));
			else res.pb(mp(r2,i));
		} for(pii e:res) printf("%d %d\n",e.fi,e.se);
	} else {
		static bool vis[MAXN+5];
		for(int i=1;i<=n;i++){
			bool flg=1;
			for(int j=1;j<=n;j++) if((a[i]&a[j])==a[j]&&a[i]!=a[j])
				flg=0;
			if(!flg) continue;
			bitset<MAXN+5> tmp=a[i]&is;
			for(int j=1;j<=n;j++) if(tmp[j]&&b[j]==tmp){
				if(!vis[j]){
					for(int k=1;k<=n;k++) if(!is[k]&&a[i][k]) res.pb(mp(j,k));
					vis[j]=1;
				}
				break;
			}
		} for(pii e:res) printf("%d %d\n",e.fi,e.se);
	}
	return 0;
}
/*
5
5 1 2 3 4 5
4 1 3 4 5
4 3 4 5 2
3 2 5 4
3 1 4 3
*/