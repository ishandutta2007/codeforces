#include <cstdio>
#include <algorithm>
 
#define reg register
#define Fread fread(B,1,1<<20,stdin)
 
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
 
int f[110],x[110];
 
int main() {
	reg int n=R(),ans=0;
	for(reg int i=1;i<=n;i++) {
		fr(x[i]);
		if(x[i]==1)return fw(1),fwrite(D,1,A-D,stdout),0;
	}
	std::sort(x+1,x+1+n);
	for(reg int i=1;i<=n;i++) {
		reg int fl=0;
		for(reg int j=2;j<=x[i];j++)
			if(x[i]%j==0&&f[j]) {fl=1;break;}
		if(!fl)f[x[i]]=1,ans++;
	}
	return fw(ans),fwrite(D,1,A-D,stdout),0;
}