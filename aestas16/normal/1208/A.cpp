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
	int t=R();
	while(t--) {
		int a=R(),b=R(),n=R();
		if(n%3==0)printf("%d\n",a);
		else if(n%3==1)printf("%d\n",b);
		else printf("%d\n",a^b);
	}
	return 0;
}