#include <cstdio>
#include <algorithm>

template<class T>void fr(T &a) {
    T s=0,w=1;char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-')w=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
    a=w*s;
}
template<class T>T fr() {T a;fr(a);return a;}
#define R() fr<int>()

struct Node {
	int a,id;
}f[1010];

bool cmp(Node a,Node b) {return a.a>b.a;}

int main() {
    int n=R(),x=0;long long ans=0;
    for(int i=1;i<=n;i++) fr(f[i].a),f[i].id=i;
    std::sort(f+1,f+1+n,cmp);
	for(int i=1;i<=n;i++) {
		ans+=f[i].a*x+1;
		x++;
	}
    printf("%lld\n",ans);
    for(int i=1;i<=n;i++) printf("%d ",f[i].id);
    return 0;
}