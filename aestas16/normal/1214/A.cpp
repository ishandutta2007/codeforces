#include <cstdio>
 
#define min(a,b) ((a)<(b)?(a):(b))
 
template<class T>void fr(T &a) {
	T s=0,w=1;a=0;char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-')w=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
    a=w*s;
}
template<class T>T in() {T a;fr(a);return a;}
#define R() in<int>()
 
int main() {
	int n=R(),d=R(),e=R(),ans=0x3f3f3f3f;
	for(int i=0;d*i<=n;i++) ans=min(ans,(n-d*i)%(5*e));
	return !printf("%d\n",ans);
}