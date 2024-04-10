#include <cstdio>
 
#define reg register
#define Fread fread(B,1,1<<20,stdin)
#define max(a,b) ((a)>(b)?(a):(b))
 
char B[1<<20],*S=B,*T=B,D[1<<25],*A=D-1;
inline char getc() {
	return (S==T&&(T=(S=B)+Fread,S==T)?0:*S++);
}
#define getc getchar
template<class T>inline void fr(reg T &a) {
	reg T s=0,w=1;reg char ch=getc();
	while(ch<'0'||ch>'9') {if(ch=='-')w=-1;ch=getc();}
	while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getc();
	a=w*s;
}
template<class T>inline T fr() {T a;fr(a);return a;}
#define R() fr<int>()
inline void fw(reg int x) {
	static char C[20];static int T;
	while(C[++T]=48+x%10,x/=10);
	while(*++A=C[T],--T);
	*++A='\n';
}
 
char str[110];
int a[110],b[110],f[110][10010];
 
int gcd(int a,int b) {return a%b?gcd(b,a%b):b;}
int lcm(int a,int b) {return a/gcd(a,b)*b;}
 
int main() {
	int n=R(),l=10000,ans=0;scanf("%s",str);
	for(int i=1;i<=n;i++) {
		fr(a[i]),fr(b[i]);
		// l=lcm(lcm(a[i],b[i]),l);
	}
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=l;j++) {
			int x=(j-b[i])/a[i];
			if(a[i]*x!=j-b[i])x++;
			if(x%2)f[i][j]=!(str[i-1]-'0');
			else f[i][j]=str[i-1]-'0';
			if(j<=b[i])f[i][j]=str[i-1]-'0';
		}
	}
	for(int i=1;i<=l;i++) {
		int x=0;
		for(int j=1;j<=n;j++)
			if(f[j][i])x++;
		ans=max(x,ans);
	}
	return fw(ans),fwrite(D,1,A-D,stdout),0;
}