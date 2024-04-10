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
const int MAXN=1e5;
int n,p[MAXN+5];
int main(){
	int qu;scanf("%d",&qu);
	while(qu--){
		scanf("%d",&n);
		if(n==2){puts("1\n2 1\n1\n2 1");continue;}
		if(n==3){puts("5\n2 3 1\n2\n1 3\n3 2");continue;}
		int lim=(n-1>>1),cur=n-1;p[1]=cur;
		for(int i=1;i<=lim;i++) p[cur]=cur-1,cur--;
		p[++cur]=n;p[n]=2;cur=2;
		for(int i=1;i<=n-2-lim;i++) p[cur]=cur+1,cur++;
		p[--cur]=1;
		ll res=1ll*(n-1)*(n-1);int lft=n-2;
		for(int i=n-2;i;i--){
			if(lft) lft--,res+=1ll*i*i;
			if(lft) lft--,res+=1ll*i*i;
		} printf("%lld\n",res);
		for(int i=1;i<=n;i++) printf("%d%c",p[i]," \n"[i==n]);
		printf("%d\n",n-1);
		for(int i=1;i<=lim;i++) printf("%d %d\n",p[1],1),swap(p[1],p[p[1]]);
		for(int i=1;i<=n-2-lim;i++) printf("%d %d\n",p[n],n),swap(p[n],p[p[n]]);
		printf("%d %d\n",p[1],1);
	}
	return 0;
}