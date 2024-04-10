#include <cstdio>
 
template<class T>void fr(T &a) {
	T s=0,w=1;a=0;char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
	a=w*s;
}
template<class T>T in() {T a;fr(a);return a;}
#define R() in<int>()
 
int main() {
	int b=R(),g=R(),n=R(),ans=0;
	for(int i=0;i<=n;i++) {
		int j=n-i;
		if(i<=b&&j<=g)ans++;
	}
	return !printf("%d\n",ans);
}