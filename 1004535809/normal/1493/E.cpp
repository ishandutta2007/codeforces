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
const int MAXN=1e6;
int n;
char s[MAXN+5],t[MAXN+5];
int main(){
	scanf("%d%s%s",&n,s+1,t+1);
	if(strlen(t+1)==1&&t[1]=='0') return puts("0"),0;
	if(s[1]=='0'){
		for(int i=1;i<=n;i++) putchar('1');
		printf("\n");
	} else {
		bool flg=1;
		for(int i=1;i<=n;i++) flg&=(s[i]==t[i]);
		if(flg) printf("%s\n",t+1);
		else{
			s[n]++;int cur=n;
			while(s[cur]>'1') s[cur]='0',s[cur-1]++,cur--;
			bool flg=1;
			for(int i=1;i<=n;i++) flg&=(s[i]==t[i]);
			if(flg) printf("%s\n",t+1);
			else{
				if(t[n]=='0') t[n]='1';
				printf("%s\n",t+1);
			}
		}
	}
	return 0;
}
/*
10
1000000000
1101000000
*/