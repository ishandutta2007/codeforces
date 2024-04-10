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
const int MAXN=2.5e5;
int n,m,mxd=0;
vector<int> a[MAXN+5];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		a[i].resize(m+1);
		for(int j=1;j<=m;j++) scanf("%d",&a[i][j]);
	}
	for(int i=1;i<=n;i++){
		int sum=0;
		for(int j=1;j<=m;j++) sum+=(a[1][j]!=a[i][j]);
		chkmax(mxd,sum);
	}
	if(mxd>=5) return puts("No"),0;
	else if(mxd<=2){
		puts("Yes");
		for(int j=1;j<=m;j++) printf("%d%c",a[1][j]," \n"[j==m]);
		return 0;
	} else if(mxd==4){
		int pos=0;
		for(int i=1;i<=n;i++){
			int sum=0;
			for(int j=1;j<=m;j++) sum+=(a[1][j]!=a[i][j]);
			if(sum==4) pos=i;
		}
		vector<int> dif;
		for(int j=1;j<=m;j++) if(a[1][j]!=a[pos][j]) dif.pb(j);
		for(int i=0;i<4;i++) for(int j=i+1;j<4;j++){
			static int res[MAXN+5];
			for(int k=1;k<=m;k++) res[k]=a[1][k];
			res[dif[i]]=a[pos][dif[i]];res[dif[j]]=a[pos][dif[j]];
			bool flg=1;
			for(int k=1;k<=n;k++){
				int sum=0;
				for(int l=1;l<=m;l++) sum+=(res[l]!=a[k][l]);
				flg&=(sum<=2);
			} if(flg){
				puts("Yes");
				for(int k=1;k<=m;k++) printf("%d%c",res[k]," \n"[k==m]);
				return 0;
			}
		} puts("No");
	} else {
		int pos=0;
		for(int i=1;i<=n;i++){
			int sum=0;
			for(int j=1;j<=m;j++) sum+=(a[1][j]!=a[i][j]);
			if(sum==3) pos=i;
		}
		vector<int> dif;
		for(int j=1;j<=m;j++) if(a[1][j]!=a[pos][j]) dif.pb(j);
		for(int i=0;i<3;i++) for(int j=0;j<3;j++) if(i^j){
			static int res[MAXN+5];
			for(int k=1;k<=m;k++) res[k]=a[1][k];
			res[dif[j]]=a[pos][dif[j]];
			int pos=-1;
			for(int k=1;k<=n;k++){
				int sum=0;
				for(int l=1;l<=m;l++) sum+=(res[l]!=a[k][l]);
				if(sum==3) pos=k;
			} if(!~pos) {
				puts("Yes");
				for(int k=1;k<=m;k++) printf("%d%c",res[k]," \n"[k==m]);
				return 0;
			} else {
				int p=3-i-j;
				res[dif[p]]=a[pos][dif[p]];
				bool flg=1;
				for(int k=1;k<=n;k++){
					int sum=0;
					for(int l=1;l<=m;l++) sum+=(res[l]!=a[k][l]);
					flg&=(sum<=2);
				} if(flg){
					puts("Yes");
					for(int k=1;k<=m;k++) printf("%d%c",res[k]," \n"[k==m]);
					return 0;
				}
			}
		} puts("No");
	}
	return 0;
}
/*
3 3
1 2 3
1 3 4
2 3 5
*/