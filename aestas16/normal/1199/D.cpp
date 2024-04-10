#include <cstdio>

#define max(a,b) ((a)>(b)?(a):(b))

template<class T>void fr(T &a) {
	T s=0,w=1;a=0;char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-')w=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
    a=w*s;
}
template<class T>T in() {T a;fr(a);return a;}
#define R() in<int>()

int a[200010],lt[200010],orz[200010];

int main() {
	int n=R(),m;
	for(int i=1;i<=n;i++) fr(a[i]);
	fr(m);
	for(int i=1;i<=m;i++) {
		int opt=R(),p=R(),x;
		if(opt==1)fr(x),a[p]=x,lt[p]=i;
		else orz[i]=p;
	}
	for(int i=m-1;i>=0;i--) orz[i]=max(orz[i+1],orz[i]);
	for(int i=1;i<=n;i++) printf("%d ",max(a[i],orz[lt[i]]));
	return 0;
}